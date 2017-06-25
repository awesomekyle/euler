#include <iostream>
#include <set>
#include <unordered_set>
#include <map>
#include <sstream>

int longest_repeating_pattern(std::string const& s)
{
    std::map<std::string, size_t> substrings;
    auto const max_len = (s.size() - 2) / 2 + 3;
    for (size_t start = 2; start < max_len; ++start) {
        for (size_t len = 1; len < max_len; ++len) {
            std::string sub = s.substr(start, len);

            // now find occurrences of the string
            for (size_t ii = start + 1; ii < s.size(); ++ii) {
                if (s.substr(ii, sub.size()) == sub) {
                    substrings[sub]++;
                }
            }
        }
    }

    int max = 0;
    for (auto const& p : substrings) {
        if (p.second > max) {
            max = p.second;
        }
    }
    return max;
}

void trim(std::string* s)
{
    while (*(s->end() - 1) == '0') {
        s->erase(s->end() - 1);
    }
}

int main()
{
    std::map<int, int> longest_recurring;
    for (int ii = 2; ii <= 1000; ++ii) {
        double val = 1.0 / ii;
        std::string strv = std::to_string(val);  // TODO: Do long division :(
        trim(&strv);
        longest_recurring[ii] = longest_repeating_pattern(strv);
    }

    return 0;
}
