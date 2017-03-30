#include <iostream>
#include <vector>
#include <algorithm>

void g(){
    std::vector<int> v = {1, 2, 3, 4};

    for(int& n : v){
        n++;
        std::cout << " " << n;
    }
    std::cout << std::endl;

    std::for_each(v.begin(), v.end(), [](int &n){ n++; });
    std::for_each(v.begin(), v.end(), [](const int& n) { std::cout << " " << n; });

    std::cout << std::endl;
}

int main(){
    g();

    return 0;
}
