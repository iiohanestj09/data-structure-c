#include <stdio.h>   
#include <stdlib.h>  

// Definisi untuk Node sebagai ADT (Abstract Data Type)
typedef struct Node {
    int data;           
    struct Node* next;  // Pointer ke node berikutnya dalam Linked List
} Node;


typedef struct Stack {
    Node* top;  // Pointer ke node teratas dalam stack
} Stack;

Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack)); 
    stack->top = NULL;  
    return stack;  
}

void push(Stack* stack, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));  
    newNode->data = data;  
    newNode->next = stack->top;  
    stack->top = newNode; 
    printf("%d pushed to stack\n", data);  
}

int pop(Stack* stack) {
    if (stack->top == NULL) {  
        printf("Stack is empty\n");  
        return -1;  
    }
    Node* temp = stack->top;  
    int poppedValue = temp->data; 
    stack->top = stack->top->next; 
    free(temp);  
    return poppedValue; 
}

void destroyStack(Stack* stack) {
    while (stack->top != NULL) {  
        pop(stack);  
    }
    free(stack);  
}

int main() {
    
    Stack* stack = createStack();  
    push(stack, 10);  
    push(stack, 20);  
    push(stack, 30);  

    
    printf("%d popped from stack\n", pop(stack));  
    printf("%d popped from stack\n", pop(stack));  

    destroyStack(stack);  

    return 0;  
}