//QUEUE ADT PADA ARRAY DINAMIS//

#include <stdio.h>   // untuk pustaka standar input-output untuk fungsi seperti printf dan scanf (kek biasa lah ya)
#include <stdlib.h>  // untuk pustaka standar untuk fungsi manajemen memori seperti malloc dan realloc

// ini untuk Definisikan struktur Queue nya
typedef struct {
    int *data;     // Pointer untuk array dinamis yang nanti akan menyimpan elemen-elemen queue
    int head;     // Indeks elemen terdepan dalam queue
    int tail;      // Indeks elemen terakhir dalam queue
    int capacity;  // Kapasitas maksimum saat ini dari queue
} Queue;

// Fungsi ini untuk inisialisasi queue dengan kapasitas tertentu
void initQueue(Queue *q, int size) {
    q->data = (int*) malloc(size * sizeof(int));  // ini mengalokasikan memori untuk array dinamis sesuai ukuran yang ditentukan nantinya
    q->head = q->tail = -1;  // Menginisialisasi kalau head dan tail ke -1 untnuk menandakan queue kosong
    q->capacity = size;       // untuk menetapkan kapasitas awal queue
}

// Fungsi untuk memeriksa apakah queue kosong
int isEmpty(Queue *q) {
    return (q->head == -1 || q->head > q->tail);  // Queue dianggap kosong jika head bernilai -1 atau lebih besar dari tail (artinya jika queue lebih besar dari tail maka juga dianggap kosong, karena tidak mungkin apabila awalnya atau head nya melebihi nilai dari tail nya)
}

// Fungsi untuk menambahkan elemen ke dalam queue
void enqueue(Queue *q, int value) {
    if (q->tail == q->capacity - 1) {  // Memeriksa apakah queue ini penuh atau tidak
        q->capacity *= 2;  // Jika penuh, maka akan gandakan kapasitas queue
        q->data = (int*) realloc(q->data, q->capacity * sizeof(int));  // lalu Realokasi memori dengan kapasitas baru
        printf("Ukuran queue bertambah menjadi %d\n", q->capacity);  // untuk mengInformasikan atau memberitahu bahwa ukuran queue bertambah
    }

    if (q->head == -1) q->head = 0;  // Jika queue sebelumnya kosong, maka head tersebut akan di set ke 0
    q->tail++;  // Increment tail untuk menambahkan elemen di posisi berikutnya
    q->data[q->tail] = value;  // nilai baru tersebut akan disimpan diposisi tail 
    printf("Enqueue: %d\n", value);  // lalu ditampilkan nilai yang sudah ditambahkan
}

// Fungsi untuk menghapus elemen dari queue
int dequeue(Queue *q) {
    if (isEmpty(q)) {  // Memeriksa apakah queue kosong (karena jika tidak ada elemen, maka tidak ada yang bisa dihapus)
        printf("Queue kosong, tidak bisa dequeue!\n");  // Pesan ditampilkan jika queue kosong
        return -1;  // Mengembalikan -1 menandakan tidak adanya elemen yang di-dequeue
    }
    
    int temp = q->data[q->head];  // jika tidak kosong maka akan Menyimpan elemen yang akan dikeluarkan
    q->head++;  // lalu jika elemen sudah dikeluarkan maka akan Menggeser head ke kanan

    // Jika setelah dequeue, queue menjadi kosong
    if (q->head > q->tail) {
        q->head = q->tail = -1;  // maka, akan reset head dan tail ke -1(NULL)
    }

    return temp;  // Mengembalikan elemen yang dikeluarkan
}

// Fungsi untuk menampilkan elemen-elemen dalam queue
void displayQueue(Queue *q) {
    if (isEmpty(q)) {  // pertama, diperiksa apakah queue kosong
        printf("Queue kosong!\n");  // jika memang kosong, maka akan muncul pesan ini
        return; //agar saat queue emang kosong, maka setelah pesan muncul akan otomatis diberhentikan atau tidak lanjut
    }

    printf("Isi Queue: ");  // Menampilkan elemen-elemen dalam queue
    for (int i = q->head; i <= q->tail; i++) {  // Iterasi dari head ke tail
// jika i = head, maka batasnya head itu <=tail, jika lebih besar (>) dari tail, maka queue tersebut kosong
        printf("%d ", q->data[i]);  // Menampilkan setiap elemen
    }
    printf("\n");
}

// Fungsi utama
int main() {
    Queue q;  // Deklarasikan dulu variabel queue
    initQueue(&q, 5);  // lalu Inisialisasi queue dengan kapasitas awal 5

    enqueue(&q, 10);  // Menambahkan elemen 10 ke dalam queue
    enqueue(&q, 20);  // Menambahkan elemen 20 ke dalam queue
    enqueue(&q, 30);  // Menambahkan elemen 30 ke dalam queue
    enqueue(&q, 40);  // Menambahkan elemen 40 ke dalam queue
    enqueue(&q, 50);  // Menambahkan elemen 50 ke dalam queue
    
    displayQueue(&q);  // Menampilkan isi queue (opsional)

    enqueue(&q, 60);  // Menambahkan elemen 60 ke dalam queue, ini akan memperbesar ukuran queue karena kapasitas awal sudah penuh

    printf("Dequeue: %d\n", dequeue(&q));  // Mengeluarkan elemen yg terdepan dari queue
    printf("Dequeue: %d\n", dequeue(&q));  // Mengeluarkan elemen yg terdepan berikutnya dari queue

    displayQueue(&q);  // Menampilkan isi queue setelah dequeue

    return 0;  // Mengakhiri program
}