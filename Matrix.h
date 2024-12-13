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

// ELEMENTARY ROW OPERATIONS
void row_scalar(int row, double scalar,  Matrix* m1);
void column_scalar(int column, double scalar,  Matrix* m1);
void swap_rows(int r1, int r2, Matrix* m1);
void swap_columns(int c1, int c2, Matrix* m1);
void add_rows(int source, int dest, double scalar, Matrix* m1); // order is important
void add_columns(int source, int dest, double scalar, Matrix* m1);

// OPERATIONS ON MATRICES
Matrix multiply_matrices(Matrix m1, Matrix m2);
Matrix multiply_scalar(Matrix m1, double scalar);
Matrix add_matrices(Matrix m1, Matrix m2);
Matrix transpose(Matrix m1);
Matrix gauss_elim(Matrix m1);
double det(Matrix m1);

#endif
