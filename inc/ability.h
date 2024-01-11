#include <stdio.h>
#include <functional>
#include "array.h"

#define NAMESIZE 20

#pragma once

class Ability{
    private: 
        char name[20] = {0};
        std::function<void()> action;
        // we are assuming that both fnr and anr cant be !=0 at the same time
        int for_num_rounds;
        int after_num_rounds;

    public:
        Ability(const char* _name, std::function<void()> _action): action(_action){
            strcpy(name, _name);
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

    friend std::ostream& operator<<(std::ostream& os, Ability* ab){
        os << ab->getName();
        return os;
    }

    // ------------------- Getters -------------------
    char*   getName()       {return name;}
    int     get_anr()       {return after_num_rounds;}
    void    decrease_anr()  {after_num_rounds--;}
    int     get_fnr()       {return for_num_rounds;}
    void    decrease_fnr()  {for_num_rounds--;}

    // ------------------- Functions -------------------
    void do_action(){
        action();
    }

};