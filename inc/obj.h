#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdarg.h>
#include <iostream>

#define POKEDEX_ARRAY_SIZE 20
#define POKEMON_NAME_SIZE 20

// Declarations
class Pokemon;
class Pokedex;
class Ability;

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

        ~Pokemon(){
            printf("Pokemon %s is dead!\n", name);
        }

        // -------------------- Operators --------------------

        // ----- , -----
        // Pokedex operator,(Pokemon* pokemon){
        //     Pokedex* temp = new Pokedex();
        //     temp->addPokemon(this);
        //     temp->addPokemon(pokemon);
        //     return *temp;
        // }

        // ------------------- Functions -------------------

        char*       getName()       {return name;}
        int         getHp()         {return hp;}
        pok_Type    getType()       {return type;}
        bool        isInPokeball()  {return in_pokeball;}
};

class Pokedex {
    private:
        bool main_pokedex;
        Pokemon* pokedex[POKEDEX_ARRAY_SIZE];
        int count;

    public:
        // ------------------- Constructors -------------------
        Pokedex(bool is_main){
            main_pokedex = is_main;
            count = 0;
        }

        // Ignore the parameter
        // this is because the object is going to be later filled
        // by the overloaded [] operator and then assigned to temp_pokedex
        // later on the temp is going to be added to the main pokedex
        Pokedex(Pokedex* _pokedex){
            main_pokedex = false;
            count = 0;
        }

        ~Pokedex(){
            for(int i = 0; i < count; i++){
                delete pokedex[i];
            }
        }
 
        // -------------------- Operators --------------------

        // ----- [] -----
        Pokedex operator[](Pokemon* pokemon){
            this->addPokemon(pokemon);
            return this;
        }

        // overload to add a list of pokemons
        Pokedex operator[](Pokedex* _pokedex){
            this->addPokemon(_pokedex);
            return *this;
        }

        // overload to get a pokemon by name
        Pokemon* operator[](char* name){
            for(int i = 0; i < count; i++){
                if(strcmp(pokedex[i]->getName(), name) == 0){
                    return pokedex[i];
                }
            }
            return nullptr;
        }

        // overload to get a pokemon by index
        Pokemon* operator[](int index){
            return pokedex[index];
        }

        // ----- , -----
        Pokedex operator,(Pokedex* _pokedex){ //possibly will remain unused
            this->addPokemon(_pokedex);
            return *this;
        }

        Pokedex operator,(Pokemon pokemon){
            this->addPokemon(&pokemon);
            return *this;
        }

        // ----- << -----
        friend std::ostream& operator<<(std::ostream& os, const Pokedex pokedex){
            os << "Pokedex:" << std::endl;
            for(int i = 0; i < pokedex.count; i++){
                os << "  - " << pokedex.pokedex[i]->getName() << std::endl;
            }
            return os;
        }


        // -------------------- Functions --------------------
        
        //Two add functions overloaded to support both single 
        void addPokemon(Pokemon* pokemon){
            if(!main_pokedex){
                info("Adding pokemon %s to temp pokedex", pokemon->getName());
            } else {
                info("Adding pokemon %s to main pokedex", pokemon->getName());
            }
            if((*this)[pokemon->getName()] != nullptr){
                info("Pokemon %s already exists in pokedex", pokemon->getName());
                return;
            }
            pokedex[count] = pokemon;
            count++;
        }

        // and multiple pokemon additions
        void addPokemon(Pokedex _pokedex){
            info("Adding whole pokedex to current pokedex");
            int _count = 0;
            for(int i = 0; i < _pokedex.getCount(); i++){
                if((*this)[_pokedex[i]->getName()] != nullptr){
                    info("Pokemon %s already exists in pokedex", _pokedex[i]->getName());
                    continue;
                }
                pokedex[count++] = _pokedex[i];
                _count++;
            }
            _pokedex.setCount(0);
            // _pokedex.lose_refs();
        }

        // ---------- Get/Set ters ----------
        int getCount(){return count;}
        void setCount(int _count){count = _count;}    

        void lose_refs(){
            for(int i = 0; i < POKEDEX_ARRAY_SIZE; i++){
                pokedex[i] = nullptr;
            }
        }    
};

class Ability {
    private:
        char name[20];
        // virtual int action() = 0;

    public:
        Ability(char* _name, int (*_action)()){
            strcpy(name, _name);
            // action = _action;
        }
        ~Ability();

        char* getName()     {return name;}
        // int (*getAction())(){return action;}
};