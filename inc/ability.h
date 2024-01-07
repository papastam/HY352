#include <stdio.h>
#include "pokemon.h"

class Ability{
    private: 
        char* name;

    public:
        Ability(char* _name){
            name = _name;
        }

        void cast_ability(Pokemon* target){
            target->setHp(target->getHp());
        }

};