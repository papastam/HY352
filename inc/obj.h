#include <stdlib.h>
#include <string.h>
#include <stdio.h>

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
        bool in_pokeball;
        // Ability abilities[4];
    
    public:
        Pokemon(char* _name, int _hp, pok_Type _type){
            strcpy(name, _name);
            hp = _hp;
            type = _type;
            in_pokeball = true;
        }
        
        Pokemon(){
            strcpy(name, "Default");
            hp = 10;
            type = Electric;
        };

        ~Pokemon(){
            printf("Pokemon %s is dead!\n", name);
        };
    
        char*       getName()       {return name;}
        int         getHp()         {return hp;}
        pok_Type    getType()       {return type;}
        bool        isInPokeball()  {return in_pokeball;}
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