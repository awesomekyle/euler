project(euler)

add_library(large-number STATIC large-number/large-number.h
    large-number/large-number.cpp
)


add_executable(large-number-test
    large-number/large-number-test.cpp
)
add_custom_command(TARGET large-number-test
    POST_BUILD
    COMMAND $<TARGET_FILE:large-number-test>
)

add_executable(17 17.cpp)
add_executable(18 18.cpp)
