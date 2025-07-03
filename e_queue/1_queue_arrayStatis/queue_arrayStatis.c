#include <stdio.h>   // Pustaka standar buat input-output (biar bisa pakai printf & scanf)
#define max 5        // Batas maksimal ukuran queue (karena ini queue statis)


typedef struct queue {
    int data[max];  // Array buat nyimpen elemen queue
    int head, rear; // head itu elemen depan, rear itu elemen belakang
} Queue;

// Fungsi buat inisialisasi queue
void initQueue(Queue *q) {
    q->head = -1;  // head = -1 artinya queue masih kosong
    q->rear = -1;  // rear = -1 juga berarti belum ada elemen
}

// Fungsi buat ngecek apakah queue kosong
int isEmpty(Queue *q) {
    return q->head == -1;  // Queue kosong kalau head masih -1
}

// Fungsi buat ngecek apakah queue penuh
int isFull(Queue *q) {
    return q->rear == max - 1;  // Queue penuh kalau rear udah di indeks max-1
}

// Fungsi buat masukin elemen ke queue (enqueue)
void enqueue(Queue *q, int value) {
    if (isFull(q)) {  // Cek dulu, kalau penuh ga bisa masukin elemen
        printf("Queue penuh!\n");  
        return;
    }
    if (isEmpty(q))  // Kalau queue kosong, set head ke 0 (biar mulai dari indeks pertama)
        q->head = 0;
    
    q->rear++;  // Tambah rear dulu buat nyiapin tempat buat elemen baru
    q->data[q->rear] = value;  // Simpan elemen di posisi rear
    printf("Enqueue: %d\n", value);  // Kasih tau elemen yang dimasukin
}

// Fungsi buat ngeluarin elemen dari queue (dequeue)
int dequeue(Queue *q) {
    if (isEmpty(q)) {  // Kalau kosong, ga bisa dequeue
        printf("Queue kosong!\n");
        return -1;
    }
    
    int temp = q->data[q->head];  // Simpan dulu elemen yang mau dikeluarin
    printf("Dequeue: %d\n", temp);  // Kasih tau elemen yang dikeluarin

    if (q->head == q->rear) {  // Kalau cuma 1 elemen yang ada
        q->head = q->rear = -1;  // Reset queue ke kosong lagi
    } else {
        q->head++;  // Geser head ke elemen berikutnya
    }

    return temp;  // Balikin elemen yang udah dikeluarin
}

// Fungsi buat nampilin isi queue
void display(Queue *q) {
    if (isEmpty(q)) {  // Kalau kosong, kasih tau aja biar ga bingung
        printf("Queue kosong!\n");
        return;
    }
    
    printf("Isi queue: ");
    for (int i = q->head; i <= q->rear; i++) {  // Loop dari head sampai rear
        printf("%d ", q->data[i]);  // Cetak elemen satu per satu
    }
    printf("\n");
}

// Fungsi utama (main)
int main() {
    Queue q;         // Deklarasi queue
    initQueue(&q);   // Inisialisasi biar mulai dari kosong

    enqueue(&q, 10);  // Masukin elemen 10
    enqueue(&q, 20);  // Masukin elemen 20
    enqueue(&q, 30);  // Masukin elemen 30
    enqueue(&q, 40);  // Masukin elemen 40
    enqueue(&q, 50);  // Masukin elemen 50

    display(&q);  // Tampilkan isi queue

    dequeue(&q);  // Keluarkan elemen pertama
    dequeue(&q);  // Keluarkan elemen berikutnya

    display(&q);  // Tampilkan isi queue setelah dequeue

    return 0;  // Selesai
}
