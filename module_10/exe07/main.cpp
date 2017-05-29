#include <iostream>
#include <string>
#include <memory>
#include <vector>

template <class T>
struct IsClassType
{
    template <class C> static char size(int C::*);
    template <class C> static std::int16_t size(...);
    enum { Yes = sizeof(IsClassType<T>::size<T>(nullptr)) == 1 };
    enum { No = !Yes };
};

template <class T>
void f() {
    if (IsClassType<T>::Yes)
        std::cout << "yes" << std::endl;
    else
        std::cout << "no" << std::endl;
}

struct MyStruct{};

int main()
{
    std::cout << "IsClassType<int> = "; f<int>();
    std::cout << "IsClassType<MyStruct> = "; f<MyStruct>();

    return 0;
}

