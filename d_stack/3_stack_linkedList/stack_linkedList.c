#include <stdio.h>   // Mengimpor library standar untuk input/output (fungsi printf)
#include <stdlib.h>  // Mengimpor library standar untuk alokasi memori (malloc, free)

// Definisi untuk Node sebagai ADT (Abstract Data Type)
typedef struct Node {
    int data;           // Menyimpan data integer
    struct Node* next;  // Pointer ke node berikutnya dalam Linked List
} Node;

// Definisi untuk Stack yang menggunakan Linked List
typedef struct Stack {
    Node* top;  // Pointer ke node teratas dalam stack
} Stack;

// Fungsi untuk membuat Stack baru
Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack)); // Mengalokasikan memori untuk Stack
    stack->top = NULL;  // Menetapkan top stack ke NULL karena stack masih kosong
    return stack;  // Mengembalikan pointer ke Stack yang baru dibuat
}

// Fungsi untuk menambahkan elemen ke Stack (push)
void push(Stack* stack, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));  // Mengalokasikan memori untuk node baru
    newNode->data = data;  // Menetapkan nilai data node baru
    newNode->next = stack->top;  // Menetapkan pointer next node baru ke node yang ada di atas stack (jika ada)
    stack->top = newNode;  // Mengubah pointer top stack untuk menunjuk ke node baru
    printf("%d pushed to stack\n", data);  // Menampilkan pesan bahwa data telah dimasukkan ke dalam stack
}

// Fungsi untuk menghapus elemen dari Stack (pop)
int pop(Stack* stack) {
    if (stack->top == NULL) {  // Memeriksa apakah stack kosong
        printf("Stack is empty\n");  // Menampilkan pesan bahwa stack kosong
        return -1;  // Mengembalikan -1 sebagai tanda bahwa tidak ada elemen yang dapat dihapus
    }
    Node* temp = stack->top;  // Menyimpan pointer sementara ke node teratas
    int poppedValue = temp->data;  // Menyimpan nilai data node yang akan dihapus
    stack->top = stack->top->next;  // Memindahkan top stack ke node berikutnya
    free(temp);  // Membebaskan memori yang digunakan oleh node yang telah dihapus
    return poppedValue;  // Mengembalikan nilai yang dihapus dari stack
}

// Fungsi untuk menghancurkan Stack dan membebaskan memori
void destroyStack(Stack* stack) {
    while (stack->top != NULL) {  // Selama masih ada elemen di stack
        pop(stack);  // Menghapus elemen teratas dari stack
    }
    free(stack);  // Membebaskan memori yang dialokasikan untuk stack
}

int main() {
    // Stack
    Stack* stack = createStack();  // Membuat stack baru
    push(stack, 10);  // Menambahkan 10 ke dalam stack
    push(stack, 20);  // Menambahkan 20 ke dalam stack
    push(stack, 30);  // Menambahkan 30 ke dalam stack

    // Menghapus elemen-elemen dari stack dan mencetak nilainya
    printf("%d popped from stack\n", pop(stack));  // Menghapus elemen teratas (30) dan mencetak nilainya
    printf("%d popped from stack\n", pop(stack));  // Menghapus elemen teratas (20) dan mencetak nilainya

    destroyStack(stack);  // Menghapus semua elemen dalam stack dan membebaskan memori

    return 0;  // Program selesai
}
