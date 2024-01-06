#include "obj.h"
#include <iostream>

// ------------------- Utulities -----------------
#define REMOVE_SC false?0 // Remove semicolon

// Commands that need to be executed before each command
#define PRE_EXEC ;\
    if(temp_pokedex.getCount()!=0){ \
        pokedex->addPokemon(temp_pokedex); \
    }else if(temp_pokemon != nullptr){ \
        pokedex->addPokemon(temp_pokemon); \
    } \
    temp_pokemon = nullptr;

#define CLEAR_MEMORY ;\
    delete pokedex; \
    delete temp_pokemon;

// -------------------- Macros -------------------

#define BEGIN_GAME \
    int main(int argc, char *argv[]) {\
    std::cout << "---------- Pokemon game for HY352 ----------" << std::endl;\
    Pokedex* pokedex = new Pokedex(true);\
    Pokemon* temp_pokemon = nullptr;\
    Pokedex temp_pokedex = Pokedex(false);\

#define END_GAME \
    ;\
    CLEAR_MEMORY;\
    std::cout << "---------- End of pokemon game ------------" << std::endl;\
    return 0; \
    } 

#define CREATE PRE_EXEC;
#define POKEMON temp_pokemon = new Pokemon
#define POKEMONS temp_pokedex
#define NAME REMOVE_SC
#define TYPE REMOVE_SC
#define HP REMOVE_SC

// UNIMPLEMENTED

#define ABILITY
#define ABILITIES
#define ACTION
#define START
#define ATTACKER
#define DEFENDER
#define DAMAGE
#define HEAL
#define POKEBALL

// ------------------ Actions ------------------
#define GET_HP(x) x->getHp()
#define GET_NAME(x) x->getName()
#define GET_TYPE(x) x->getType()
#define IS_IN_POKEBALL(x) x->isInPokeball()

// Logical operators
// AND(GET_TYPE(ATTACKER) == "Electric", GET_HP(ATTACKER) > 20)
#define AND(x, y) x && y
// OR(GET_TYPE(ATTACKER) == "Electric", GET_HP(ATTACKER) > 20)
#define OR(x, y) x || y
// NOT(GET_TYPE(ATTACKER) == "Electric")
#define NOT(x) !x

// Flow control
// IF(GET_TYPE(ATTACKER) == "Electric") DO
//     DAMAGE DEFENDER 20
// END
#define IF ;if(
#define DO ){
#define ELSE } else {
#define ELSE_IF } else if(
#define END }

// Loops
// FOR 5 ROUNDS DO
//     DAMAGE DEFENDER 20
// END
#define FOR ;for(int i = 0; i <
#define ROUNDS ; i++
// #define DO ){ already defined
// #define END } already defined

// After
// AFTER 5 ROUNDS DO
//     POKEBALL DEFENDER ---a
// END
#define AFTER ;for(int i = 0; i < 
// #define ROUNDS ; i++ already defined
// #define DO ){} already defined

// Print
// SHOW GET_NAME(ATTACKER) 
#define SHOW PRE_EXEC std::cout <<
