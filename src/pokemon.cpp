#include "../inc/grammar.h"

BEGIN_GAME
    CREATE POKEMON{ 
        NAME: "Pikachu",
        TYPE: "Electric",
        HP: 100
    }

    CREATE POKEMONS[
        POKEMON{
            NAME: "Papastam",
            TYPE: "Electric",
            HP: 10
        },
        POKEMON{
            NAME: "Bis",
            TYPE: "Grass",
            HP: 1
        },
        POKEMON{
            NAME: "Bis2",
            TYPE: "Grass",
            HP: 1
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

    // DEAR "Pikachu" LEARN[
    //     ABILITY_NAME("ab_name")
    // ]

    // CREATE ABILITY{
    //     NAME: "TEST",
    //     ACTION: START
    //         IF GET_HP(ATTACKER) DO
    //         END

    //     END
    // }

    SHOW game.getPokemons()

END_GAME