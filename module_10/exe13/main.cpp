#include <iostream>
#include <string>
#include <regex>

int main()
{
    std::regex r(R"(<(.*)>.*</\1>)");
    std::string s = "tag <foo> 123 </foo> gat";
    std::smatch match;
    bool ok = std::regex_search(s, match, r);

    for(auto m : match){
        std::cout << "match = " << m << '\n';
    }

    return 0;
}
