add_executable(Lists
        TestDumbExample.c
)

target_link_libraries(Lists
        DumbExample_lib
        Unity
)

add_test(NAME DumbExample_test COMMAND Lists)