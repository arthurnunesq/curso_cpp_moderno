#ifndef CLOSURE_H
#define CLOSURE_H

#include <iostream>

template <class T>
class  Closure{
public:
    T value;

    Closure(T src) : value(src)
    {
        std::cout << "Closure(T)" << std::endl;
    }


    ~Closure(){
    }
};

// http://www.learncpp.com/cpp-tutorial/13-8-partial-template-specialization-for-pointers/
template <class T>
class  Closure<T*>{
public:
    T& value;

    Closure(T* src) : value(*src)
    {
        std::cout << "Closure(T*)" << std::endl;
    }

    ~Closure(){
    }
};

template <class T>
Closure<T> make_closure(T value){
    return Closure<T>(value);
}



#endif // CLOSURE_H

