#include <stdlib.h>
#include <stdio.h>
#include "Matrix.h"

#define TOPLEFT "\u250C"
#define TOPRIGHT "\u2510"
#define BOTTOMLEFT "\u2514"
#define BOTTOMRIGHT "\u2518"
#define SIDE "\u2502"
Error init_matrix(int m, int n, Matrix* mat) { // n - rows, m - columns
    mat->columns = n;
    mat->rows = m;
    mat->values = (int**)malloc(m*sizeof(int*));
    if (mat->values == NULL) return BAD_MALLOC;
    for (int i = 0; i<m; i++) {
        mat->values[i] = (int*)malloc(n*sizeof(int));
        if (mat->values[i] == NULL) {
            for (int fix = 0; fix < i-1; fix++) {
                free(mat->values[fix]);
            }
            return BAD_MALLOC;
        }
        for (int j = 0; j<n; j++) {
            printf("Awaiting input for: [%d][%d]:", i, j);
            scanf("%d", &mat->values[i][j]); // forgive this atrocious input... this is an academic program
        }
    }
    
    return SUCCESS;
}

void print_matrix(Matrix matrix) {
    if (matrix.rows == 1) {
        printf("[");
        for (int j = 0; j<matrix.columns; j++) {
            printf("%d", matrix.values[0][j]);
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
    for (int i = 0; i<matrix->columns; i++) {
        free(matrix->values[i]);
    }
    free(matrix->values);
}
