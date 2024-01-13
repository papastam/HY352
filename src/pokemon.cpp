#include "../inc/grammar.h"

BEGIN_GAME
    CREATE POKEMONS[
        POKEMON{
            NAME: "Papastam GOD",
            TYPE: "Electric",
            HP: 1000
        },
        POKEMON{
            NAME: "Bis",
            TYPE: "Grass",
            HP: 60
        },
        POKEMON{
            NAME: "Oiko",
            TYPE: "Water",
            HP: 10000 
        },
        POKEMON{
            NAME: "Zmu",
            TYPE: "Fire",
            HP: 100
        },
        POKEMON{
            NAME: "Xiwths",
            TYPE: "Electric",
            HP: 1000
        }
    ]

    CREATE ABILITIES[
        ABILITY{
            NAME: "Punch",
            ACTION: START
                SHOW "Damaged 50 HP"
                DAMAGE DEFENDER 50
                AFTER 3 ROUNDS DO
                    SHOW "Defender is now bleeding from the punch\n"
                    FOR 3 ROUNDS DO
                        SHOW "Damaged 5 HP"
                        DAMAGE DEFENDER 5
                    END
                END
            END
        },
        ABILITY{
            NAME: "Poison",
            ACTION: START
                SHOW "Damage 10HP and 5HP for 5 rounds"
                DAMAGE DEFENDER 10
                FOR 5 ROUNDS DO
                    DAMAGE DEFENDER 10
                END
            END
        },
        ABILITY{
            NAME: "Heal",
            ACTION: START
                SHOW "Heal 30HP"
                HEAL ATTACKER 30
            END
        },
        ABILITY{
            NAME: "Confront",
            ACTION: START
                SHOW "Store in Pokeball for 3 rounds"
                POKEBALL DEFENDER _
                AFTER 3 ROUNDS DO
                    POKEBALL DEFENDER ---α
                END
            END
        },
        ABILITY{
            NAME: "Thunder",
            ACTION: START
                IF AND(GET_TYPE(ATTACKER) == "Electric", GET_HP(ATTACKER) > 20) DO
                    SHOW "DAAMAGED 100 HP"
                    DAMAGE DEFENDER 100
                END
            END
        },
        ABILITY{
            NAME: "SelfStab",
            ACTION: START
                SHOW "Damaged 3 HP for 5 rounds"
                FOR 5 ROUNDS DO
                    DAMAGE ATTACKER 3
                END
            END
        },
        ABILITY{
            NAME: "Execute",
            ACTION: START
                IF GET_HP(DEFENDER) < 50 DO
                    SHOW "You are dead"
                    DAMAGE DEFENDER 10000000
                END
            END
        },
        ABILITY{
            NAME: "Skip",
            ACTION: START
            SHOW "Skiped turn"
            END
        }
    ]

    DEAR "Papastam GOD" LEARN[
        ABILITY_NAME("Punch"),
        ABILITY_NAME("Poison"),
        ABILITY_NAME("Heal"),
        ABILITY_NAME("Confront"),
        ABILITY_NAME("Execute"),
        ABILITY_NAME("Skip")
    ]

    DEAR "Bis" LEARN[
        ABILITY_NAME("Punch"),
        ABILITY_NAME("Poison"),
        ABILITY_NAME("Heal"),
        ABILITY_NAME("Confront"),
        ABILITY_NAME("Skip")
    ]

    DEAR "Oiko" LEARN[
        ABILITY_NAME("Punch"),
        ABILITY_NAME("Heal"),
        ABILITY_NAME("Thunder"),
        ABILITY_NAME("Execute"),
        ABILITY_NAME("Skip")
    ]

    DEAR "Xiwths" LEARN[
        ABILITY_NAME("Punch"),
        ABILITY_NAME("Heal"),
        ABILITY_NAME("Confront"),
        ABILITY_NAME("Execute"),
        ABILITY_NAME("Skip")
    ]

    DEAR "Zmu" LEARN[
        ABILITY_NAME("Punch"),
        ABILITY_NAME("Heal"),
        ABILITY_NAME("SelfStab"),
        ABILITY_NAME("Execute"),
        ABILITY_NAME("Skip")
    ]

    DUEL

END_GAME