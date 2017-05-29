#include <iostream>
#include <string>
#include <map>
#include <unordered_map>

struct Person{
	std::string name_;
	int age_;

	Person(std::string name, int age)
	: name_(name), age_(age)
	{}
};

struct ComparePerson {
	bool operator() (const std::string& a, const std::string& b) const {
		return a.length() < b.length();
	}
};

int main()
{
	std::map<std::string, Person, ComparePerson> map;
	map.emplace("Arthur", Person("Arthur", 26));

	std::unordered_map<std::string, Person> umap;
	umap.emplace("Arthur", Person("Arthur", 26));

    return 0;
}


