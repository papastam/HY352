#include "pokemon.h"
#include "ability.h"
#include "array.h"

class Game{
    private:
        Array<Pokemon> pokemons;

    public:
        // ------------------- Constructors -------------------
        Game(){
            std::cout << "---------- Pokemon game for HY352 ----------" << std::endl;
            pokemons = Array<Pokemon>();
        }

        // Destructor
        ~Game(){
            std::cout << "----------- End of pokemon game ------------" << std::endl;
        }

        // Copy constructor
        Game(const Game& _game){
            pokemons = _game.pokemons;            
        }

        // Copy assignment
        Game& operator=(const Game& _game){
            pokemons = _game.pokemons;
            return *this;
        }

        // Move constructor
        Game(Game&& _game){
            pokemons = std::move(_game.pokemons);
        }

        // --------------------- Operators --------------------

        void operator+=(Pokemon* _pokemon){
            pokemons.add(_pokemon);
        }

        void operator+=(Array<Pokemon>* _pokemons){
            pokemons.add(_pokemons);
        }

        // -------------------- Get/Setters -------------------

        // get a pointer to the pokedex
        Array<Pokemon>* getPokemons(){
            return &pokemons;
        }

};