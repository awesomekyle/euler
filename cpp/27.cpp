#include <iostream>
#include <set>
#include <unordered_set>
#include <map>
#include <sstream>

static bool is_prime(int64_t num)
{
    if (num <= 1) {
        return false;
    }

    if (num <= 3) {
        return true;
    }

    if (num % 2 == 0 || num % 3 == 0) {
        return false;
    }

    int64_t cmp = 5;
    while (cmp * cmp <= num) {
        if ((num % cmp == 0) || (num % (cmp + 2)) == 0) {
            return false;
        }
        cmp += 6;
    }

    return true;
}

static int64_t quadratic(int64_t const n, int64_t const a, int64_t const b)
{
    return (n * n) + a * n + b;
}

int main()
{
    int64_t a = 0;
    int64_t b = 0;
    int64_t n = 0;

    std::tuple<int64_t, int64_t, int64_t> max;

    for (b = 0; b <= 1000; ++b) {
        if (!is_prime(b)) {
            continue;
        }
        for (a = -999; a < 999; ++a) {
            n = 0;
            for (;;) {
                int64_t const val = quadratic(n, a, b);
                if (!is_prime(val)) {
                    break;
                }
                n++;
            }
            if (n > std::get<2>(max)) {
                max = std::make_tuple(a, b, n);
            }
        }
    }

    std::cout << std::get<0>(max) << std::endl;
    std::cout << std::get<1>(max) << std::endl;
    std::cout << std::get<0>(max) * std::get<1>(max) << std::endl;
    std::cout << std::get<2>(max) << std::endl;

    return 0;
}
