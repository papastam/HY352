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
        NAME: "GAMHSI",
        ACTION: START
            PRINT_HW
        END
    }

    CREATE ABILITY{
        NAME: "GAMHSI2",
        ACTION: START
            PRINT_HW
        END
    }

    // CREATE ABILITIES[
    //     ABILITY{
    //         NAME: "TEST",
    //         ACTION: START
    //             PRINT_HW
    //         END
    //     },
    //     ABILITY{
    //         NAME: "TEST2",
    //         ACTION: START
    //             PRINT_HW
    //         END
    //     }
    // ]

    // ;void std::function<void()>::operator+=(std::function<void()> f){
    //     f();
    // } 

    // ;std::function<void()>() += [&]()->void{
    //     std::cout << "Hello World" << std::endl;
    // }


    ; game += new Array<Ability>; game += temp_ab[
        Ability{
            "TEST",
            std::function<void()>([&]()->void{
                std::cout << "Hello World" << std::endl;
            })
        },
        Ability{
            "TEST2",
            std::function<void()>([&]()->void{
                std::cout << "Hello World" << std::endl;
            })
        },
        Ability{
            "TEST3",
            std::function<void()>([&]()->void{
                std::cout << "Hello World" << std::endl;
            })
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

    // CREATE ABILITY{
    //     NAME: "TEST",
    //     ACTION: START
    //         IF GET_HP(ATTACKER) DO
    //         END

    //     END
    // }
    ;game.getPokemon("Pikachu")->get_ability("GAMHSI")->do_action();

    SHOW game.getPokemons()

END_GAME