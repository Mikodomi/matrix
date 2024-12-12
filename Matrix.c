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
Matrix init_matrix(int m, int n, const int numbers[m][n]) { // n - rows, m - columns
    Matrix mat;
    mat.columns = n;
    mat.rows = m;
    mat.values = (int**)malloc(m*sizeof(int*));
    if (mat.values == NULL) abort();
    for (int i = 0; i<m; i++) {
        mat.values[i] = (int*)malloc(n*sizeof(int));
        if (mat.values[i] == NULL) {
            for (int fix = 0; fix < i-1; fix++) {
                free(mat.values[fix]);
            }
            abort();
        }
        if (!numbers) {
            for (int j = 0; j<n; j++) {
                mat.values[i][j] = 0;
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
            printf("%6d", matrix.values[0][j]);
        }
        printf("]\n");
        return;
    }
    printf(TOPLEFT);
    for (int j = 0; j<matrix.columns; j++) {
        printf("%6d", matrix.values[0][j]);
    }
    printf(TOPRIGHT"\n");
    for (int i = 1; i<matrix.rows-1; i++) {
            printf(SIDE);
            for (int j = 0; j<matrix.columns; j++) {
                printf("%6d", matrix.values[i][j]);
            }
            printf(SIDE"\n");
    }
    printf(BOTTOMLEFT);
    for (int j = 0; j<matrix.columns; j++) {
        printf("%6d", matrix.values[matrix.rows-1][j]);
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
                int sum = 0;
                for (int cA = 0; cA<A.columns; cA++) {
                    sum += A.values[rA][cA]*B.values[cA][cB];
                }
                result.values[rA][cB] = sum;
            }
        }
    }
    return result;
}
