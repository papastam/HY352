#include "obj.h"
#include <iostream>

// -------------------- Macros -------------------

#define BEGIN_GAME int main(int argc, char *argv[]) {\
    Pokemons* pokemons = new Pokemons();\
     
#define END_GAME  return 0; } 

#define CREATE  
#define POKEMON pokemons->addPokemon(new Pokemon
#define POKEMONS
#define NAME name=
#define TYPE type=
#define HP hp=

// UNIMPLEMENTED

#define ABILITY
#define ABILITIES
#define ACTION
#define START
#define END

// ------------------ Actions ------------------
#define ATTACKER
#define DEFENDER
#define DAMAGE
#define HEAL
#define POKEBALL
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
#define IF if(
#define DO ){
#define ELSE } else {
#define ELSE_IF } else if(
#define END }

// Loops
// FOR 5 ROUNDS DO
//     DAMAGE DEFENDER 20
// END
#define FOR for(int i = 0; i <
#define ROUNDS ; i++)
#define DO {
// #define END } already defined

// After
// AFTER 5 ROUNDS DO
//     POKEBALL DEFENDER ---a
// END
#define AFTER for(int i = 0; i < 
#define ROUNDS ; i++)
#define DO {}

// Print
// SHOW GET_NAME(ATTACKER)
#define SHOW std::cout <<


#define PRINT_HELLO printf("Hello World!\n");
