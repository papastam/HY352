#define ARRAYSIZE 50


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
            return arr[i];
        }

        // overload to get a pokemon by name
        T* operator[](char* name){
            for(int i = 0; i < count; i++){
                if(strcmp(arr[i]->getName(), name) == 0){
                    return arr[i];
                }
            }
            return nullptr;
        }

        void operator[](T _element){
            add(&_element);
        }

        friend std::ostream& operator<<(std::ostream& os, Array* _arr){
            os << "Pokedex:" << std::endl;
            for(int i = 0; i < _arr->getCount(); i++){
                os << "  - " << _arr->arr[i]->getName() << std::endl;
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
        int getCount(){
            return count;
        }
};