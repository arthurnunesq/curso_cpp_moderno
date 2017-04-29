#ifndef SHARED_PTR_H
#define SHARED_PTR_H

#include <iostream>

template <class T>
class shared_ptr
{

public:

shared_ptr(T* ptr)
: ptr_(ptr), counter_(new int(0)){
    std::cout << "shared_ptr<T>: created" << std::endl;
    increase();
}

~shared_ptr() {
    decrease();
    std::cout << "shared_ptr<T>: deleted, counter = " << (counter_ ? (*counter_) : -1) << std::endl;
}

shared_ptr(const shared_ptr<T>& ptr) : ptr_(ptr.ptr_), counter_(ptr.counter_){
    std::cout << "shared_ptr<T>: copyied" << std::endl;
    increase();
}

shared_ptr<T>& operator=(const shared_ptr<T>& ptr){
    if(this!=&ptr)
    {
        ptr_ = ptr.ptr_;
        counter_ = ptr.counter_;
        increase();
    }
}

shared_ptr(shared_ptr<T>&& ptr) : ptr_(ptr.ptr_), counter_(ptr.counter_)
{
    ptr.ptr_ = nullptr;
    ptr.counter_ = nullptr;
    std::cout << "shared_ptr<T>: Construtor de transferencia" << std::endl;
}

shared_ptr<T>& operator=(shared_ptr<T>&& ptr){
    ptr_ = ptr.ptr_;
    counter_ = ptr.counter_;
    ptr.ptr_ = nullptr;
    ptr.counter_ = nullptr;
    std::cout << "shared_ptr<T>: Atribuicao por transferencia" << std::endl;
    return *this;
}

void increase(){
    if(counter_) {
        (*counter_)++;
    }
}

void decrease(){
    if(counter_ && !(--(*counter_))){
        delete ptr_;
        delete counter_;
        ptr_ = nullptr;
        counter_ = nullptr;
        std::cout << "shared_ptr<T>: Deleted pointer" << std::endl;
    }
}

T* get(){
    return ptr_;
}

T* release(){
    T* t = ptr_;
    ptr_ = nullptr;
    counter_ = nullptr;
    return t;
} 

private:
    T* ptr_ = nullptr;
    int* counter_ = nullptr;
};


#endif // SHARED_PTR_H

