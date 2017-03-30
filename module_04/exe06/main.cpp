#include <iostream>
#include <string>
#include <regex>

int main()
{
    std::string s = R"(leandro\"BR"\31-99990000)";

    std::regex conventional_regex("leandro\\\\\"BR\"\\\\31-99990000");
    if (std::regex_search(s, conventional_regex)) {
        std::cout << "Match found with conventional string.\n";
    }

    std::regex raw_regex(R"(leandro\\"BR"\\31-99990000)");
    if (std::regex_search(s, raw_regex)) {
        std::cout << "Match found with raw string.\n";
    }

    return 0;
}
