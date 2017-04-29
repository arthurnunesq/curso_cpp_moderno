#include <iostream>
#include <string>
#include <memory>

// http://stackoverflow.com/questions/17902405/how-to-implement-make-unique-function-in-c11
// http://stackoverflow.com/questions/7038357/make-unique-and-perfect-forwarding
// https://herbsutter.com/gotw/_102/
// http://stackoverflow.com/questions/27594731/what-are-the-6-dots-in-template-parameter-packs
template<typename T, typename... Args>
std::unique_ptr<T> make_unique(Args&&... args)
{
    return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}

int main()
{
	auto ptr = make_unique<std::string>("Hello world");

    return 0;
}

