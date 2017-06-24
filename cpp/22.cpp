#include <iostream>
#include <set>

std::set<std::string> const kNames = {
#include "p022_names.txt"
};

uint64_t string_value(std::string const& s)
{
    uint64_t sum = 0;
    for (char c : s) {
        sum += (c - 'A') + 1;
    }
    return sum;
}

int main()
{
    uint64_t sum = 0;
    size_t ii = 1;
    for (auto const& n : kNames) {
        sum += ii * string_value(n);
        ++ii;
    }
    std::cout << sum << std::endl;
    return 0;
}
