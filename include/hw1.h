#ifndef AP_HW1_H
#define AP_HW1_H

#include <vector>
using Row = std::vector<double>;
using Matrix = std::vector<Row>;

namespace algebra {

    // zeros implement this function so that it will create a n x m matrix with all elements equal to zero.
    Matrix zeros(size_t n, size_t m);

    // ones implement this function so that it will create a n x m matrix with all elements equal to one.
    Matrix ones(size_t n, size_t m);

    // random implement this function so that it will create a n x m matrix with all elements a random number between min and max
    Matrix random(size_t n, size_t m, double min, double max);

    // show implement this function so that it will display the matrix in a beautiful way.
    void show(const Matrix& matrix);

    // implement this function so that it multiplies the matrix into the constant scalar c.
    Matrix multiply(const Matrix& matrix, double c);

    // implement this function so that it multiplies the matrix1 into matrix2. (this is not an element-wise multiplication)
    Matrix multiply(const Matrix& matrix1, const Matrix& matrix2);

    // implement this function so that it adds the constant number c to every element of matrix.
    Matrix sum(const Matrix& matrix, double c);

    // implement this function so that it adds 2 matrices to each other.
    Matrix sum(const Matrix& matrix1, const Matrix& matrix2);

    // transpose implement this function so that it will generate the transpose matrix of the input matrix.
    // 转置
    Matrix transpose(const Matrix& matrix);

    // minor implement this function so that it will create the minor of the input matrix with respect to nth row and mth column.
    // 余子式: 在n阶行列式中，把所在的第i行与第j列划去后，所留下来的n-1阶行列式叫元的余子式。
    Matrix minor(const Matrix& matrix, size_t n, size_t m);

    // determinant implement this function so that it calculates the determinant of the input matrix.
    // 行列式
    double determinant(const Matrix& matrix);

    // inverse implement this function so that it generates the matrix's inverse.
    // 矩阵的逆
    Matrix inverse(const Matrix& matrix);

    // concatenate implement this function so that it will concatenate matrix1 and matrix2 along the specified axis. (axis=0: on top of each other | axis=1: alongside each other).
    // 矩阵拼接 axis = 0: 往下拼接，增加行; axis = 1: 往右拼接，增加列
    Matrix concatenate(const Matrix& matrix1, const Matrix& matrix2, int axis = 0);

    // row变换1：将第r1行与第r2行交换
    Matrix ero_swap(const Matrix& matrix, size_t r1, size_t r2);

    // multiply multiplies every element in rth row with constant number c.
    Matrix ero_multiply(const Matrix& matrix, size_t r, double c);

    // sum adds   r1th x c   into r2th row.
    Matrix ero_sum(const Matrix& matrix, size_t r1, double c, size_t r2);
}

#endif //AP_HW1_H
