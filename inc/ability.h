#include <stdio.h>
#include <functional>
#include "array.h"

#define NAMESIZE 20

class Pokemon;

#pragma once

class Ability{
    private: 
        char name[20] = {0};
        std::function<void(Pokemon &, Pokemon &)> action;
        // we are assuming that both fnr and anr cant be !=0 at the same time
        int for_num_rounds;
        int after_num_rounds;
        bool newly_added;

    public:
        Ability(const char* _name, std::function<void(Pokemon &, Pokemon &)> _action){
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

    Array<Ability>& operator,(Ability &_ability){
        Array<Ability> *arr = new Array<Ability>();
        arr->add(*this);
        arr->add(_ability);
        return *arr;
    }

    friend std::ostream& operator<<(std::ostream& os, Ability* ab){
        os << ab->getName();
        return os;
    }

    // ------------------- Getters -------------------
    char*   getName()       {return name;}
    int     getFnr()        {return for_num_rounds;}
    void    decreaseFnr()   {for_num_rounds--;}
    int     getAnr()        {return after_num_rounds;}
    void    decreaseAnr()   {after_num_rounds--;}
    bool    getNewlyAdded() {return newly_added;}
    void   setNewlyAdded(bool _newly_added) {newly_added = _newly_added;}

    // ------------------- Functions -------------------
    void do_action(Pokemon &attacker, Pokemon &defender){
        action( attacker, defender );
    }

};