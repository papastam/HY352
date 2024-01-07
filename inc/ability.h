#include <stdio.h>
#include "pokemon.h"

class Ability{
    private: 
        char* name;
        int damage; //negative damage is healing
        int turns_to_cast;
        int for_num_turns;

    public:
        Ability(char* _name, int _damage, int _turns_to_cast, int _for_num_turns){
            name = _name;
            damage = _damage;
            turns_to_cast = _turns_to_cast;
            for_num_turns = _for_num_turns;
        }

        void cast_ability(Pokemon* target){
            target->setHp(target->getHp() - damage);
        }

};