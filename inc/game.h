#include "pokemon.h"
#include "ability.h"
#include <assert.h>
#include <cmath>

#pragma once

class Game{
    private:
        Array<Pokemon> pokemons;
        Array<Ability> abilities;
        int round;
        Pokemon* attacker;
        Pokemon* defender;
        Pokemon p1;
        Pokemon p2;
        bool game_started;
        // active abilities attacker/defender
        // pending abilities attacker/defender

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

        void operator+=(Pokemon &_pokemon){
            pokemons.add(_pokemon);
        }

        void operator+=(Array<Pokemon> _pokemons){
            pokemons.add(_pokemons);
        }

        void operator+=(Ability &_ability){
            abilities.add(_ability);
        }

        void operator+=(Array<Ability> _abilities){
            abilities.add(_abilities);
        }

        // -------------------- Get/Setters -------------------

        Array<Pokemon>* getPokemons()   {return &pokemons;}
        Array<Ability>* getAbilities()  {return &abilities;}

        Pokemon& getAttacker(){assert(game_started);return *attacker;}
        Pokemon& getDefender(){assert(game_started);return *defender;}
        bool getGameStarted(){return game_started;}
        
        Pokemon& getPokemonRef(const char* name){
            for(int i = 0; i < pokemons.getCount(); i++){
                if(strcmp(pokemons[i]->getName(), name) == 0){
                    return *pokemons[i];
                }
            }
            error("Pokemon not found");
            exit(0);
        }

        Pokemon getPokemon(const char* name){
            for(int i = 0; i < pokemons.getCount(); i++){
                if(strcmp(pokemons[i]->getName(), name) == 0){
                    return *pokemons[i];
                }
            }
            error("Pokemon not found");
            exit(0);
        }

        bool pokemon_exists(const char* name){
            for(int i = 0; i < pokemons.getCount(); i++){
                if(strcmp(pokemons[i]->getName(), name) == 0){
                    return true;
                }
            }
            return false;
        }

        bool ability_exists(const char* name){
            for(int i = 0; i < abilities.getCount(); i++){
                if(strcmp(abilities[i]->getName(), name) == 0){
                    return true;
                }
            }
            return false;
        }

        // -------------------- DUEL -------------------

        void duel(){
            game_started = true;
            char selected_name[20];
            Ability* selected;

            p1 = getPokemon(select_pokemon(1));
            p2 = getPokemon(select_pokemon(2));
            
            attacker = &p1;
            attacker->setPos(false);
            attacker->setPlayer(1);
            
            defender = &p2;
            defender->setPos(false);
            defender->setPlayer(2);

            attacker->setOpType(defender->getType());
            defender->setOpType(attacker->getType());           
            
            // assert(!attacker || !defender);

            while(1) {
                round++;
                attacker->setRound(round);
                defender->setRound(round);

                std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
                std::cout << "Round " << round << std::endl;
                std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
                
                for(int i = 0; i < 2; i++) {
                    // add 5% of max hp to attacker if type is grass and round is even
                    if (attacker->getType() == Grass && round % 2 == 0)
                        attacker->setHp(attacker->getHp() + (int)floor(attacker->getMaxHp() * 0.05));    
                    
                    // do necessary actions for any active FNR abilities
                    for(int i = 0 ; i < attacker->getFnrAbilities()->getCount(); i++) {
                        attacker->getFnrAbilities()->getObj(i).do_action(*attacker, *defender);
                        attacker->getFnrAbilities()->getObj(i).decreaseFnr();
                        if(attacker->getFnrAbilities()->getObj(i).getFnr() == 0)
                            attacker->getFnrAbilities()->remove_and_rearrange(i);
                    }

                    // do necessary actions for any active ANR abilities
                    for(int i = 0 ; i < attacker->getAnrAbilities()->getCount(); i++) {
                        attacker->getAnrAbilities()->getObj(i).decreaseAnr();
                        if(attacker->getAnrAbilities()->getObj(i).getAnr() == 0) {
                            attacker->getAnrAbilities()->getObj(i).do_action(*attacker, *defender);
                            attacker->getAnrAbilities()->remove_and_rearrange(i);
                        }
                    }

                    // check for game end after the abilities are triggered (if any)
                    if(is_dead(defender))
                        end_game(attacker);

                    selected = select_ability();

                    if(selected)
                        selected->do_action( *attacker, *defender);

                    // handle any newly added FNR abilities that need to be executed this round
                    for(int i = 0; i < attacker->getFnrAbilities()->getCount(); i++) {
                        if(attacker->getFnrAbilities()->getObj(i).getNewlyAdded()) {
                            attacker->getFnrAbilities()->getObj(i).do_action(*attacker, *defender);
                            attacker->getFnrAbilities()->getObj(i).decreaseFnr();
                            attacker->getFnrAbilities()->getObj(i).setNewlyAdded(false);
                        }
                    }

                    print_status();

                    //3. Check if defending pokemon is dead after the ability
                    if(is_dead(defender))
                        end_game(attacker);
                    
                    //4. Attacker/defender pointers are switched
                    switch_pointers();
                }
            }
        }

        // -------------------- Functions for Duel -------------------

        char* select_pokemon(int player_num) {
            char* selected_name = new char[20];
            while(1){
                std::cout << "Player "<< player_num << " choose your pokemon:" << std::endl;
                // std::cout << "-----------------------------------------" << std::endl;
                std::cout << getPokemons() << std::endl;
                // std::cout << "-----------------------------------------" << std::endl;
                std::cout << "Pokemon name: ";
                std::cin >> selected_name;
                if(!pokemon_exists(selected_name))
                    std::cout << "Pokemon not found, please select a valid pokemon!" << std::endl;        
                else
                    break;
            }
            return selected_name;
        }

        Ability* select_ability(){
            char selected_name[20];

            if(attacker->isInPokeball()){
                    std::cout << attacker->getName() << " is in pokeball and cannot attack" << std::endl;
            }else{
                //6. Action is performed
                std::cout << std::endl;
                std::cout << attacker->getName() << " select an ability:" << std::endl;
                std::cout << "--------------------" << std::endl;
                std::cout << attacker->getAbilities();
                std::cout << "--------------------" << std::endl;
                std::cout << "Ability name: ";
                std::cin >> selected_name;
                std::cout << std::endl;
                return attacker->get_ability(selected_name);
            }
            return nullptr;
        }

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

        void print_status() {
            std::cout << std::endl << std::endl;
            std::cout << "#############################" << std::endl;
            std::cout << "Name : " << attacker->getName() << std::endl;
            std::cout << "HP : " << attacker->getHp() << std::endl;
            if(attacker->isInPokeball())
                std::cout << "Pokemon is in Pokeball" << std::endl;
            else
                std::cout << "Pokemon is out of Pokeball" << std::endl;
            std::cout << "#############################" << std::endl;
            
            std::cout << std::endl << std::endl;

            std::cout << "#############################" << std::endl;
            std::cout << "Name : " << defender->getName() << std::endl;
            std::cout << "HP : " << defender->getHp() << std::endl;
            if(defender->isInPokeball())
                std::cout << "Pokemon is in Pokeball" << std::endl;
            else
                std::cout << "Pokemon is out of Pokeball" << std::endl;
            std::cout << "#############################" << std::endl;
            std::cout << std::endl << std::endl;

        }
};