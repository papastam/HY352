#include "../inc/grammar.h"

BEGIN_GAME

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
            END
        }
    ]

    // ;bool _ = true;
    // enum t{
    //     α = true
    // };
    
    // // _ = ---α;

    // bool test = _;
    // attacker^_;
    // ATTACKER _

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

    // ;temp_pok.clearArray();
    // temp_ab.clearArray();
    // *(game.getPokemon( "Zmu")) += temp_ab[
    //     game.getAbilities()->operator[]("Klwtsidi")

    //     // game.getAbilities()->getObj("Throw")
    // ]

    // ;temp_pok.clearArray(); temp_ab.clearArray(); *(game.getPokemon( "Zmu")) += temp_ab[
    //     &(game.getAbilities()->getObj("Klwtsidi"))
    //     // game.getAbilities()->getObj("Throw")
    // ]
    
    // ;temp_pok.clearArray(); temp_ab.clearArray(); *(game.getPokemon( "Xiwths")) += temp_ab[
    //     &(game.getAbilities()->getObj("Klwtsidi")),
    //     &(game.getAbilities()->getObj("Throw"))
    //     // game.getAbilities()->getObj("Throw")
    // ]
    

    DUEL

END_GAME