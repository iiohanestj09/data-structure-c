#include <stdio.h>  // untuk fungsi standar input-output (printf, scanf)

// Ini buat mendefinisikan ukuran maksimum stack
#define MAX 5  

// Struktur Stack pakai array statis
typedef struct {
    int data[MAX];  // Array untuk menyimpan elemen stack
    int top;        // Indeks elemen teratas dalam stack
} Stack;

// Fungsi untuk inisialisasi stack
void initStack(Stack *s) {
    s->top = -1;  // Set top ke -1 biar stack kosong saat pertama kali dibuat
}

// Fungsi untuk memeriksa apakah stack kosong
int isEmpty(Stack *s) {
    return s->top == -1;  // Kalau top masih -1, berarti stack kosong
}

// Fungsi untuk memeriksa apakah stack penuh
int isFull(Stack *s) {
    return s->top == MAX - 1;  // Kalau top == MAX - 1, berarti stack penuh
}

// Fungsi untuk menambahkan elemen ke dalam stack (Push)
void push(Stack *s, int value) {
    if (isFull(s)) { // Cek apakah stack penuh sebelum push
        printf("Stack penuh, tidak bisa push %d!\n", value);
        return;  // Stop eksekusi biar tidak nambahin elemen di luar batas
    }

    s->top++;  // Geser top ke atas buat masukin elemen baru
    s->data[s->top] = value; // Simpan nilai di posisi top
    printf("Push: %d\n", value); // Kasih tahu elemen yang sudah dimasukkan
}

// Fungsi untuk menghapus elemen dari stack (Pop)
int pop(Stack *s) {
    if (isEmpty(s)) { // Cek dulu apakah stack kosong sebelum pop
        printf("Stack kosong, tidak bisa pop!\n");
        return -1;  // Balikin -1 kalau tidak ada elemen yang bisa di-pop
    }
    
    int poppedValue = s->data[s->top]; // Simpan elemen yang akan dihapus
    s->top--;  // Geser top ke bawah setelah pop
    return poppedValue; // Balikin elemen yang dihapus
}

// Fungsi untuk melihat elemen teratas stack tanpa menghapusnya (Peek)
int peek(Stack *s) {
    if (isEmpty(s)) { // Cek dulu apakah stack kosong
        printf("Stack kosong!\n");
        return -1; // Balikin -1 kalau tidak ada elemen di stack
    }
    return s->data[s->top]; // Balikin elemen yang ada di top
}

// Fungsi untuk menampilkan isi stack
void displayStack(Stack *s) {
    if (isEmpty(s)) { // Cek apakah stack kosong
        printf("Stack kosong!\n"); // Kalau kosong, kasih tahu
        return; // Stop biar gak lanjut eksekusi
    }
    
    printf("Isi Stack: "); // Kasih tahu kalau mau menampilkan stack
    for (int i = s->top; i >= 0; i--) { // Mulai dari elemen teratas ke bawah
        printf("%d ", s->data[i]); // Cetak elemen stack
    }
    printf("\n"); // Kasih baris baru setelah cetak semua elemen
}

// Fungsi utama
int main() {
    Stack s; // Deklarasikan variabel stack
    initStack(&s); // Inisialisasi stack

    push(&s, 10); // Masukin elemen 10 ke stack
    push(&s, 20); // Masukin elemen 20 ke stack
    push(&s, 30); // Masukin elemen 30 ke stack
    push(&s, 40); // Masukin elemen 40 ke stack
    push(&s, 50); // Masukin elemen 50 ke stack

    displayStack(&s); // Tampilkan isi stack setelah push

    push(&s, 60); // Coba push elemen tambahan, tapi stack udah penuh

    printf("Pop: %d\n", pop(&s)); // Hapus elemen teratas dari stack
    printf("Pop: %d\n", pop(&s)); // Hapus elemen berikutnya dari stack

    displayStack(&s); // Tampilkan isi stack setelah pop

    printf("Elemen teratas: %d\n", peek(&s)); // Lihat elemen teratas

    return 0; // Program selesai
}
