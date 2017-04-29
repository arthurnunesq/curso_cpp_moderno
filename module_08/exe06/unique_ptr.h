#ifndef UNIQUE_PTR_H
#define UNIQUE_PTR_H

#include <iostream>

template <class T>
class unique_ptr
{
public:

unique_ptr(T* ptr)
: ptr_(ptr){
    std::cout << "unique_ptr<T>: construtor" << std::endl;
}

~unique_ptr() {
	if(ptr_){
        std::cout << "unique_ptr<T>: internal pointer deleted" << std::endl;		
	}
    delete ptr_;
    std::cout << "unique_ptr<T>: destructor" << std::endl;
}

unique_ptr<T>(const unique_ptr<T>& ptr) = delete;
void operator=(const unique_ptr<T>& ptr) = delete;

unique_ptr(unique_ptr<T>&& ptr) : ptr_(ptr.ptr_)
{
    ptr.ptr_ = nullptr;
    std::cout << "unique_ptr<T>: transfer constructor" << std::endl;
}

unique_ptr<T>& operator=(unique_ptr<T>&& ptr){
    ptr_ = ptr.ptr_;
    ptr.ptr_ = nullptr;
    std::cout << "unique_ptr<T>: transfer assignment" << std::endl;
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

