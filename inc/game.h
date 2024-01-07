#include "pokedex.h"
#include "pokemon.h"
#include "ability.h"

class Game{
    private:
        Pokedex pokedex;

    public:
        // ------------------- Constructors -------------------
        Game(){
            std::cout << "---------- Pokemon game for HY352 ----------" << std::endl;
            pokedex = Pokedex(true);
        }

        // Destructor
        ~Game(){
            std::cout << "----------- End of pokemon game ------------" << std::endl;
        }

        // Copy constructor
        Game(const Game& _game){
            pokedex = _game.pokedex;
        }

        // Copy assignment
        Game& operator=(const Game& _game){
            pokedex = _game.pokedex;
            return *this;
        }

        // Move constructor
        Game(Game&& _game){
            pokedex = _game.pokedex;
            _game.pokedex = Pokedex();
        }

        // --------------------- Operators --------------------

        void operator+=(Pokemon* _pokemon){
            pokedex.addPokemon(_pokemon);
        }

        // -------------------- Get/Setters -------------------

        // get a pointer to the pokedex
        Pokedex* getPokedex(){
            return &pokedex;
        }
};