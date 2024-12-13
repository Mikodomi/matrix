#ifndef MATRIX_HEADER_H
#define MATRIX_HEADER_H

typedef struct matrix_t {
    int columns;
    int rows;
    double** values;
} Matrix;

Matrix init_matrix(int m, int n, const double numbers[m][n]); 
void print_matrix(Matrix matrix);
void free_matrix(Matrix* matrix);

// OPERATIONS
Matrix multiply_matrices(Matrix m1, Matrix m2);
Matrix multiply_scalar(Matrix m1, double scalar);

#endif
