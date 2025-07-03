#include <stdio.h>

int main(){
    int x = 10;

    int *ptrX = &x;

    printf("Nilai yang ditunjuk oleh ptrX    : %p", ptrX);
    printf("Nilai yang ditunjuk oleh *ptrX   : %d", *ptrX);
    printf("Nilai yang ditunjuk oleh Addres x: %d", *(&x));

    return 0;
}