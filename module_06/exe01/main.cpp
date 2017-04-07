#include <iostream>

int main()
{
    int i = 1;
    double d = 1.0


    std::cout   << "Type of (int + float): \t" << decltype(i+d) << std::endl;

    return 0;
}

