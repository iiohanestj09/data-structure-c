#include <stdio.h>
#include <math.h>
#include "Segitiga.h"

Titik buatTitik(int a, int b){
    Titik t;
    t.x = a;
    t.y = b;
    return t;
}

Segitiga buatSegitiga(Titik ta, Titik tb, Titik tc){
    Segitiga st;
    st.t1 = ta;
    st.t2 = tb;
    st.t3 = tc;
    return st;
}

void cetakTitik(Titik t, char namaTitik){
    printf("Titik t%c: (%2d, %2d)\n", namaTitik, t.x, t.y);
}

void cetakSegitiga(Segitiga st){
    printf("Tiga titik yang membentuk Segitiga, yaitu\n");
    cetakTitik(st.t1, 'a');
    cetakTitik(st.t2, 'b');
    cetakTitik(st.t3, 'c');
}

float panjangSisi(Titik t1, Titik t2){
    return sqrt(pow(t2.x - t1.x, 2) + pow(t2.y - t1.y, 2));
}

float hitungKeliling(Segitiga st){
    float ab = panjangSisi(st.t1, st.t2);
    float bc = panjangSisi(st.t2, st.t3);
    float ca = panjangSisi(st.t3, st.t1);
    return ab + bc + ca;
}

float hitungLuas(Segitiga st){
    float ab = panjangSisi(st.t1, st.t2);
    float bc = panjangSisi(st.t2, st.t3);
    float ca = panjangSisi(st.t3, st.t1);
    float s = (ab + bc + ca) / 2;
    return sqrt(s * (s - ab) * (s - bc) * (s - ca));
}

void transTitik(Titik *t, int dx, int dy){
    t -> x += dx;
    t -> y += dy;
}

void transSegitiga(Segitiga *st, int dx, int dy){
    transTitik(&(st -> t1), dx, dy);
    transTitik(&(st -> t2), dx, dy);
    transTitik(&(st -> t3), dx, dy);
}
