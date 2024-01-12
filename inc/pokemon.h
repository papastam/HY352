#include <stdio.h>
#include <stdarg.h>
#include <iostream>
#include <string.h>

#include "array.h"
#include "utils.h"
#include "ability.h"

#pragma once

#define POKEMON_NAME_SIZE 20

typedef enum e_type{
    Electric,
    Fire,
    Water,
    Grass
} pok_Type;

// ------------------- Utulities -----------------
pok_Type strToType(const char* str){
    if(strcmp(str, "Electric") == 0){
        return Electric;
    } else if(strcmp(str, "Fire") == 0){
        return Fire;
    } else if(strcmp(str, "Water") == 0){
        return Water;
    } else if(strcmp(str, "Grass") == 0){
        return Grass;
    } else {
        error("Unknown pokemon type %s\n", str);
        exit(1);
    }
}

const char* typeToStr(pok_Type type){
    switch(type){
        case Electric:
            return "Electric";
        case Fire:
            return "Fire";
        case Water:
            return "Water";
        case Grass:
            return "Grass";
        default:
            error("Unknown pokemon type %d\n", type);
            exit(1);
    }
}

// ------------------- Objects -------------------

class Pokemon {
    private:
        char name[POKEMON_NAME_SIZE]= {0};
        int hp;
        pok_Type type;
        pok_Type opponent_type;
        bool in_pokeball;
        int player;
        Array<Ability> abilities;
        Array<Ability> active_abilities;
        bool damage_pending;
    
    public:
        // ------------------- Constructors -------------------
        Pokemon(const char* _name, const char* _type, int _hp){
            strcpy(name, _name);
            type = strToType(_type);
            hp = _hp;
            in_pokeball = true;
            abilities = Array<Ability>();
            damage_pending = false;
        }
        
        Pokemon(){
            strcpy(name, "Default");
            hp = 10;
            type = Electric;
            in_pokeball = true;
            abilities = Array<Ability>();
            damage_pending = false;
        }

        // Destructor
        ~Pokemon(){
        }

        // Copy constructor
        Pokemon(const Pokemon& _pokemon){
            strcpy(name, _pokemon.name);
            hp = _pokemon.hp;
            type = _pokemon.type;
            in_pokeball = _pokemon.in_pokeball;
            abilities = _pokemon.abilities;
            damage_pending = _pokemon.damage_pending;
        }

        // Copy assignment
        Pokemon& operator=(const Pokemon& _pokemon){
            strcpy(name, _pokemon.name);
            hp = _pokemon.hp;
            type = _pokemon.type;
            in_pokeball = _pokemon.in_pokeball;
            abilities = _pokemon.abilities;
            damage_pending = _pokemon.damage_pending;
            return *this;
        }

        // Move constructor
        Pokemon(Pokemon&& _pokemon){
            strcpy(name, _pokemon.name);
            hp = _pokemon.hp;
            type = _pokemon.type;
            in_pokeball = _pokemon.in_pokeball;
            abilities = _pokemon.abilities;
            _pokemon.hp = 0;
            _pokemon.in_pokeball = false;   
            _pokemon.abilities = Array<Ability>();
            damage_pending = _pokemon.damage_pending;
        }

        // -------------------- Operators --------------------
        
        Array<Pokemon>& operator,(Pokemon& _pokemon){
            Array<Pokemon> *arr = new Array<Pokemon>();
            arr->add(*this);
            arr->add(_pokemon);
            return *arr;
        }

        Pokemon& operator-(){
            damage_pending = true;
            return *this;
        }

        Pokemon& operator+(int _hp){
            if(damage_pending){
                damage_pending = false;
                // TODO: Call the damage function
                hp -= _hp;
            }else{
                hp += _hp;
            }
            return *this;
        }

        void operator+(bool pok){
            in_pokeball = pok;
        }

        friend std::ostream& operator<<(std::ostream& os, Pokemon* pok){
            os << "  - " << pok->getName() << " (" << pok->getTypestr() << ", HP: " << pok->getHp() << ")";
            if(pok->abilities.getCount() != 0){
                os << " [Abilities: ";
                for(int i = 0; i < pok->abilities.getCount(); i++){
                    os << pok->abilities[i]->getName() << " ";
                }
                os << "]";
            }
            return os;
        }

        void operator+=(Array<Ability> &_abilities){
            for(int i = 0; i < _abilities.getCount(); i++){
                if(ability_exists(_abilities[i]->getName())){
                    error("Ability %s already exists\n", _abilities.getObj(i).getName());
                    continue;
                }
                abilities.add(*_abilities[i]);
            }
        }

        // ------------------- Functions -------------------

        // int damage(int initial_dmg) {
        //     int final_dmg = initial_dmg; // if no modifiers are applied then deal the initial dmg
            
        //     if(attacker->getType() == Electric) {
        //         switch (defender->getType()) {
        //             case Fire:

        //                 break;
        //             case Electric:
                    
        //                 break;
        //             case Grass:
                    
        //                 break;
        //         }
        //     }
        //     else if(attacker->getType() == Fire){
        //         switch (defender->getType()) {
        //             case Fire:

        //                 break;
        //             case Electric:
                    
        //                 break;
        //             case Grass:
                    
        //                 break;
        //         }
        //     }
        //     else if(attacker->getType() == Water){
        //         switch (defender->getType()) {
        //             case Fire:

        //                 break;
        //             case Electric:
                    
        //                 break;
        //             case Grass:
                    
        //                 break;
        //         }
        //     }
            
            
        //     return final_dmg;

        // }

        bool ability_exists(const char* ability_name){
            for(int i = 0; i < abilities.getCount(); i++) {
                if(!strcmp(abilities[i]->getName(), ability_name)){
                    return true;
                }
            }
            return false;
        }

        char*           getName()           {return name;}
        int             getHp()             {return hp;}
        void            setHp(int value)    {hp = value;}
        int             getPlayer()         {return player;}
        void            setPlayer(int i)    {player = i;}
        const char*     getTypestr()        {return typeToStr(type);}
        pok_Type        getType()           {return type;}
        bool            isInPokeball()      {return in_pokeball;}
        Array<Ability>* getAbilities()      {return &abilities;}
        void            setPos(bool inPoke) {in_pokeball = inPoke;}
        void            setOpType(pok_Type type) {opponent_type = type;}

        Ability* get_ability(const char* ability_name){
            for(int i = 0; i < abilities.getCount(); i++) {
                if(!strcmp(abilities[i]->getName(), ability_name)){
                    return abilities[i];
                }
            }
            return nullptr;
        }
};
