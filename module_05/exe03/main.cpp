#include "../exe01/BigInt.h"

namespace std{

void fast_swap(BigInt& a, BigInt& b){
    BigInt t(std::move(a));
    a = std::move(b);
    b = std::move(t);
}

}

constexpr int BIG_INT_LEN = 100000;
constexpr int TEST_NUM_COUNT = 1000;

int main(){
    BigInt a(1, BIG_INT_LEN);
    BigInt b(1, BIG_INT_LEN);

    for(int i = 0; i < TEST_NUM_COUNT; i++){
        std::swap(a, b);
    }
}

