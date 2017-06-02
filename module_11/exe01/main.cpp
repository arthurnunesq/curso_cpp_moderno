#include <iostream>
#include <vector>

#include <algorithm>
#include <future>

// https://stackoverflow.com/a/28682886/702828
template <class RandomIt>
void quicksort(RandomIt b, RandomIt e) {
	size_t d = std::distance(b, e);

    if (d > 2) {
    	auto mid_value = *(b + d/2);

    	RandomIt pivot = b + (d)/2;

	    std::iter_swap(pivot, e-1); // save pivot.
	    pivot = std::partition(b, e-1,  [e] (const typename RandomIt::value_type& x) { return x < *(e-1); });
	    std::iter_swap(pivot, e-1); // restore pivot.

        quicksort(b, pivot);
        quicksort(pivot+1, e);
    }
}

template <class RandomIt>
void par_quicksort(RandomIt b, RandomIt e) {
	size_t d = std::distance(b, e);

    if (d > 2) {
    	auto mid_value = *(b + d/2);

    	RandomIt pivot = b + (d)/2;

	    std::iter_swap(pivot, e-1); // save pivot.
	    pivot = std::partition(b, e-1,  [e] (const typename RandomIt::value_type& x) { return x < *(e-1); });
	    std::iter_swap(pivot, e-1); // restore pivot.

        auto t1 = std::async([b, pivot] () { par_quicksort(b, pivot); } );
        auto t2 = std::async([e, pivot] () { par_quicksort(pivot+1, e); } );

        t1.get();
        t2.get();
    }
}

template< class ForwardIteratorType >
void print_it( ForwardIteratorType begin, ForwardIteratorType end ){
    while(begin != end)
    {
    	std::cout << *(begin) << "\t";
        ++begin;
    }
}

int main()
{
    std::vector<int> vData = { 5, 7, 8, 9, 1, 2 };

    par_quicksort(vData.begin(), vData.end());
    std::cout << "Sorted vector: \t"; print_it(vData.begin(), vData.end()); std::cout << std::endl;

    return 0;
}
