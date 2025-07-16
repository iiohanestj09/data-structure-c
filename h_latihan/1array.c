#include <stdio.h>
#include <stdlib.h>

int main() {
    int size;
    printf("Masukkan Ukuran Array: ");
    scanf("%d", &size);

    int* arr = (int*) malloc(size * sizeof(int));
    
    printf("[");
    for(int i = 0; i < size; i++) {
        arr[i] = i * 2;
        printf("%d ", arr[i]);
    }
    printf("]");

    free(arr);
}