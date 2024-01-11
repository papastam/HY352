#include "../inc/grammar.h"

BEGIN_GAME

    CREATE POKEMON{
        NAME: "Picachu",
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
            NAME: "Oiko",
            TYPE: "Water",
            HP: 10000 
        },
        POKEMON{
            NAME: "Zmu",
            TYPE: "Fire",
            HP: 50
        },
        POKEMON{
            NAME: "Xiwths",
            TYPE: "Electric",
            HP: 100
        } 
    ]

    // SHOW game.getPokemons();

    // ;game += *new Ability{
    //     NAME: "Klwtsidi",
    //     ACTION: START
    //         PRINT_HW
    //     END
    // }

    // ;game += temp_ab[
    //     *new Ability{
    //         NAME: "Throw",
    //         ACTION: START
    //             PRINT_HW
    //         END
    //     },
    //     *new Ability{
    //         NAME: "Mpounia",
    //         ACTION: START
    //             PRINT_HW
    //         END
    //     }
    // ]

    CREATE ABILITIES[
        ABILITY{
            NAME: "Klwtsidi",
            ACTION: START
                PRINT_HW
            END
        },
        ABILITY{
            NAME: "Throw",
            ACTION: START
                PRINT_HW
            END
        },
        ABILITY{
            NAME: "Mpounia",
            ACTION: START
                PRINT_HW
            END
        },
        ABILITY{
            NAME: "GAMHSI",
            ACTION: START
                PRINT_HW
                ;- attacker + 10;
            END
        }
    ]

    DEAR "Papastam" LEARN[
        ABILITY_NAME("Klwtsidi"),
        ABILITY_NAME("Throw"),
        ABILITY_NAME("Mpounia")
    ]

    DEAR "Bis" LEARN[
        ABILITY_NAME("Klwtsidi"),
        ABILITY_NAME("Throw"),
        ABILITY_NAME("Mpounia"),
        ABILITY_NAME("GAMHSI")
    ]

    DEAR "Oiko" LEARN[
        ABILITY_NAME("Klwtsidi"),
        ABILITY_NAME("Throw"),
        ABILITY_NAME("Mpounia")
    ]

    DEAR "Zmu" LEARN[
        ABILITY_NAME("Mpounia")
    ]

    DEAR "Xiwths" LEARN[
        ABILITY_NAME("Klwtsidi"),
        ABILITY_NAME("Mpounia")
    ]

    SHOW game.getPokemons();

    // ;bool _ = true;
    // enum t{
    //     α = true
    // };
    
    // // _ = ---α;

    // bool test = _;
    // attacker^_;
    // ATTACKER _

    // DUEL

END_GAME