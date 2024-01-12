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
            NAME: "Takeout",
            ACTION: START
                POKEBALL ATTACKER ---α
            END
        },
        ABILITY{
            NAME: "Store",
            ACTION: START
                POKEBALL DEFENDER _
            END
        },
        ABILITY{
            NAME: "Heal10",
            ACTION: START
                HEAL ATTACKER 10
            END
        },
        ABILITY{
            NAME: "Damage10",
            ACTION: START
                DAMAGE DEFENDER 10

            END
        }
    ]

    DEAR "Papastam" LEARN[
        ABILITY_NAME("Takeout"),
        ABILITY_NAME("Store"),
        ABILITY_NAME("Heal10"),
        ABILITY_NAME("Damage10")
    ]

    DEAR "Bis" LEARN[
        ABILITY_NAME("Takeout"),
        ABILITY_NAME("Store"),
        ABILITY_NAME("Heal10"),
        ABILITY_NAME("Damage10")
    ]

    DEAR "Oiko" LEARN[
        ABILITY_NAME("Takeout"),
        ABILITY_NAME("Store")
    ]

    DEAR "Zmu" LEARN[
        ABILITY_NAME("Takeout")
    ]

    DEAR "Xiwths" LEARN[
        ABILITY_NAME("Heal10"),
        ABILITY_NAME("Damage10")
    ]

    // SHOW game.getPokemons();
    
    DUEL

END_GAME