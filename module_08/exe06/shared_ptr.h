#ifndef SHARED_PTR_H
#define SHARED_PTR_H

#include <iostream>

template <class T>
class shared_ptr
{

public:

shared_ptr(T* ptr)
: ptr_(ptr), counter_(new int(0)){
    std::cout << "shared_ptr<T>: constructor" << std::endl;
    increase();
}

~shared_ptr() {
    std::cout << "shared_ptr<T>: destructor" << std::endl;
    decrease();
}

shared_ptr(const shared_ptr<T>& ptr) : ptr_(ptr.ptr_), counter_(ptr.counter_){
    std::cout << "shared_ptr<T>: copy constructor" << std::endl;
    increase();
}

shared_ptr<T>& operator=(const shared_ptr<T>& ptr){
    std::cout << "shared_ptr<T>: assignment" << std::endl;
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
    std::cout << "shared_ptr<T>: transfer constructor" << std::endl;
}

shared_ptr<T>& operator=(shared_ptr<T>&& ptr){
    ptr_ = ptr.ptr_;
    counter_ = ptr.counter_;
    ptr.ptr_ = nullptr;
    ptr.counter_ = nullptr;
    std::cout << "shared_ptr<T>: transfer assignment" << std::endl;
    return *this;
}

void increase(){
    if(counter_) {
        (*counter_)++;
        std::cout << "shared_ptr<T>: counter incremented = " << *counter_ << std::endl;
    }
}

void decrease(){
    if(!counter_){
        return;
    }

    --(*counter_);
    std::cout << "shared_ptr<T>: counter decremented = " << *counter_ << std::endl;

    if(!*counter_){
        delete ptr_;
        delete counter_;
        ptr_ = nullptr;
        counter_ = nullptr;
        std::cout << "shared_ptr<T>: internal pointer deleted" << std::endl;
    }
}

T* get(){
    return ptr_;
}

private:
    T* ptr_ = nullptr;
    int* counter_ = nullptr;
};


#endif // SHARED_PTR_H

