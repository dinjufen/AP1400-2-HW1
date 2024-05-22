#include "hw1.h"
#include <random>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <stdexcept>
#include <numeric>

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

    Matrix multiply(const Matrix& matrix1, const Matrix& matrix2) {
        if (matrix1.empty() && matrix2.empty()) {
            return {};
        }
        if (matrix1[0].size() != matrix2.size()) {
            throw std::logic_error("matrix1'column not equal to matrix2's row");
        }
        const auto n = matrix1.size();
        const auto m = matrix2[0].size();
        const auto len = matrix1[0].size();
        Matrix _mat;
        for (size_t i = 0;i < n;i++) {
            std::vector<double> row(m);
            for (size_t j = 0;j < m;j++) {
                double sum = 0;
                for (size_t k = 0;k < len;k++) {
                    sum += matrix1[i][k] * matrix2[k][j];
                }
                row[j] = sum;
            }
            _mat.push_back(std::move(row));
        }
        return _mat;
    }

    Matrix sum(const Matrix& matrix, double c) {
        if (matrix.empty() || matrix[0].empty()) {
            return {};
        }
        Matrix _mat;
        for (const auto& row : matrix) {
            std::vector<double> new_row;
            std::transform(row.begin(), row.end(), std::back_inserter(new_row), [c] (double item) { return item + c; });
            _mat.push_back(std::move(new_row));
        }
        return _mat;
    }

    Matrix sum(const Matrix& matrix1, const Matrix& matrix2) {
        if (matrix1.empty() && matrix2.empty()) {
            return {};
        }
        if (matrix1.size() != matrix2.size()) {
            throw std::logic_error("count of rows not equal!");
        }
        if (matrix1[0].size() != matrix2[0].size()) {
            throw std::logic_error("count of columns not equal!");
        }
        Matrix _mat;
        for (size_t i = 0;i < matrix1.size();i++) {
            Row new_row(matrix1[0].size());
            std::transform(matrix1[i].begin(), matrix1[i].end(), matrix2[i].begin(), new_row.begin(), std::plus<>());
            _mat.push_back(std::move(new_row));
        }
        return _mat;
    }

    Matrix transpose(const Matrix& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return {};
        }
        auto n = matrix.size();
        auto m = matrix[0].size();
        Matrix _mat;
        for (auto i = 0;i < m;i++) {
            Row row;
            for (auto j = 0;j < n;j++) {
                row.push_back(matrix[j][i]);
            }
            _mat.push_back(std::move(row));
        }
        return _mat;
    }

    Matrix minor(const Matrix& matrix, size_t n, size_t m) {
        if (matrix.empty() || matrix[0].empty() || n >= matrix.size() || m >= matrix[0].size()) {
            return matrix;
        }
        Matrix _mat;
        for (size_t i = 0;i < matrix.size();i++) {
            if (i == n) continue;
            Row row;
            for (size_t j = 0;j < matrix.size();j++) {
                if (j != m) {
                    row.push_back(matrix[i][j]);
                }
            }
            _mat.push_back(std::move(row));
        }
        return _mat;
    }

    double determinant(const Matrix& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return 1;
        }
        if (matrix.size() != matrix[0].size()) {
            throw std::logic_error("row != column");
        }
        if (matrix.size() == 2) {
            return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
        }
        // 以第一行展开
        // TODO 递归如何优化？
        double sum = 0;
        for (size_t i = 0;i < matrix[0].size();i++) {
            double symbol = i % 2 ? -1.0 : 1.0;
            const auto& minorMat = minor(matrix, 0, i);
            sum += symbol * matrix[0][i] * determinant(minorMat);
        }
        return sum;
    }
}