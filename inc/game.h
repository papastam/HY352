#include "pokemon.h"
#include "ability.h"

#pragma once

class Game{
    private:
        Array<Pokemon> pokemons;
        Array<Ability> abilities;

    public:
        // ------------------- Constructors -------------------
        Game(){
            std::cout << "---------- Pokemon game for HY352 ----------" << std::endl;
            pokemons = Array<Pokemon>();
            abilities = Array<Ability>();
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

        // get a pointer to the pokedex
        Array<Pokemon>* getPokemons(){return &pokemons;}

        // get a pointer to the abilities
        Array<Ability>* getAbilities(){return &abilities;}

};