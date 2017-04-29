#ifndef UNIQUE_PTR_H
#define UNIQUE_PTR_H

#include <iostream>

template <class T>
class unique_ptr
{
public:

unique_ptr(T* ptr)
: ptr_(ptr){
    std::cout << "unique_ptr<T>: created" << std::endl;
}

~unique_ptr() {
    delete ptr_;
    std::cout << "unique_ptr<T>: destroyed" << std::endl;
}

unique_ptr<T>(const unique_ptr<T>& ptr) = delete;
void operator=(const unique_ptr<T>& ptr) = delete;

unique_ptr(unique_ptr<T>&& ptr) : ptr_(ptr.ptr_)
{
    ptr.ptr_ = nullptr;
    std::cout << "unique_ptr<T>: Construtor de transferencia" << std::endl;
}

unique_ptr<T>& operator=(unique_ptr<T>&& ptr){
    ptr_ = ptr.ptr_;
    ptr.ptr_ = nullptr;
    std::cout << "unique_ptr<T>: Atribuicao por transferencia" << std::endl;
    return *this;
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


#endif // UNIQUE_PTR_H

