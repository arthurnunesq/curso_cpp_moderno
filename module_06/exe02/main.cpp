#include <iostream>
#include "printtype.h"

struct Perso{};
typedef int (*fun)(double);
typedef Perso Tab[3][5][7];
typedef fun fun2(Tab*&);
typedef fun2** T2[9];
typedef Tab Perso::*U;

int main(){
    std::cout << Printtype<unsigned long*const*volatile*&()>().name() << std::endl;
    std::cout << Printtype<void(*&)(int(void),Perso&)>().name() << std::endl;
    std::cout << Printtype<const Perso&(...)>().name() << std::endl;
    std::cout << Printtype<long double(volatile int*const,...)>().name() << std::endl;
    std::cout << Printtype<int (Perso::**)(double)>().name() << std::endl;
    std::cout << Printtype<const volatile short Perso::*>().name() << std::endl;
    std::cout << Printtype<T2*(&)(long)>().name() << std::endl;
    std::cout << Printtype<U[][9]>().name() << std::endl;
}

// FIXME: const char[] is ambiguous!
