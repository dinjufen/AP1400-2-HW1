
#include <iostream>
#include <gtest/gtest.h>
#include <fmt/core.h>
#include "hw1.h"

int main(int argc, char **argv)
{
    if (false) // make false to run unit-tests
    {
        // debug section
        fmt::print("fmt hello {}", "world");
        auto mat_zeros = algebra::zeros(4, 5);
        algebra::show(mat_zeros);
        auto mat_ones = algebra::ones(6, 9);
        algebra::show(mat_ones);
        auto mat_random = algebra::random(13, 16, 1.0, 100.0);
        algebra::show(mat_random);
    }
    else
    {
        ::testing::InitGoogleTest(&argc, argv);
        std::cout << "RUNNING TESTS ..." << std::endl;
        int ret{RUN_ALL_TESTS()};
        if (!ret)
            std::cout << "<<<SUCCESS>>>" << std::endl;
        else
            std::cout << "FAILED" << std::endl;
    }
    return 0;
}