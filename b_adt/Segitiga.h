typedef struct titik{
    int x;
    int y;
} Titik;

typedef struct segitiga{
    Titik t1;
    Titik t2;
    Titik t3;
} Segitiga;

Titik buatTitik(int a, int b);

Segitiga buatSegitiga(Titik ta, Titik tb, Titik tc);

void cetakTitik(Titik t, char namaTitik);

void cetakSegitiga(Segitiga st);

float panjangSisi(Titik t1, Titik t2);

float hitungKeliling(Segitiga st);

float hitungLuas(Segitiga st);

void transTitik(Titik *t, int dx, int dy);

void transSegitiga(Segitiga *st, int dx, int dy);

