#include <iostream>
#include <string>

template <class T, size_t N>
void swap(T (&a) [N], T (&b) [N])
noexcept(noexcept(std::swap(a,b)))
{
}

int main()
{
    return 0;
}

