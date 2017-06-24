#include <stdio.h>
#include <sstream>

namespace {

char const* one_to_ten[] = {
    "", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten",
};
char const* eleven_to_nineteen[] = {
    "eleven",  "twelve",    "thirteen", "fourteen", "fifteen",
    "sixteen", "seventeen", "eighteen", "nineteen",
};
char const* tens[] = {
    "", "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety",
};

}  // namespace

int main()
{
    std::stringstream str;
    for (int ii = 1; ii < 1000; ++ii) {
        int hundreds = ii / 100;
        if (hundreds) {
            str << one_to_ten[hundreds] << "hundred";
            if (ii % 100 != 0) {
                str << "and";
            } else {
                continue;
            }
        }

        if ((ii % 100) <= 10) {
            str << one_to_ten[(ii % 100)];
        } else if ((ii % 100) <= 19) {
            str << eleven_to_nineteen[(ii % 100) - 11];
        } else {
            str << tens[(ii % 100) / 10];
            str << one_to_ten[ii % 10];
        }
    }
    str << "onethousand";
    printf("%zu\n", str.str().length());
    return 0;
}
