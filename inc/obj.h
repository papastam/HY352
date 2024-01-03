#include <stdlib.h>
#include <string.h>
#include <stdio.h>

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

// ------------------- Objects -------------------

class Pokemon {
    private:
        char name[20];
        int hp;
        pok_Type type;
        bool in_pokeball;
        // Ability abilities[4];
    
    public:
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
    
        char*       getName()       {return name;}
        int         getHp()         {return hp;}
        pok_Type    getType()       {return type;}
        bool        isInPokeball()  {return in_pokeball;}
};
class Pokemons {
    private:
        Pokemon* pokemons[20];
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
        
        //Two add functions overloaded to support both single and multiple pokemon
        void addPokemon(Pokemon* pokemon){
            std::cout << "ADD1" << std::endl;
            pokemons[count] = pokemon;
            count++;
        }

        void addPokemon(Pokemon* pokemon_array[]){
            std::cout << "ADD2" << std::endl;
            int _count = 0;
            while(pokemon_array[_count] != NULL){
                pokemons[_count] = pokemon_array[count];
                _count++;
            }

            count += _count;
        }

        Pokemon* getPokemon(int index){
            return pokemons[index];
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