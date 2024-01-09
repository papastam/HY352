#include "pokemon.h"
#include "ability.h"
#include <assert.h>

#pragma once

class Game{
    private:
        Array<Pokemon> pokemons;
        Array<Ability> abilities;
        int round;
        Pokemon* attacker;
        Pokemon* defender;
        bool game_started;

    public:
        
        // ------------------- Constructors -------------------
        Game(){
            std::cout << "---------- Pokemon game for HY352 ----------" << std::endl;
            pokemons = Array<Pokemon>();
            abilities = Array<Ability>();
            attacker = nullptr;
            defender = nullptr;
            game_started = false;
            round = 0;
        }

        // Destructor
        ~Game(){
            std::cout << "----------- End of pokemon game ------------" << std::endl;
        }

        // Copy constructor
        Game(const Game& _game){
            pokemons = _game.pokemons;
            abilities = _game.abilities;
            attacker = _game.attacker;
            defender = _game.defender;
            game_started = _game.game_started;
            round = _game.round;
        }

        // Copy assignment
        Game& operator=(const Game& _game){
            pokemons = _game.pokemons;
            abilities = _game.abilities;
            attacker = _game.attacker;
            defender = _game.defender;
            game_started = _game.game_started;
            round = _game.round;
            return *this;
        }

        // Move constructor
        Game(Game&& _game){
            pokemons = std::move(_game.pokemons);
            abilities = std::move(_game.abilities);
            attacker = std::move(_game.attacker);
            defender = std::move(_game.defender);
            game_started = std::move(_game.game_started);
            round = std::move(_game.round);
        }

        // --------------------- Operators --------------------

        void operator+=(Pokemon* _pokemon){
            pokemons.add(_pokemon);
        }

        void operator+=(Array<Pokemon>* _pokemons){
            pokemons.add(_pokemons);
        }

        void operator+=(Ability* _ability){
            abilities.add(_ability);
        }

        void operator+=(Array<Ability>* _abilities){
            abilities.add(_abilities);
        }

        // -------------------- Get/Setters -------------------

        Array<Pokemon>* getPokemons()   {return &pokemons;}
        Array<Ability>* getAbilities()  {return &abilities;}

        Pokemon* getAttacker(){assert(game_started);attacker;}
        Pokemon* getDefender(){assert(game_started);return defender;}
        bool getGameStarted(){return game_started;}
        
        Pokemon* getPokemon(const char* name){
            for(int i = 0; i < pokemons.getCount(); i++){
                if(strcmp(pokemons[i]->getName(), name) == 0){
                    return pokemons[i];
                }
            }
            error("Pokemon not found");
            return nullptr;
        }

        // -------------------- DUEL -------------------

        void duel(){
            game_started = true;
            assert(!attacker || !defender);
            char selected_name[20];

            while(1){// EACH player chooses their pokemon
                std::cout << "Player 1 choose your pokemon:" << std::endl;
                std::cout << "-----------------------------------------" << std::endl;
                std::cout << getPokemons() << std::endl;
                std::cout << "-----------------------------------------" << std::endl;
                std::cout << "Pokemon name: ";
                std::cin >> selected_name;
                if((attacker = getPokemon(selected_name)) != nullptr)
                    break;
                else
                    std::cout << "Pokemon not found, please select a valid pokemon!" << std::endl;        
            }
            attacker->setPos(false);

            while(1){
                std::cout << "Player 2 choose your pokemon:" << std::endl;
                std::cout << "-----------------------------------------" << std::endl;
                std::cout << getPokemons() << std::endl;
                std::cout << "-----------------------------------------" << std::endl;
                std::cout << "Pokemon name: ";
                std::cin >> selected_name;
                if ((defender = getPokemon(selected_name)) != nullptr)
                    break;
                else
                    std::cout << "Pokemon not found, please select a valid pokemon!" << std::endl;
            }
            defender->setPos(false);
            
            while(1) {
                round++;

                //1. Player 1 chooses an ability to cast
                std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
                std::cout << "Round " << round << std::endl;
                std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
                
                // Check if attacker is in pokeball
                if(attacker->isInPokeball()){
                    std::cout << attacker->getName() << " is in pokeball and cannot attack" << std::endl;
                }else{
                    //2. Action is performed
                    std::cout << attacker->getName() << " select an ability:" << std::endl;
                    std::cout << "-----------------------------------------" << std::endl;
                    std::cout << attacker->getAbilities() << std::endl;
                    std::cout << "-----------------------------------------" << std::endl;
                    std::cout << "Ability name: ";
                    std::cin >> selected_name;
                    attacker->get_ability(selected_name)->do_action();
                }

                // Check for activated abilities

                //3. Check if defending pokemon is dead
                if(is_dead(defender))
                    end_game(attacker);
                
                //4. Attacker/defender pointers are switched
                switch_pointers();
                
                //5. Player 2 chooses an ability to cast
                std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
                std::cout << "Round " << round << std::endl;
                std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;

                // Check if attacker is in pokeball
                if(attacker->isInPokeball()){
                    std::cout << attacker->getName() << " is in pokeball and cannot attack" << std::endl;
                }else{
                    //6. Action is performed
                    std::cout << attacker->getName() << " select an ability:" << std::endl;
                    std::cout << "-----------------------------------------" << std::endl;
                    std::cout << attacker->getAbilities() << std::endl;
                    std::cout << "-----------------------------------------" << std::endl;
                    std::cout << "Ability name: ";
                    std::cin >> selected_name;
                    attacker->get_ability(selected_name)->do_action();
                }

                // Check for activated abilities

                //7. Check if defending pokemon is dead
                if(is_dead(defender))
                    end_game(attacker);
                
                //8. Attacker/Defender pointers are switched again
                switch_pointers();
            }
        }

        // -------------------- Functions for Duel -------------------

        void end_game(Pokemon* winner){
            std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
            std::cout << "Game ended in round " << round << std::endl;
            std::cout << "Winner is " << winner->getName() << std::endl;
            std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
            exit(0);
        }

        int is_dead(Pokemon* target){
            if(target->getHp() > 0)
                return 0; 
            return 1;
        }

        void switch_pointers(){
            Pokemon* tmp = attacker;
            attacker = defender;
            defender = tmp;
        }

        // int calculate_final_damage(int initial_dmg) {
        //     int final_dmg = initial_dmg; // if no modifiers are applied then deal the initial dmg
            
        //     if(attacker->getType() == Electric) {
        //         switch (defender->getType()) {
        //             case Fire:

        //                 break;
        //             case Electric:
                    
        //                 break;
        //             case Grass:
                    
        //                 break;
        //         }
        //     }
        //     else if(attacker->getType() == Fire){
        //         switch (defender->getType()) {
        //             case Fire:

        //                 break;
        //             case Electric:
                    
        //                 break;
        //             case Grass:
                    
        //                 break;
        //         }
        //     }
        //     else if(attacker->getType() == Water){
        //         switch (defender->getType()) {
        //             case Fire:

        //                 break;
        //             case Electric:
                    
        //                 break;
        //             case Grass:
                    
        //                 break;
        //         }
        //     }
            
            
        //     return final_dmg;

        // }



};