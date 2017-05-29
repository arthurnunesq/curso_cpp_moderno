#include <memory>
#include <vector>

template <class T>
struct PoolAlloc
{
    typedef T value_type;

    T* allocate(size_t n){
        void* p = malloc(n);
        return static_cast<T*>(p);
    }

    void deallocate(T* p, size_t){
        free(p);
    }

};

int main()
{
    std::vector<int, PoolAlloc<int>> v;

    return 0;
}

