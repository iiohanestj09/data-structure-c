#include <stdio.h>

int main(){
    int x;

    x = 5;
    x = 10;

    int y = 0;

    printf("Nilai Variabel x \t: %d %d %f", x, y, y);
    printf("Address dari Variabel x(%%d): %d", &x);
    printf("Address dari Variabel x(%%p): %p", &x);
    
    return 0;
}