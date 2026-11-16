add_executable(g2d1_test
    g2d1_test.cpp
)

target_link_libraries(g2d1_test
    PRIVATE
        g2d1::g2d1
)

add_test(
    NAME g2d1_test
    COMMAND g2d1_test
)
