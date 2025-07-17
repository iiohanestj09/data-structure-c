#include <stdio.h>  

#define MAX 5  

// Struktur Stack pakai array statis
typedef struct {
    int data[MAX];  
    int top;        
} Stack;

void initStack(Stack *s) {
    s->top = -1; 
}

int isEmpty(Stack *s) {
    return s->top == -1;  
}

int isFull(Stack *s) {
    return s->top == MAX - 1;  
}

void push(Stack *s, int value) {
    if (isFull(s)) { 
        printf("Stack penuh, tidak bisa push %d!\n", value);
        return;  
    }

    s->top++;  
    s->data[s->top] = value; 
    printf("Push: %d\n", value); 
}

int pop(Stack *s) {
    if (isEmpty(s)) { 
        printf("Stack kosong, tidak bisa pop!\n");
        return -1;  
    }
    
    int poppedValue = s->data[s->top]; 
    s->top--;  
    return poppedValue; 
}

int peek(Stack *s) {
    if (isEmpty(s)) { 
        printf("Stack kosong!\n");
        return -1; 
    }
    return s->data[s->top]; 
}

void displayStack(Stack *s) {
    if (isEmpty(s)) { 
        printf("Stack kosong!\n"); 
        return; 
    }
    
    printf("Isi Stack: "); 
    for (int i = s->top; i >= 0; i--) { 
        printf("%d ", s->data[i]); 
    }
    printf("\n"); 
}

int main() {
    Stack s; 
    initStack(&s); 

    push(&s, 10); 
    push(&s, 20); 
    push(&s, 30); 
    push(&s, 40); 
    push(&s, 50); 

    displayStack(&s); 

    push(&s, 60); 

    printf("Pop: %d\n", pop(&s)); 
    printf("Pop: %d\n", pop(&s)); 

    displayStack(&s); 

    printf("Elemen teratas: %d\n", peek(&s)); 

    return 0; 
}
