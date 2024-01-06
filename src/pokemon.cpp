#include "../inc/pokemon.h"

BEGIN_GAME
    CREATE POKEMON{
        NAME: "Pikachu",
        TYPE: "Electric",
        HP: 100
    }

    // CREATE POKEMONS[
    //     POKEMON{
    //         NAME: "papastam",
    //         TYPE: "Electric",
    //         HP: 10
    //     }
    // ]

    CREATE POKEMONS[
        POKEMON{
            NAME: "papastam",
            TYPE: "Electric",
            HP: 10
        }
    ]
    ;std::cout << temp_pokedex.getCount() << std::endl
    
    SHOW *pokedex
    ;std::cout << temp_pokedex.getCount() << std::endl
    SHOW temp_pokedex

END_GAME