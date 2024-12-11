#ifndef MATRIX_HEADER_H
#define MATRIX_HEADER_H

typedef struct matrix_t {
    int columns;
    int rows;
    int** values;
} Matrix;

typedef enum error_e {
    BAD_MALLOC,
    SUCCESS,
} Error;


Error init_matrix(int m, int n, Matrix* mat); 
void print_matrix(Matrix matrix);
void free_matrix(Matrix* matrix);
Matrix multiply_matrices(Matrix m1, Matrix m2);
int classical_det(Matrix matrix);
int gauss_det(Matrix matrix);

#endif
