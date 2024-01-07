#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdarg.h>
#include <iostream>
#include "pokemon.h"

#define POKEDEX_ARRAY_SIZE 20

class Pokedex {
    private:
        bool main_pokedex;
        Pokemon* pokedex[POKEDEX_ARRAY_SIZE] = {nullptr};
        int count;

    public:
        // ------------------- Constructors -------------------
        Pokedex(){
            main_pokedex = false;
            count = 0;
        }
        
        Pokedex(bool is_main){
            main_pokedex = is_main;
            count = 0;
        }

        ~Pokedex(){
            for(int i = 0; i < count; i++){
                pokedex[i] = nullptr;
            }
            count = 0;
        }

        // Copy constructor
        Pokedex(const Pokedex& _pokedex){
            main_pokedex = _pokedex.main_pokedex;
            count = _pokedex.count;
            for(int i = 0; i < count; i++){
                pokedex[i] = new Pokemon(_pokedex.pokedex[i]->getName(), 
                                         _pokedex.pokedex[i]->getType(), 
                                         _pokedex.pokedex[i]->getHp());
            }
        }

        // Copy assignment
        Pokedex& operator=(const Pokedex& _pokedex){
            main_pokedex = _pokedex.main_pokedex;
            count = _pokedex.count;
            for(int i = 0; i < count; i++){
                pokedex[i] = new Pokemon(_pokedex.pokedex[i]->getName(), 
                                         _pokedex.pokedex[i]->getType(), 
                                         _pokedex.pokedex[i]->getHp());
            }
            return *this;
        }

        // Move constructor
        Pokedex(Pokedex&& _pokedex){
            main_pokedex = _pokedex.main_pokedex;
            count = _pokedex.count;
            for(int i = 0; i < count; i++){
                pokedex[i] = _pokedex.pokedex[i];
                _pokedex.pokedex[i] = nullptr;
            }
            _pokedex.count = 0;
        }
 
        // -------------------- Operators --------------------

        Pokedex & operator[](Pokedex* _pokedex){
            addPokemon(_pokedex);
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

        // ----- << -----
        friend std::ostream& operator<<(std::ostream& os, Pokedex* pokedex){
            os << "Pokedex:" << std::endl;
            for(int i = 0; i < pokedex->getCount(); i++){
                os << "  - " << pokedex->pokedex[i]->getName() << std::endl;
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
        void addPokemon(Pokedex* _pokedex){
            info("Adding whole pokedex to current pokedex");
            int _count = 0;
            for(int i = 0; i < _pokedex->getCount(); i++){
                if((*this)[(*_pokedex)[i]->getName()] != nullptr){
                    info("Pokemon %s already exists in pokedex", (*_pokedex)[i]->getName());
                    continue;
                }
                pokedex[count++] = (*_pokedex)[i];
                _count++;
            }
            _pokedex->setCount(0);
            // _pokedex.lose_refs();
        }

        // ---------- Get/Set ters ----------
        int getCount(){return count;}
        void setCount(int _count){count = _count;}    
 
};