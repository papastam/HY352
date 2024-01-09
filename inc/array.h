#include <assert.h>
#include "utils.h"

#define ARRAYSIZE 50

#pragma once

template<class T> class Array {
    private:
        T* arr[ARRAYSIZE] = {0};
        int count;

    public:
        Array(){
            count = 0;
        }

        ~Array(){
            for(int i = 0; i < count; i++){
                arr[i] = nullptr;
            }
            count = 0;
        }

        // Copy constructor
        Array(const Array& _array){
            count = _array.count;
            for(int i = 0; i < count; i++){
                arr[i] = new T(*_array.arr[i]);
            }
        }

        // Copy assignment
        Array& operator=(const Array& _array){
            count = _array.count;
            for(int i = 0; i < count; i++){
                arr[i] = new T(*_array.arr[i]);
            }
            return *this;
        }

        // Move constructor
        Array(Array&& _array){
            count = _array.count;
            for(int i = 0; i < count; i++){
                arr[i] = _array.arr[i];
                _array.arr[i] = nullptr;
            }
            _array.count = 0;
        }

        // ------------------- Operators -------------------
        T* operator[](int i){
            assert(i < count);
            return arr[i];
        }

        // overload to get a pokemon by name
        T* operator[](const char* name){
            for(int i = 0; i < count; i++){
                if(strcmp(arr[i]->getName(), name) == 0){
                    return arr[i];
                }
            }
            return nullptr;
        }

        Array<T>* operator[](T _element){
            add(&_element);
            return this;
        }

        Array<T>* operator[](Array<T> _element){
            add(&_element);
            return this;
        }

        Array<T> operator,(T _element){
            add(&_element);
            return *this;
        }

        friend std::ostream& operator<<(std::ostream& os, Array* _arr){
            os << "Pokedex:" << std::endl;
            for(int i = 0; i < _arr->getCount(); i++){
                os << _arr->arr[i] << std::endl;
            }
            return os;
        }

        // ------------------- Methods -------------------
        void add(T* _element){
            // Check for duplicate names
            if((*this)[_element->getName()] != nullptr){
                error("Pokemon %s already in pokedex", _element->getName());
                return;
            }
            arr[count] = _element;
            count++;
        }

        void add(Array* _array){
            for(int i = 0; i < _array->getCount(); i++){
                if((*this)[(*_array)[i]->getName()] != nullptr){
                    error("Pokemon %s already in pokedex", (*_array)[i]->getName());
                    continue;
                }
                arr[count] = _array->arr[i];
                count++;
            }
        }


        // ------------------- Getters -------------------
        T getObj(const char *name){
            return *(*this)[name];
        }

        T getObj(int i){
            return *arr[i];
        }
        
        int getCount(){
            return count;
        }
};