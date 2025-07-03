#include <stdio.h>
#include <stdlib.h>

int main(){
    int arrBiasa[10];

    int *arr, size;

    printf("Masukkan Size: ");
    scanf("%d", &size);

    arr = (int*) malloc(size * sizeof(int));
    
    for(int i = 0; i < size; i++){
        *(arr + i) = i * 2;
    }

    for(int i = 0; i < size; i++){
        printf("%d ", *(arr + i));
        printf("%p\n", (arr + i));
    }

    free(arr);

    return 0;
}