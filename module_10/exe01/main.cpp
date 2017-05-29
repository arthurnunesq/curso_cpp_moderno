#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <deque>
#include <type_traits>

// template<typename T>
// T sum(T* array, int n) {
// 	T result = T();
// 	for (int i = 0; i < n; ++i)
// 		result = result + array[i];
// 	return result;
// }

// http://www.cplusplus.com/forum/articles/20881/
// https://stackoverflow.com/questions/18467190/a-template-function-that-takes-iterators-or-pointers-and-gets-the-pointed-to-typ
template<class ForwardIteratorType>
typename std::iterator_traits<ForwardIteratorType>::value_type sum( ForwardIteratorType begin, ForwardIteratorType end) {
	auto result = typename std::iterator_traits<ForwardIteratorType>::value_type();
    while(begin != end)
    {
		result = result + *(begin);
        ++begin;
    }

	return result;
}

int main()
{
    const int LENGTH(6);
    int data[LENGTH] = { 5, 7, 8, 9, 1, 2 };
    std::vector<int> vData(data, data + LENGTH);
    std::list<int> lData(data, data + LENGTH);
    std::deque<int> dData(data, data + LENGTH);

    std::cout << "Array sum: " << sum(data, data + LENGTH) << std::endl;
    std::cout << "Vector sum: " << sum(vData.begin(), vData.end()) << std::endl;
    std::cout << "List sum: " << sum(lData.begin(), lData.end()) << std::endl;  
    std::cout << "Deque sum: " << sum(dData.begin(), dData.end()) << std::endl;

    return 0;
}

