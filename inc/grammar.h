#include <iostream>
#include "game.h"

#pragma once

// ------------------- Utulities -----------------
#define REMOVE_COL false?0 // Remove semicolon
#define REMOVE_COL_LF false?temp_lfunc

// Commands that need to be executed before each command
#define PRE_EXEC ;

// Clear temporary arrays
#define CLEAR_TEMP \
    temp_pok.clearArray();\
    temp_ab.clearArray();\

enum PokeballType
{
    α = false
};

PokeballType operator-(PokeballType value)
{
    return value;
}

bool operator--(PokeballType value)
{
	return static_cast<bool>(value);
}

// -------------------- Macros -------------------

#define BEGIN_GAME \
    int main(int argc, char *argv[]) {\
    Game game = Game();\
    Array<Pokemon> temp_pok = Array<Pokemon>();\
    Array<Ability> temp_ab = Array<Ability>();\
    std::function<void(Pokemon &, Pokemon &)> temp_lfunc;\
    bool _ = true;\

#define END_GAME \
    ;\
    return 0; \
    }

#define CREATE PRE_EXEC CLEAR_TEMP game +=
#define POKEMON *new Pokemon
#define POKEMONS temp_pok
#define NAME REMOVE_COL
#define TYPE REMOVE_COL
#define HP REMOVE_COL

#define ABILITY *new Ability
#define ABILITIES temp_ab
#define ACTION REMOVE_COL_LF

#define START [&](Pokemon &attacker, Pokemon &defender)->void{{
#define END PRE_EXEC }}
#define ATTACKER attacker +
#define DEFENDER defender +
#define DAMAGE PRE_EXEC -
#define HEAL PRE_EXEC
#define POKEBALL PRE_EXEC

#define DUEL PRE_EXEC CLEAR_TEMP game.duel()

#define DEAR PRE_EXEC CLEAR_TEMP game.getPokemonRef(
#define LEARN ) += temp_ab
#define ABILITY_NAME(x) game.getAbilities()->getObj(x)

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
// #define END ;}} already defined

// Loops
// FOR 5 ROUNDS DO
//     DAMAGE DEFENDER 20
// END
#define FOR PRE_EXEC attacker += *new Ability{
#define ROUNDS ,0,[&](Pokemon &attacker, Pokemon &defender
// #define DO ){ already defined
// #define END ;}} already defined

// After
// AFTER 5 ROUNDS DO
//     POKEBALL DEFENDER ---a
// END
#define AFTER ;for(int i = 0; i < 
// #define ROUNDS ; i++ already defined
// #define DO ){} already defined
// #define END ;}} already defined

// Print
// SHOW GET_NAME(ATTACKER) 
#define SHOW PRE_EXEC std::cout <<

#define PRINT_HW std::cout << "O papastamos gamietai" << std::endl;