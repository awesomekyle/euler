#include <iostream>
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
    std::unordered_set<uint64_t> not_amicable;
    std::unordered_set<uint64_t> amicable_numbers;

    for (uint64_t ii = 2; ii < 10000; ++ii) {
        if (amicable_numbers.count(ii) || not_amicable.count(ii)) {
            continue;
        }
        uint64_t sum = sum_proper_divisors(ii);
        if (sum == 1) {
            continue;
        }
        if (sum == ii) {
            continue;
        }

        uint64_t d = sum_proper_divisors(sum);
        if (d == ii) {
            amicable_numbers.insert(ii);
            amicable_numbers.insert(sum);
        } else {
            not_amicable.insert(ii);
            not_amicable.insert(sum);
        }
    }

    uint64_t sum = 0;
    for (auto const& n : amicable_numbers) {
        sum += n;
    }
    std::cout << sum << std::endl;
    return 0;
}
