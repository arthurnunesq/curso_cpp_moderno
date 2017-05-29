#include <iostream>

template <class T>
T n_sum(T base) {
    return base;
}

template <class T, class ... Ts>
T n_sum(T first, Ts... rest) {
    return first + n_sum(rest...);
}

int main()
{
    std::cout << "n_sum(1,2.0,3L,4.0f,5) = " << n_sum(1,2.0,3L,4.0f,5) << std::endl;

    return 0;
}

