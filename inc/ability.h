#include <stdio.h>
#include <functional>

#define NAMESIZE 20

#pragma once

class Ability{
    private: 
        char name[20] = {0};
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