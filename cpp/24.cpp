#include <iostream>
#include <set>
#include <unordered_set>

uint64_t power(uint64_t a, uint64_t b)
{
    if (b == 0) {
        return 1;
    }
    if (b == 1) {
        return a;
    }
    return a * power(a, b - 1);
}

void permutation(std::set<uint64_t>* all_permutations, std::set<uint64_t> const& vals,
                 uint64_t currSum)
{
    if (vals.size() == 1) {
        all_permutations->insert(*vals.begin() + currSum);
        return;
    }
    uint64_t const currMagnitude = power(10, vals.size() - 1);
    for (auto const v : vals) {
        auto newVals = vals;
        newVals.erase(v);
        permutation(all_permutations, newVals, currSum + (v * currMagnitude));
    }
}

int main()
{
    std::set<uint64_t> permutations;

    std::set<uint64_t> const values = {
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
    };

    permutation(&permutations, values, 0);

    size_t index = 0;
    for (auto const v : permutations) {
        ++index;
        if (index == 1000000) {
            std::cout << v << std::endl;
            break;
        }
    }

    return 0;
}
