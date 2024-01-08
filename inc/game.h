#include "pokemon.h"
#include "ability.h"
#include <assert.h>

#pragma once

class Game{
    private:
        Array<Pokemon> pokemons;
        Array<Ability> abilities;
        int round;

    public:
        Pokemon* attacker;
        Pokemon* defender;
        
        // ------------------- Constructors -------------------
        Game(){
            std::cout << "---------- Pokemon game for HY352 ----------" << std::endl;
            pokemons = Array<Pokemon>();
            abilities = Array<Ability>();
            attacker = nullptr;
            defender = nullptr;
        }

        // Destructor
        ~Game(){
            std::cout << "----------- End of pokemon game ------------" << std::endl;
        }

        // Copy constructor
        Game(const Game& _game){
            pokemons = _game.pokemons;
            abilities = _game.abilities;
        }

        // Copy assignment
        Game& operator=(const Game& _game){
            pokemons = _game.pokemons;
            abilities = _game.abilities;
            return *this;
        }

        // Move constructor
        Game(Game&& _game){
            pokemons = std::move(_game.pokemons);
            abilities = std::move(_game.abilities);
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

        Array<Pokemon>* getPokemons(){return &pokemons;}
        Array<Ability> getAbilities(){return abilities;}

        Pokemon* getAttacker(){return attacker;}
        Pokemon* getDefender(){return defender;}

        // -------------------- DUEL -------------------

        void duel(){
            assert(!attacker || !defender);

            // EACH player chooses their pokemon


            while(1) {
                //1. Player 1 chooses an ability to cast
                //2. Action is performed
                //3. Check if defending pokemon is dead
                if(is_dead(defender))
                    //print winner and finish game
                //4. Attacker/defender pointers are switched
                switch_pointers();
                //5. Player 2 chooses an ability to cast
                //6. Action is performed
                //7. Check if defending pokemon is dead
                if(is_dead(defender))
                    //print winner and finish game
                //8. Attacker/Defender pointers are switched again
                switch_pointers();
                //9. Round number is increased
                round++;
            }
        }

        // -------------------- Functions for Duel -------------------

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


        Pokemon* getPokemon(const char* name){
            for(int i = 0; i < pokemons.getCount(); i++){
                if(strcmp(pokemons[i]->getName(), name) == 0){
                    return pokemons[i];
                }
            }
            error("Pokemon not found");
            return nullptr;
        }

};