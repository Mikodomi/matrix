#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "Matrix.h"

#define TOPLEFT "\u250C"
#define TOPRIGHT "\u2510"
#define BOTTOMLEFT "\u2514"
#define BOTTOMRIGHT "\u2518"
#define SIDE "\u2502"

// MATRIX STRUCT FUNCTIONS

// preinitialized to an empty matrix
Matrix init_matrix(int m, int n, const double numbers[m][n]) { // n - rows, m - columns
    Matrix mat;
    mat.columns = n;
    mat.rows = m;
    mat.values = (double**)malloc(m*sizeof(double*));
    if (mat.values == NULL) abort();
    for (int i = 0; i<m; i++) {
        mat.values[i] = (double*)malloc(n*sizeof(double));
        if (mat.values[i] == NULL) {
            for (int fix = 0; fix < i-1; fix++) {
                free(mat.values[fix]);
            }
            abort();
        }
        if (!numbers) {
            for (int j = 0; j<n; j++) {
                mat.values[i][j] = 0.0;
            }
        } else {
            for (int j = 0; j<n; j++) {
                mat.values[i][j] = numbers[i][j];
            }
        }
    }
    return mat;
}

void print_matrix(Matrix matrix) {
    if (matrix.rows == 1) {
        printf("[");
        for (int j = 0; j<matrix.columns; j++) {
            printf("%8.2lf", matrix.values[0][j]);
        }
        printf("]\n");
        return;
    }
    printf(TOPLEFT);
    for (int j = 0; j<matrix.columns; j++) {
        printf("%8.2lf", matrix.values[0][j]);
    }
    printf(TOPRIGHT"\n");
    for (int i = 1; i<matrix.rows-1; i++) {
            printf(SIDE);
            for (int j = 0; j<matrix.columns; j++) {
                printf("%8.2lf", matrix.values[i][j]);
            }
            printf(SIDE"\n");
    }
    printf(BOTTOMLEFT);
    for (int j = 0; j<matrix.columns; j++) {
        printf("%8.2lf", matrix.values[matrix.rows-1][j]);
    }
    printf(BOTTOMRIGHT"\n");
}

void free_matrix(Matrix* matrix) {
    for (int i = 0; i<matrix->rows; i++) {
        free(matrix->values[i]);
    }
    free(matrix->values);
}

// OPERATIONS

Matrix multiply_matrices(Matrix A, Matrix B) {
    assert(A.columns == B.rows && "matrix A columns must be equal matrix B rows for multiplication");
    Matrix result = init_matrix(A.rows, B.columns, NULL);
    
    for (int rA = 0; rA<A.rows; rA++) {
        for (int cB = 0; cB<B.columns; cB++) {
            for (int rB = 0; rB<B.rows; rB++) {
                double sum = 0;
                for (int cA = 0; cA<A.columns; cA++) {
                    sum += A.values[rA][cA]*B.values[cA][cB];
                }
                result.values[rA][cB] = sum;
            }
        }
    }
    return result;
}

Matrix multiply_scalar(Matrix m1, double scalar) {
    for (int r = 0; r<m1.rows; r++) {
        for (int c = 0; c<m1.columns; c++) {
            m1.values[r][c] *= scalar;
        }
    }
    return m1;
}

Matrix add_matrices(Matrix m1, Matrix m2) {
    assert((m1.rows == m2.rows && m1.columns == m2.columns) && "Matrices must be of equal dimensions to be added");
    for (int r = 0; r<m1.rows; r++) {
        for (int c = 0; c<m1.columns; c++) {
            m2.values[r][c] += m1.values[r][c];
        }
    }
    return m2;
}

Matrix transpose(Matrix m1) {
    Matrix transposed = init_matrix(m1.columns, m1.rows, NULL);
    for (int r = 0; r<m1.rows; r++) {
        for (int c = 0; c<m1.columns; c++) {
            transposed.values[c][r] = m1.values[r][c];
        }
    }
    return transposed;
}
