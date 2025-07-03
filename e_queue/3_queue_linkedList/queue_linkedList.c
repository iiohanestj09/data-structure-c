#include <stdio.h>   // Pustaka standar untuk input-output seperti printf dan scanf
#include <stdlib.h>  // Pustaka standar untuk fungsi alokasi memori seperti malloc dan free

// Ini untuk mendefinisikan struktur Node pada Linked List yang bakal dipakai untuk Queue
typedef struct Node {
    int data;          // Data yang bakal disimpan di dalam node
    struct Node* next; // Pointer ke node berikutnya (karena pakai linked list)
} Node;

// Ini adalah struktur utama dari Queue yang terdiri dari head (elemen pertama) dan tail (elemen terakhir)
typedef struct {
    Node* head;  // Pointer ke elemen paling depan (head) dalam queue
    Node* tail;   // Pointer ke elemen paling belakang (tail) dalam queue
} Queue;

// Fungsi untuk menginisialisasi queue, ini harus dipanggil dulu sebelum queue dipakai
void initQueue(Queue* q) {
    q->head = q->tail = NULL;  // Awalnya, queue masih kosong jadi head dan tail di-set NULL
}

// Fungsi untuk memeriksa apakah queue kosong atau tidak
int isEmpty(Queue* q) {
    return (q->head == NULL);  // Kalau head masih NULL, artinya queue kosong
}

// Fungsi untuk menambahkan elemen ke dalam queue (enqueue)
void enqueue(Queue* q, int value) {
    // Alokasi memori untuk node baru (karena pakai linked list, tiap elemen harus dialokasikan secara dinamis)
    Node* newNode = (Node*) malloc(sizeof(Node));  // malloc untuk alokasi memori
    newNode->data = value;  // Masukkan nilai yang ingin ditambahkan ke dalam node
    newNode->next = NULL;   // Node baru ini belum terhubung ke node lain, jadi next-nya NULL

    if (q->tail == NULL) {  // Kalau queue masih kosong (tail NULL), berarti ini elemen pertama
        q->head = q->tail = newNode;  // Head dan tail langsung menunjuk ke node baru ini
    } else {  
        q->tail->next = newNode;  // Hubungkan node terakhir (tail) ke newNode
        q->tail = newNode;        // Geser tail ke newNode (karena newNode sekarang jadi elemen terakhir)
    }
    printf("Enqueue: %d\n", value);  // Cetak elemen yang ditambahkan
}

// Fungsi untuk menghapus elemen dari queue (dequeue)
int dequeue(Queue* q) {
    if (isEmpty(q)) {  // Periksa dulu apakah queue kosong
        printf("Queue kosong, tidak bisa dequeue!\n");  // Kalau kosong, cetak pesan error
        return -1;  // Kembalikan -1 sebagai tanda error
    }

    Node* temp = q->head;  // Simpan node yang akan dihapus ke dalam variabel temp
    int data = temp->data;  // Simpan nilai dari node yang akan dikeluarkan

    q->head = q->head->next;  // Geser head ke node berikutnya

    if (q->head == NULL) {  // Kalau setelah dequeue queue jadi kosong
        q->tail = NULL;  // Rear juga harus di-set NULL
    }

    free(temp);  // Hapus node yang sudah tidak digunakan dari memori
    return data;  // Kembalikan nilai yang dikeluarkan
}

// Fungsi untuk menampilkan isi queue
void displayQueue(Queue* q) {
    if (isEmpty(q)) {  // Cek dulu apakah queue kosong
        printf("Queue kosong!\n");
        return;  // Langsung berhenti kalau queue kosong
    }

    printf("Isi Queue: ");
    Node* temp = q->head;  // Pakai variabel sementara untuk traversal dari head ke tail
    while (temp != NULL) {  // Selama masih ada node, lakukan perulangan
        printf("%d ", temp->data);  // Cetak nilai data di node saat ini
        temp = temp->next;  // Geser ke node berikutnya
    }
    printf("\n");  // Buat baris baru setelah selesai menampilkan isi queue
}

// Fungsi utama
int main() {
    Queue q;  // Deklarasi variabel queue
    initQueue(&q);  // Panggil fungsi inisialisasi queue sebelum digunakan

    enqueue(&q, 10);  // Tambahkan elemen 10 ke queue
    enqueue(&q, 20);  // Tambahkan elemen 20 ke queue
    enqueue(&q, 30);  // Tambahkan elemen 30 ke queue
    enqueue(&q, 40);  // Tambahkan elemen 40 ke queue

    displayQueue(&q);  // Tampilkan isi queue

    printf("Dequeue: %d\n", dequeue(&q));  // Hapus elemen paling depan dan cetak hasilnya
    printf("Dequeue: %d\n", dequeue(&q));  // Hapus elemen berikutnya dan cetak hasilnya

    displayQueue(&q);  // Tampilkan isi queue setelah dequeue

    return 0;  // Selesai program
}
