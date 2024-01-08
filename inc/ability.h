#include <stdio.h>
#include <functional>
#include "pokemon.h"

class Ability{
    private: 
        char* name;
        std::function<void(Pokemon* p1, Pokemon* p2)> action;

    public:
        Ability(const char* _name, std::function<void(Pokemon* p1, Pokemon* p2)> _action){
            strcpy(name, _name);
            action = _action;
        }

        // void cast_ability(Pokemon* attacker, Pokemon* defender){
        //     action(attacker, defender)
        // }

    // ------------------- Operators -------------------

    // ------------------- Getters -------------------
    char* getName(){return name;}

};