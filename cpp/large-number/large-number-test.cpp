#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "large-number.h"

SCENARIO("basic numbers are supported")
{
    GIVEN("small large numbers")
    {
        LargeNumber a = 16;
        LargeNumber b = 64;

        THEN("basic math operations can be performed") { REQUIRE(80 == a + b); }
    }
}
