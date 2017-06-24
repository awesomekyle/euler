#include <iostream>
#include <set>
#include <unordered_set>

uint64_t sum_proper_divisors(uint64_t num)
{
    uint64_t sum = 0;
    for (uint64_t ii = num / 2; ii >= 1; --ii) {
        if (num % ii == 0) {
            sum += ii;
        }
    }
    return sum;
}

int main()
{
    std::vector<uint64_t> abundent_numbers;
    // Find all abundent numbers
    for (uint64_t ii = 0; ii <= 28123; ++ii) {
        uint64_t sum = sum_proper_divisors(ii);
        if (sum > ii) {
            abundent_numbers.push_back(ii);
        }
    }

    // Brute force the crap out of this
    std::unordered_set<uint64_t> sums;
    for (size_t ii = 0; ii < abundent_numbers.size(); ++ii) {
        for (size_t jj = ii; jj < abundent_numbers.size(); ++jj) {
            sums.insert(abundent_numbers[ii] + abundent_numbers[jj]);
        }
    }

    uint64_t sum = 0;
    for (uint64_t ii = 0; ii <= 28123; ++ii) {
        if (sums.count(ii) == 0) {
            sum += ii;
        }
    }

    std::cout << sum << std::endl;

    return 0;
}
