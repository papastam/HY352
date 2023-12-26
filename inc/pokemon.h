#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum type{
    Electric,
    Fire,
    Water,
    Grass
} pok_Type;

// ------------------- Objects -------------------

class Pokemons {
    private:
        Pokemon* pokemons[6];
        int count;
    public:
        Pokemons(){
            count = 0;
        }
        ~Pokemons(){
            for(int i = 0; i < count; i++){
                delete pokemons[i];
            }
        }
        void addPokemon(Pokemon* pokemon){
            pokemons[count] = pokemon;
            count++;
        }
};

class Pokemon {
    private:
        char name[20];
        int hp;
        pok_Type type;
        // Ability abilities[4];
    
    public:
        Pokemon(char* _name, int _hp, pok_Type _type){
            strcpy(name, _name);
            hp = _hp;
            type = _type;
        }
        
        Pokemon(){
            strcpy(name, "Default");
            hp = 10;
            type = Electric;
        };

        ~Pokemon(){
            printf("Pokemon %s is dead!\n", name);
        };
    
        // char*       getName()   {return name;}
        // int         getHp()     {return hp;}
        // pok_Type    getType()   {return type;}
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

// -------------------- Macros -------------------

#define BEGIN_GAME int main(int argc, char *argv[]) {\
    Pokemons* pokemons = new Pokemons();\
     
#define END_GAME  return 0; } 

#define CREATE  
#define POKEMON pokemons->addPokemon(new Pokemon
#define NAME name
#define TYPE type
#define HP hp

#define PRINT_HELLO printf("Hello World!\n");
