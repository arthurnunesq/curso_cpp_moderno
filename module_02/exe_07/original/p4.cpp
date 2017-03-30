#define SIZE 100

template<int size>
class MyArray{};

void f(){
	MyArray<SIZE> a;
}

int main(){
	f();
	return 0;
}
