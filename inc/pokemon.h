#include <stdio.h>
#include <stdarg.h>
#include <iostream>
#include <string.h>

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
        printf("Error: Unknown pokemon type %s\n", str);
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
            printf("Error: Unknown pokemon type %d\n", type);
            exit(1);
    }
}

// info print function with variadic arguments
void info(const char* format, ...){
    va_list args;
    va_start(args, format);
    printf("INFO: ");
    vprintf(format, args);
    printf("\n");
    va_end(args);
}

// ------------------- Objects -------------------

class Pokemon {
    private:
        char name[POKEMON_NAME_SIZE];
        int hp;
        pok_Type type;
        bool in_pokeball;
        // Ability abilities[4];
    
    public:
        // ------------------- Constructors -------------------

        Pokemon(const char* _name, const char* _type, int _hp){
            strcpy(name, _name);
            type = strToType(_type);
            hp = _hp;
            in_pokeball = true;
        }
        
        Pokemon(){
            strcpy(name, "Default");
            hp = 10;
            type = Electric;
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
        }

        // Copy assignment
        Pokemon& operator=(const Pokemon& _pokemon){
            strcpy(name, _pokemon.name);
            hp = _pokemon.hp;
            type = _pokemon.type;
            in_pokeball = _pokemon.in_pokeball;
            return *this;
        }

        // Move constructor
        Pokemon(Pokemon&& _pokemon){
            strcpy(name, _pokemon.name);
            hp = _pokemon.hp;
            type = _pokemon.type;
            in_pokeball = _pokemon.in_pokeball;
            _pokemon.hp = 0;
            _pokemon.in_pokeball = false;
        }

        // -------------------- Operators --------------------
        
        // ------------------- Functions -------------------

        char*       getName()       {return name;}
        int         getHp()         {return hp;}
        const char* getType()       {return typeToStr(type);}
        bool        isInPokeball()  {return in_pokeball;}
};
