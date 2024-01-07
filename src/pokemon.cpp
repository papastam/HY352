#include "../inc/grammar.h"

BEGIN_GAME
    CREATE POKEMON{ 
        NAME: "Pikachu",
        TYPE: "Electric",
        HP: 100
    }
;
    // Pokedex temp_pokedex(true);

    ;game += new Array<Pokemon>[
        Pokemon{
            "papastam",
            "Electric",
            10
        }
    ]

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


    CREATE POKEMON{
        NAME: "Xiwths",
        TYPE: "Electric",
        HP: 100
    }

    SHOW game.getPokemons()

END_GAME



    // PRE_EXEC temp_pokedex[
    //     temp_pokemon = new Pokemon{
    //         "papastam2",
    //         "Electric",
    //         10
    //     }
    // ]
    
