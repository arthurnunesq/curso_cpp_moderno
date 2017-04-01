#include "nonius/main.h++"
#include "BigInt.h"

template <class T>
void swap(T& a, T& b){
    T t(a);
    a = b;
    b = t;
}

template <class T>
void fast_swap(T& a, T& b){
    T t(std::move(a));
    a = std::move(b);
    b = std::move(t);
}


constexpr int BIG_INT_LEN = 100000;
constexpr int TEST_NUM_COUNT = 1000;

void test_swap(int count){
    BigInt a(1, BIG_INT_LEN);
    BigInt b(1, BIG_INT_LEN);

    for(int i = 0; i < count; i++){
        swap(a, b);
    }
}

void test_fast_swap(int count){
    BigInt a(1, BIG_INT_LEN);
    BigInt b(1, BIG_INT_LEN);

    for(int i = 0; i < count; i++){
        fast_swap(a, b);
    }
}

NONIUS_BENCHMARK("SwapTest", []
{
    test_swap(TEST_NUM_COUNT);
})

NONIUS_BENCHMARK("FastSwapTest", []
{
    test_fast_swap(TEST_NUM_COUNT);
})
