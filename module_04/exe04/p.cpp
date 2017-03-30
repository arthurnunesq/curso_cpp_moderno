#include <iostream>
#include <vector>
#include <algorithm>

#define STR(symbol) #symbol

enum class FaultProtection : char{
    Active,  Unavailable
};

enum class ProcStatus: char{
    Active,  Waiting, Cancelled
};

bool checkViolation(ProcStatus s){
    if(s == ProcStatus::Active){
        std:: cout << STR(ProcStatus::Active);
    } else if(s == ProcStatus::Waiting){
        std:: cout << STR(ProcStatus::Waiting);
    } else if(s == ProcStatus::Cancelled){
        std:: cout << STR(ProcStatus::Cancelled);
    } else return true;
}

int main(){
    checkViolation(ProcStatus::Waiting);

    std:: cout << std::endl;

    return 0;
}
