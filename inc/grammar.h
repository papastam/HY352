#include <iostream>
#include "game.h"

#pragma once

// ------------------- Utulities -----------------
#define REMOVE_COL false?0 // Remove semicolon

// Commands that need to be executed before each command
#define PRE_EXEC ;

// Clear temporary arrays
#define CLEAR_TEMP \
    if(temp_pok.getCount() > 0){\
        temp_pok = Array<Pokemon>();\
    }\
    if(temp_ab.getCount() > 0){\
        temp_ab = Array<Ability>();\
    }

// -------------------- Macros -------------------

#define BEGIN_GAME \
    int main(int argc, char *argv[]) {\
    Game game = Game();\
    Array<Pokemon> temp_pok = Array<Pokemon>();\
    Array<Ability> temp_ab = Array<Ability>();\

#define END_GAME \
    ;\
    return 0; \
    }

#define CREATE PRE_EXEC CLEAR_TEMP game += new
#define POKEMON Pokemon
#define POKEMONS Array<Pokemon>; game += temp_pok
#define NAME REMOVE_COL
#define TYPE REMOVE_COL
#define HP REMOVE_COL

#define ABILITY Ability
#define ABILITIES Array<Ability>; game += temp_ab
#define ACTION REMOVE_COL

#define START std::function<void()>([&]()->void{
#define END })
#define ATTACKER game.getAttacker()
#define DEFENDER game.getDefender()
#define DAMAGE
#define HEAL
#define POKEBALL

#define DEAR PRE_EXEC CLEAR_TEMP *(game.getPokemon(
#define LEARN )) += temp_ab
#define ABILITY_NAME(x) game.getAbilities().getObj(x)

// ------------------ Actions ------------------
#define GET_HP(x) x->getHp()
#define GET_NAME(x) x->getName()
#define GET_TYPE(x) x->getTypestr()
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
// #define END } already defined

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

#define PRINT_HW std::cout << "Hello World" << std::endl;