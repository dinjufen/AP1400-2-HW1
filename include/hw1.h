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
    Matrix transpose(const Matrix& matrix);

    // minor implement this function so that it will create the minor of the input matrix with respect to nth row and mth column.
    // 在n阶行列式中，把所在的第i行与第j列划去后，所留下来的n-1阶行列式叫元的余子式。
    Matrix minor(const Matrix& matrix, size_t n, size_t m);

    // determinant implement this function so that it calculates the determinant of the input matrix.
    double determinant(const Matrix& matrix);
}

#endif //AP_HW1_H
