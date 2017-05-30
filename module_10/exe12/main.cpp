#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <algorithm>

void print(const std::vector<std::tuple<int, char>>& v){
    for(auto t : v)
        std::cout << "<" << std::get<0>(t) << ", " << std::get<1>(t) << ">" << std::endl;
}

int main()
{
    std::vector<std::tuple<int, char>> v = {
        std::make_tuple(4, 'a'),
        std::make_tuple(3, 'a'),
        std::make_tuple(9, 'b'),
        std::make_tuple(9, 'a'),
        std::make_tuple(1, 'a'),
        std::make_tuple(10, 'a'),
        std::make_tuple(1, 'b'),
        std::make_tuple(2, 'a'),
        std::make_tuple(7, 'a')    
    };

    std::cout << "Unsorted:" << std::endl;
    print(v);
    std::cout << std::endl;

    auto compare = [](std::tuple<int, char> a, std::tuple<int, char> b) {
        return std::get<0>(a) < std::get<0>(b);   
    };

    std::vector<std::tuple<int, char>> v1 = v;
    std::sort(v1.begin(), v1.end(), compare);
    std::cout << "std::sort():" << std::endl;
    print(v1);
    std::cout << std::endl;

    std::vector<std::tuple<int, char>> v2 = v;
    std::partial_sort(v2.begin(), v2.end(), v2.end(), compare);
    std::cout << "std::partial_sort():" << std::endl;
    print(v2);
    std::cout << std::endl;

    std::vector<std::tuple<int, char>> v3 = v;
    std::stable_sort(v3.begin(), v3.end(), compare);
    std::cout << "std::stable_sort():" << std::endl;
    print(v3);
    std::cout << std::endl;

    return 0;
}


