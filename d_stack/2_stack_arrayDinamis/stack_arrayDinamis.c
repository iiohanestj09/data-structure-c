#include <stdio.h>   // untuk pustaka standar input-output (fungsi printf dan scanf)
#include <stdlib.h>  // untuk pustaka standar manajemen memori (malloc dan realloc)

// ini untuk mendefinisikan struktur Stack pada Array Dinamis
typedef struct {
    int *data;      // pointer ke array dinamis untuk menyimpan elemen stack
    int top;        // indeks elemen teratas dalam stack
    int capacity;   // kapasitas maksimum saat ini dari stack
} Stack;

// Fungsi untuk inisialisasi stack dengan kapasitas tertentu
void initStack(Stack *s, int size) {
    s->data = (int*) malloc(size * sizeof(int)); // alokasi memori sesuai kapasitas awal
    s->top = -1;    // set top ke -1 biar stack awalnya kosong
    s->capacity = size; // simpan kapasitas awal stack
}

// Fungsi untuk memeriksa apakah stack kosong
int isEmpty(Stack *s) {
    return s->top == -1;  // kalau top masih -1, berarti stack kosong
}

// Fungsi untuk menambahkan elemen ke dalam stack (Push)
void push(Stack *s, int value) {
    if (s->top == s->capacity - 1) {  // cek apakah stack penuh
        s->capacity *= 2;  // kalau penuh, kapasitasnya digandakan
        s->data = (int*) realloc(s->data, s->capacity * sizeof(int)); // alokasi ulang memori dengan kapasitas baru
        printf("Ukuran stack bertambah menjadi %d\n", s->capacity); // kasih tahu kalau ukuran stack bertambah
    }

    s->top++;  // geser top ke atas buat masukin elemen baru
    s->data[s->top] = value; // simpan nilai di posisi top
    printf("Push: %d\n", value); // kasih tahu elemen yang sudah dimasukkan
}

// Fungsi untuk menghapus elemen dari stack (Pop)
int pop(Stack *s) {
    if (isEmpty(s)) { // cek dulu apakah stack kosong
        printf("Stack kosong, tidak bisa pop!\n"); // kasih pesan kalau kosong
        return -1; // balikin -1 kalau tidak ada elemen yang bisa di-pop
    }
    
    int poppedValue = s->data[s->top]; // simpan elemen yang akan dihapus
    s->top--;  // geser top ke bawah setelah pop
    return poppedValue; // balikin elemen yang dihapus
}

// Fungsi untuk melihat elemen teratas stack tanpa menghapusnya (Peek)
int peek(Stack *s) {
    if (isEmpty(s)) { // cek dulu apakah stack kosong
        printf("Stack kosong!\n"); // kasih tahu kalau stack kosong
        return -1; // balikin -1 kalau tidak ada elemen di stack
    }
    return s->data[s->top]; // balikin elemen yang ada di top
}

// Fungsi untuk menampilkan isi stack
void displayStack(Stack *s) {
    if (isEmpty(s)) { // cek apakah stack kosong
        printf("Stack kosong!\n"); // kalau kosong, kasih tahu
        return; // stop biar gak lanjut eksekusi
    }
    
    printf("Isi Stack: "); // kasih tahu kalau mau menampilkan stack
    for (int i = s->top; i >= 0; i--) { // mulai dari elemen teratas ke bawah
        printf("%d ", s->data[i]); // cetak elemen stack
    }
    printf("\n"); // kasih baris baru setelah cetak semua elemen
}

// Fungsi utama
int main() {
    Stack s; // deklarasikan variabel stack
    initStack(&s, 5); // inisialisasi stack dengan kapasitas awal 5

    push(&s, 10); // masukin elemen 10 ke stack
    push(&s, 20); // masukin elemen 20 ke stack
    push(&s, 30); // masukin elemen 30 ke stack
    push(&s, 40); // masukin elemen 40 ke stack
    push(&s, 50); // masukin elemen 50 ke stack

    displayStack(&s); // tampilkan isi stack setelah push

    push(&s, 60); // masukin elemen 60 ke stack, ini bakal memperbesar ukuran stack karena sudah penuh

    printf("Pop: %d\n", pop(&s)); // hapus elemen teratas dari stack
    printf("Pop: %d\n", pop(&s)); // hapus elemen berikutnya dari stack

    displayStack(&s); // tampilkan isi stack setelah pop

    printf("Elemen teratas: %d\n", peek(&s)); // lihat elemen teratas

    return 0; // program selesai
}
