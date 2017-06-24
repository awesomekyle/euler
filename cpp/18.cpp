#include <iostream>
#include <sstream>
#include <cstdint>
#include <vector>

int dig(char c)
{
    return c - '0';
}

int get_column(std::string const& s, int index)
{
    auto len = s.length();
    if (index < len) {
        char c = s[index];
        int result = dig(c);
        return result;
    }
    return 0;
}

std::string add(std::string const& a, std::string const& b)
{
    std::stringstream out;
    int carry = 0;
    int index = 0;
    for (;;) {
        if (index >= a.length() && index >= b.length() && carry == 0) {
            break;
        }
        int x = get_column(a, index);
        int y = get_column(b, index);
        int sum = x + y + carry;
        out << (sum % 10);
        carry = sum / 10;
        index++;
    }
    auto ret = out.str();
    std::reverse(ret.begin(), ret.end());
    return ret;
}
// std::string multiplication(std::string const& a, std::string const& b)
//{
//}

// uint64_t factorial(uint64_t val)
//{
//    if (val == 1) {
//        return 1;
//    }
//    return val * factorial(val - 1);
//}
//
// uint64_t digit_summer(uint64_t val)
//{
//    if (val == 0) {
//        return 0;
//    }
//    return (val % 10) + digit_summer(val / 10);
//}

int main()
{
    //    uint64_t const fac = factorial(100);
    //    std::cout << digit_summer(fac) << "\n";
    std::cout << add("1111111111111111111111111111111111111111111111",
                     "333333333333333333333333333333333333333333333333333333333");
    return 0;
}
