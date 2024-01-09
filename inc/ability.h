#include <stdio.h>
#include <functional>
#include "array.h"

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

    Array<Ability> operator,(Ability _ability){
            Array<Ability> arr = Array<Ability>();
            arr.add(this);
            arr.add(&_ability);
            return arr;
        }
    // ------------------- Getters -------------------
    char* getName(){return name;}

    // ------------------- Functions -------------------
    void do_action(){
        action();
    }

};