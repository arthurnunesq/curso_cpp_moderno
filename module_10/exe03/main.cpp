#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <deque>
#include <type_traits>

template<class T>
struct SumPolicy {
    static void accumulate(T& total, T v) { total += v; }
};

template<class T>
struct MultiplyPolicy {
    static void accumulate(T& total, T v) { total *= v; }
};

// https://stackoverflow.com/questions/12930653/getting-an-neutral-element-for-stdmultiply-and-stdplus
template <typename Policy> struct PolicyTraits;
template<>
struct PolicyTraits<SumPolicy<int> >
{
    static int const identity = 0;
};
template<>
struct PolicyTraits<MultiplyPolicy<int> >
{
    static int const identity = 1;
};

template <template<class> class Policy = SumPolicy>
struct Accumulator {
    template<class ForwardIteratorType>
    static typename std::iterator_traits<ForwardIteratorType>::value_type run(ForwardIteratorType cur, ForwardIteratorType end) {
        auto acc = PolicyTraits<Policy<typename std::iterator_traits<ForwardIteratorType>::value_type>>::identity;
        // std::cout << "acc = " << acc << std::endl;
        while (cur != end){
            // std::cout << "cur = " << *cur << std::endl;
            Policy<typename std::iterator_traits<ForwardIteratorType>::value_type>::accumulate(acc, *cur);
            cur++;
            // std::cout << "acc = " << acc << std::endl;
        }
        return acc;
    }
};

int main()
{
    const int LENGTH(6);
    int data[LENGTH] = { 1, 2, 3, 4, 5, 6 };
    std::vector<int> vData(data, data + LENGTH);
    std::list<int> lData(data, data + LENGTH);
    std::deque<int> dData(data, data + LENGTH);

    // https://stackoverflow.com/questions/15373823/template-default-arguments
    std::cout << "Array sum_acc: " << Accumulator<>::run(data, data + LENGTH) << std::endl;
    std::cout << "Vector sum_acc: " << Accumulator<>::run(vData.begin(), vData.end()) << std::endl;
    std::cout << "List sum_acc: " << Accumulator<>::run(lData.begin(), lData.end()) << std::endl;  
    std::cout << "Deque sum_acc: " << Accumulator<>::run(dData.begin(), dData.end()) << std::endl;

    std::cout << "Array mult_acc: " << Accumulator<MultiplyPolicy>::run(data, data + LENGTH) << std::endl;
    std::cout << "Vector mult_acc: " << Accumulator<MultiplyPolicy>::run(vData.begin(), vData.end()) << std::endl;
    std::cout << "List mult_acc: " << Accumulator<MultiplyPolicy>::run(lData.begin(), lData.end()) << std::endl;  
    std::cout << "Deque mult_acc: " << Accumulator<MultiplyPolicy>::run(dData.begin(), dData.end()) << std::endl;

    return 0;
}

