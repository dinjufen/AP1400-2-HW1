#include "hw1.h"
#include <random>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <stdexcept>

static double genRandomDouble(double min, double max) {
    if (min > max) {
        throw std::logic_error("genRandomDouble min > max!");
    }
    static std::random_device randomDevice;
    static std::default_random_engine engine(randomDevice());
    std::uniform_real_distribution<double> dis(min, max);
    return dis(engine);
}

namespace algebra {
    Matrix zeros(size_t n, size_t m) {
        Matrix _mat(n, std::vector<double>(m, 0));
        return _mat;
    }

    Matrix ones(size_t n, size_t m) {
        Matrix _mat(n, std::vector<double>(m, 1.0));
        return _mat;
    }

    Matrix random(size_t n, size_t m, double min, double max) {
        Matrix _mat(n, std::vector<double>(m));
        for (auto& row : _mat) {
            std::generate(row.begin(), row.end(), [min, max](){ return genRandomDouble(min, max); });
        }
        return _mat;
    }

    void show(const Matrix& matrix) {
//        double _max = -std::numeric_limits<double>::max();
//        for (const auto& row : matrix) {
//            double row_max = *std::max_element(row.begin(), row.end());
//            if (_max < row_max) {
//                _max = row_max;
//            }
//        }
        std::cout << "\n";
        for (const auto& row : matrix) {
            for (const auto& item : row) {
                std::cout << std::setw(8) << std::setiosflags(std::ios::left) << std::fixed << std::setprecision(3) << item << " ";
            }
            std::cout << "\n";
        }
        std::cout << std::endl;
    }

    Matrix multiply(const Matrix& matrix, double c) {
        const auto n = matrix.size();
        if (n == 0) {
            return {};
        }
        const auto m = matrix[0].size();
        if (m == 0) {
            return {};
        }
        if (c == 0) {
            return zeros(n, m);
        }
        Matrix _mat;
        for (const auto& row : matrix) {
            std::vector<double> new_row;
            std::transform(row.begin(), row.end(), std::back_inserter(new_row), [c](double number) { return number * c; });
            _mat.push_back(new_row);
        }
        return _mat;
    }
}