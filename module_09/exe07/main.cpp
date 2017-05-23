#include <iostream>
#include <string>

class Type {
public:
	Type() {
		std::cout << "Type: Default constructor\n";
	}
	Type& operator=(Type&& t){
		std::cout << "Type: Transfer assignement\n";
		return *this;
	}
	Type(const Type&){
		std::cout << "Type: Copy constructor\n";
	}
};

template <class T>
class Stack{
private:
	T* p_;
	size_t size_;
	size_t used_;
public:
	void push(const T &v) {
		Stack<T> temp = *this;

		if (temp.used_ - temp.size_) {
			size_t size = temp.size_ * 2;
			T* p = new T[size];
			try{
				std::copy(temp.p_, temp.p_ + temp.size_, p);
			} catch (...) {
				delete[] p;
				throw;
			}

			delete[] temp.p_;
			temp.p_ = p;
			temp.size_ = size;
		}

		temp.p_[used_ - 1] = v;
		++temp.used_;

		std::swap(this, temp);
	}
};

int main()
{
	Stack<int> stack;

    return 0;
}

