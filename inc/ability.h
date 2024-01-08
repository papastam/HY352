#include <stdio.h>
#include <functional>

#pragma once

class Ability{
    private: 
        char* name;
        std::function<void()> action;

    public:
        Ability(const char* _name, std::function<void()> _action){
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