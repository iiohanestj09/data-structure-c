#include <stdio.h>
#include <stdlib.h>

int ***kaliMatriks(int **arrA, int **arrB){
    // alokasi memori untuk arrHasil
    int ***arrHasil = (int***) malloc(sizeof(int**));
    *arrHasil = (int**) malloc(2 * sizeof(int*));
    for(int i = 0; i < 2; i++){
        (*arrHasil)[i] = (int*) malloc(2 * sizeof(int));
    }

    // operasi perkalian arrA dan arrB
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            (*arrHasil)[i][j] = 0;
            for(int k = 0; k < 2; k++){
                (*arrHasil)[i][j] += arrA[i][k] * arrB[k][j]; 
            }
        }
    }

    return arrHasil;
}

int main(){
    int baris = 2, kolom = 2;

    // alokasi memori untuk baris matriks arrA dan arrB
    int **arrA = (int**) malloc(baris * sizeof(int*));
    int **arrB = (int**) malloc(baris * sizeof(int*));

    // alokasi memori untuk kolom di tiap baris matriks arrA dan arrB
    for(int i = 0; i < baris; i++){
        arrA[i] = (int*) malloc(kolom * sizeof(int));
        arrB[i] = (int*) malloc(kolom * sizeof(int));
    }

    // isi elemen di matriks arrA dengan kelipatan 3 dan matriks arrB dengan kelipatan 5
    printf("Matriks arrA:\n");
    int lipat3 = 3;
    for(int i = 0; i < baris; i++){
        for(int j = 0; j < kolom; j++){
            arrA[i][j] = lipat3;         
            lipat3 += 3;                // kelipatan 3
            printf("%-2d ", arrA[i][j]);
        }
        printf("\n");
    }

    printf("\nMatriks arrB:\n");
    int lipat5 = 5;
    for(int i = 0; i < baris; i++){
        for(int j = 0; j < kolom; j++){
            arrB[i][j] = lipat5;
            lipat5 += 5;                // kelipatan 5
            printf("%-2d ", arrB[i][j]);
        }
        printf("\n");
    }

    int ***arrC = kaliMatriks(arrA, arrB);
    printf("\nHasil Perkalian Matriks arrA x arrB:\n");
    for(int i = 0; i < baris; i++){
        for(int j = 0; j < kolom; j++){
            printf("%-2d ", (*arrC)[i][j]);
        }
        printf("\n");
    }

    // membebaskan memori yang dialokasikan pada matriks arrA dan arrB
    for(int i = 0; i < baris; i++){
        free(arrA[i]);
        free(arrB[i]);
        free((*arrC)[i]);
    }

    free(arrA);
    free(arrB);
    free(*arrC);
    free(arrC);

    return 0;
}