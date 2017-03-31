#include <iostream>
#include <typeinfo>

int main()
{
    std::cout   << "Type of 100: \t"      << typeid(100).name()       << std::endl
                << "Type of 100u: \t"     << typeid(100u).name()      << std::endl
                << "Type of 100UL: \t"    << typeid(100UL).name()     << std::endl
                << "Type of 100LL: \t"    << typeid(100LL).name()     << std::endl
                << "Type of 3.14: \t"     << typeid(3.14).name()      << std::endl
                << "Type of 3.14f: \t"    << typeid(3.14f).name()     << std::endl
                << "Type of 3.14L: \t"    << typeid(3.14L).name()     << std::endl;

    return 0;
}

