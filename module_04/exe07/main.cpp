#include <iostream>
#include <string>

#include <codecvt>   // for codecvt_utf8
#include <locale>    // for wstring_convert

int main()
{
    std::string s_u8 = u8"ol\u00E1";
    std::u16string s_u16 = u"ol\u00E1";
    std::u32string s_u32 = U"ol\u00E1";

    std::cout << "UTF-8: " << s_u8 << "\n";

    std::wstring_convert<std::codecvt_utf8<char16_t>, char16_t> cv_u16;
    std::cout << "UTF-16: " << cv_u16.to_bytes(s_u16) << "\n";

    std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t> cv_u32;
    std::cout << "UTF-32: " << cv_u32.to_bytes(s_u32) << "\n";

    return 0;
}

