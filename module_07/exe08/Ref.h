#ifndef REF_H
#define REF_H

#include <iostream>

template <class T>
class  ReferenceWrapper{
public:
    T& value;

    ReferenceWrapper(T& src) : value(src)    {
    }

    ~ReferenceWrapper(){
    }

    operator T&() const { return value; }
};

template <class T>
ReferenceWrapper<T> ref(T& src){
    std::cout << "Custom ref!" << std::endl;
    return ReferenceWrapper<T>(src);
}

#endif // REF_H

