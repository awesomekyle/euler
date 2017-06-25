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
add_executable(20 20.cpp)
add_executable(21 21.cpp)
add_executable(22 22.cpp)
add_executable(23 23.cpp)
add_executable(24 24.cpp)
add_executable(25 25.cpp)
add_executable(26 26.cpp) # WIP
add_executable(27 27.cpp)
