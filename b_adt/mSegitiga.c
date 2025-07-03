#include <stdio.h>
#include "Segitiga.h"

int main(){
    Titik ta = buatTitik(0,5);
    Titik tb = buatTitik(7,7);
    Titik tc = buatTitik(15,2);

    Segitiga st = buatSegitiga(ta, tb, tc);
    
    cetakSegitiga(st);

    printf("\nKeliling Segitiga: %.2f\n", hitungKeliling(st));
    printf("Luas Segitiga: %.2f\n", hitungLuas(st));

    printf("\nSegitiga akan ditranslasikan dengan dx = -9 dan dy = -4 untuk setiap titik!\n");

    transSegitiga(&st, -9, -4);
    cetakSegitiga(st);
    
    return 0;
}