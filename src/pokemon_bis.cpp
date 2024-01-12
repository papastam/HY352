#include "../inc/grammar.h"

BEGIN_GAME

    CREATE POKEMONS[
        POKEMON{
            NAME : "KRYSTALLIA",
            TYPE : "Fire",
            HP : 100,
        },
        POKEMON{
            NAME : "PAPASTAMOS",
            TYPE : "Electric",
            HP : 100,
        }
    ]

    CREATE ABILITIES[
        ABILITY{
            NAME : "SEXUALITY",
            ACTION : START
                DAMAGE DEFENDER 5
                AFTER 1 ROUNDS DO 
                    DAMAGE DEFENDER 10
                END
                AFTER 2 ROUNDS DO 
                    DAMAGE DEFENDER 15
                END
            
            END
        },
        ABILITY{
            NAME : "EVNOUXISMOS",
            ACTION : START
                IF GET_HP(DEFENDER) < 40 DO
                    DAMAGE DEFENDER 50
                END
            END
        }
    ]

    DEAR "PAPASTAMOS" LEARN[
        ABILITY_NAME("SEXUALITY"),
        ABILITY_NAME("EVNOUXISMOS")
    ]
    DEAR "KRYSTALLIA" LEARN[
        ABILITY_NAME("SEXUALITY")
    ]

    DUEL

    // CREATE POKEMONS[
    //     POKEMON{
    //         NAME : "KRYSTALLIA",
    //         TYPE : "Fire",
    //         HP : 100,
    //     },
    //     POKEMON{
    //         NAME : "PAPASTAMOS",
    //         TYPE : "Electric",
    //         HP : 100,
    //     }
    // ]

    // CREATE ABILITIES[
    //     ABILITY{
    //         NAME : "SEXUALITY",
    //         ACTION : START
    //             DAMAGE DEFENDER 5
    //             AFTER 1 ROUNDS DO 
    //                 DAMAGE DEFENDER 10
    //             END
    //             AFTER 2 ROUNDS DO 
    //                 DAMAGE DEFENDER 15
    //             END
            
    //         END
    //     },
    //     ABILITY{
    //         NAME : "EVNOUXISMOS",
    //         ACTION : START
    //             IF GET_HP(DEFENDER) < 40 DO
    //                 DAMAGE DEFENDER 50
    //             END
    //         END
    //     }
    // ]

    // DEAR "PAPASTAMOS" LEARN[
    //     ABILITY_NAME("SEXUALITY"),
    //     ABILITY_NAME("EVNOUXISMOS")
    // ]
    // DEAR "KRYSTALLIA" LEARN[
    //     ABILITY_NAME("SEXUALITY")
    // ]

    // DUEL

END_GAME
