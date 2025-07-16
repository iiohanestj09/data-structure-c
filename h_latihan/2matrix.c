#include <stdio.h>
#include <stdlib.h>

int main() {
    int row, column;

    printf("Masukkan jumlah baris dan kolom Matrix (B K): ");
    scanf("%d %d", &row, &column);

    int** matrix = (int**) malloc(row * sizeof(int*));
    for (int i = 0; i < row; i++) {
        matrix[i] = (int*) malloc(column * sizeof(int));
    }

    for (int j = 0; j < row; ++j) {
        printf("[");
        for (int k = 0; k < column; ++k) {
            matrix[j][k] = (j == 0? 1 : j) * (k == 0? 1 : k);
            printf("%d", matrix[j][k]);
            if (k < column - 1) printf(" ");
        }
        printf("]\n");
    }

    for (int l = 0; l < row; ++l) {
        free(matrix[l]);
    }

    free(matrix);
}