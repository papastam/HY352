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
        T& operator[](const char* name){
            for(int i = 0; i < count; i++){
                if(strcmp(arr[i]->getName(), name) == 0){
                    return *arr[i];
                }
            }
            error("Element %s not found in the array", name);
            exit(0);
        }

        Array<T>& operator[](T &_element){
            add(_element);
            return *this;
        }

        Array<T>& operator[](Array<T> &_element){
            add(_element);
            return *this;
        }

        Array<T>& operator,(T &_element){
            add(_element);
            return *this;
        }

        friend std::ostream& operator<<(std::ostream& os, Array* _arr){
            for(int i = 0; i < _arr->getCount(); i++){
                os << _arr->arr[i] << std::endl;
            }
            return os;
        }

        // ------------------- Methods -------------------
        void add(T &_element){
            // Check for duplicate names
            if(exists(_element.getName())){
                error("Element %s already in the array", _element.getName());
                return;
            }
            arr[count] = &_element;
            count++;
        }

        void add(Array &_array){
            for(int i = 0; i < _array.getCount(); i++){
                if(exists(_array[i]->getName())){
                    error("Element %s already in the array", _array[i]->getName());
                    continue;
                }
                arr[count] = _array.arr[i];
                count++;
            }
        }

        void clearArray(){
            for(int i = 0; i < count; i++){
                arr[i] = nullptr;
            }
            count = 0;
        }

        void remove_and_rearrange(int i){
            arr[i] = arr[count-1];
            arr[count-1] = nullptr;
            count--;
        }

        bool exists(const char* name){
            for(int i = 0; i < count; i++){
                if(strcmp(arr[i]->getName(), name) == 0){
                    return true;
                }
            }
            return false;
        }

        // ------------------- Getters -------------------
        T& getObj(const char *name){
            return (*this)[name];
        }

        T& getObj(int i){
            return *arr[i];
        }
        
        int getCount(){
            return count;
        }
};