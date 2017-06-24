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
        int const x = get_column(a, (a.length() - 1) - index);
        int const y = get_column(b, (b.length() - 1) - index);
        int const sum = x + y + carry;
        out << (sum % 10);
        carry = sum / 10;
        index++;
    }
    auto ret = out.str();
    std::reverse(ret.begin(), ret.end());
    return ret;
}

std::string multiplication(std::string const& a, std::string const& b)
{
    std::string out;
    for (auto c0 = b.rbegin(); c0 != b.rend(); ++c0) {
        int const x = dig(*c0);
        std::string tmp;
        int col = 1;
        for (auto c1 = a.rbegin(); c1 != a.rend(); ++c1) {
            int const y = dig(*c1);
            tmp = add(tmp, std::to_string(y * x * col));
            col *= 10;
        }
        int const trailing_zeros = c0 - b.rbegin();
        tmp.insert(tmp.end(), trailing_zeros, '0');
        out = add(out, tmp);
    }
    return out;
}

std::string factorial(std::string const& val, std::string const& max)
{
    if (val == max) {
        return max;
    }
    return multiplication(val, factorial(add(val, "1"), max));
}
uint64_t digit_summer(std::string const& val)
{
    uint64_t sum = 0;
    for (auto const c : val) {
        sum += dig(c);
    }
    return sum;
}

int main()
{
    std::string const fac = factorial("1", "100");
    std::cout << digit_summer(fac) << "\n";
    return 0;
}
