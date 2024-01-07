#include "../inc/grammar.h"

BEGIN_GAME
    CREATE POKEMON{ 
        NAME: "Pikachu",
        TYPE: "Electric",
        HP: 100
    }
;
    // Pokedex temp_pokedex(true);

    // ;game += (new Pokedex(false))[
    //     Pokemon{
    //         "papastam",
    //         "Electric",
    //         10
    //     },
    //     Pokemon{
    //         "bis",
    //         "Grass",
    //         1
    //     }
    // ]

    CREATE POKEMON{ 
        NAME: "Oiko",
        TYPE: "Water",
        HP: 10000 
    }

    CREATE POKEMON{
        NAME: "Zmu",
        TYPE: "Fire",
        HP: 50
    }

    CREATE POKEMON{
        NAME: "Xiwths",
        TYPE: "Electric",
        HP: 100
    }

    SHOW game.getPokedex()

END_GAME



    // PRE_EXEC temp_pokedex[
    //     temp_pokemon = new Pokemon{
    //         "papastam2",
    //         "Electric",
    //         10
    //     }
    // ]
    
