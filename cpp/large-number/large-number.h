#pragma once
#include <vector>

class LargeNumber
{
   public:
    LargeNumber(uint64_t val) { _value = {val}; }

    LargeNumber operator+(LargeNumber const& b) const { return _value[0] + b._value[0]; }
    bool operator==(LargeNumber const& b) const { return _value[0] == b._value[0]; }
    bool operator==(uint64_t b) const { return _value[0] == b; }

   private:
    std::vector<uint64_t> _value;
};

bool operator==(uint64_t a, LargeNumber const& b)
{
    return b == a;
}
