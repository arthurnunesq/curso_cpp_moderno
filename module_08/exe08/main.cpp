#include <iostream>
#include <string>
#include <memory>
#include <vector>

struct A{};

// void e() {
// 	std::vector<std::unique_ptr<A>> v;
// 	std::unique_ptr<A> up(new A);
// 	v.push_back(up);
// 	v.clear();
// }

void f() {
	std::vector<std::unique_ptr<A>> v;
	std::unique_ptr<A> up(new A);
	v.push_back(std::move(up));
	v.clear();
}

void g() {
	std::vector<std::shared_ptr<A>> v;
	std::shared_ptr<A> up(new A);
	v.push_back(up);
	v.clear();
}

int main()
{
	f();
	g();


    return 0;
}

