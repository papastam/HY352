#include <stdio.h>
#include "pokemon.h"

class Ability{
    private: 
        char* name;
        void (*action)();

    public:
        Ability(const char* _name, void (*_action)()){
            strcpy(name, _name);
            action = _action;
        }

        // void cast_ability(Pokemon* attacker, Pokemon* defender){
        //     action(attacker, defender)
        // }

};