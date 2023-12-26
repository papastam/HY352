#include "../inc/pokemon.h"

BEGIN_GAME
    CREATE POKEMON {
        NAME: "name",
        TYPE: "type",
        HP: 10
    });

    Pokemon *p = new Pokemon{
        "name",
        10,
        Electric
    }
END_GAME