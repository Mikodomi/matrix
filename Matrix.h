#ifndef MATRIX_HEADER_H
#define MATRIX_HEADER_H

typedef struct matrix_t {
    int columns;
    int rows;
    int** values;
} Matrix;

Matrix init_matrix(int m, int n, const int numbers[m][n]); 
void print_matrix(Matrix matrix);
void free_matrix(Matrix* matrix);

// OPERATIONS
Matrix multiply_matrices(Matrix m1, Matrix m2);

#endif
