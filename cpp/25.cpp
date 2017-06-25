#include <iostream>
#include <set>
#include <unordered_set>
#include <sstream>

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

std::string fibonacci(std::string const& val1, std::string const& val2, uint64_t index)
{
    return add(val1, val2);
}

int main()
{
    std::string v1 = "1";
    std::string v2 = "1";
    std::string next;
    uint64_t index = 3;
    for (;;) {
        next = add(v1, v2);
        if (next.length() >= 1000) {
            break;
        }
        v1 = v2;
        v2 = next;
        index++;
    }
    std::cout << index << std::endl;

    return 0;
}
