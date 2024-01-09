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

    CREATE ABILITY{
        NAME: "GAMHSI2",
        ACTION: START
            PRINT_HW
        END
    }

    CREATE ABILITIES[
        ABILITY{
            NAME: "TEST",
            ACTION: START
                PRINT_HW
            END
        },
        ABILITY{
            NAME: "TEST2",
            ACTION: START
                PRINT_HW
            END
        },
        ABILITY{
            NAME: "TEST3",
            ACTION: START
                PRINT_HW
            END
        }
    ]

    DEAR "Pikachu" LEARN[
        ABILITY_NAME("GAMHSI"),
        ABILITY_NAME("GAMHSI2"),
        ABILITY_NAME("TEST"),
        ABILITY_NAME("TEST2")
    ]

    DEAR "Papastam" LEARN[
        ABILITY_NAME("TEST3")
    ]

    ;game.getPokemon("Pikachu")->get_ability("GAMHSI")->do_action();

    SHOW game.getPokemons()

END_GAME