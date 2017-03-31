#include <iostream>
#include <typeinfo>

constexpr int threshold = 100;

int main()
{
    static_assert(sizeof(int) > threshold, "not portable");
    static_assert(sizeof(unsigned int) > threshold, "not portable");
    static_assert(sizeof(unsigned long) > threshold, "not portable");
    static_assert(sizeof(long long) > threshold, "not portable");
    static_assert(sizeof(double) > threshold, "not portable");
    static_assert(sizeof(float) > threshold, "not portable");
    static_assert(sizeof(long double) > threshold, "not portable");

    return 0;
}

