#include "../inc/grammar.h"

BEGIN_GAME
    CREATE POKEMON{
        NAME: "Pikachu",
        TYPE: "Electric",
        HP: 100
    }

    SHOW game.getPokedex()

END_GAME

    // CREATE POKEMON{
    //     NAME: "Oiko",
    //     TYPE: "Water",
    //     HP: 10000
    // }

    // CREATE POKEMON{
    //     NAME: "Zmu",
    //     TYPE: "Fire",
    //     HP: 50
    // }

    // CREATE POKEMON{
    //     NAME: "Xiwths",
    //     TYPE: "Electric",
    //     HP: 100
    // }

    // CREATE POKEMONS[
    //     temp_pokemon = new Pokemon{
    //         "papastam",
    //         "Electric",
    //         10
    //     },
    //     temp_pokemon = new Pokemon{
    //         "bis",
    //         "Grass",
    //         1
    //     }
    // ]

    // PRE_EXEC temp_pokedex[
    //     temp_pokemon = new Pokemon{
    //         "papastam2",
    //         "Electric",
    //         10
    //     }
    // ]
    
