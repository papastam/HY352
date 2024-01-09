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

        ~Ability(){
            action = nullptr;
        }

        Ability(const Ability& _ability){
            strcpy(name, _ability.name);
            action = _ability.action;
        }

        Ability& operator=(const Ability& _ability){
            strcpy(name, _ability.name);
            action = _ability.action;
            return *this;
        }

        Ability(Ability&& _ability){
            strcpy(name, _ability.name);
            action = _ability.action;
            _ability.name[0] = 0;
            _ability.action = nullptr;
        }

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