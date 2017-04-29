#ifndef SMART_PTR_H
#define SMART_PTR_H

#include <iostream>

template <class T>
class smart_ptr
{
public:

smart_ptr(T* ptr)
: ptr_(ptr){
    std::cout << "Created smart_ptr" << std::endl;
}

~smart_ptr() {
    delete ptr_;
    std::cout << "Destroyed smart_ptr" << std::endl;
}

T* get(){
    return ptr_;
}

T* release(){
    T* t = ptr_;
    ptr_ = nullptr;
    return t;
} 

private:
    T* ptr_;
};


#endif // SMART_PTR_H

