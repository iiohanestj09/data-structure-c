#include <stdio.h>
#include <stdlib.h>

typedef struct tElementList {
    int data;
    struct tElementList *next;
} ElementList;

typedef struct linkedlist {
    ElementList *head;
} Linkedlist;

void init(Linkedlist *list) {
    list->head = NULL;
}

void addElement(Linkedlist *list, int dataX) {
    ElementList *newElement = (ElementList *)malloc(sizeof(ElementList));
    newElement->data = dataX;
    newElement->next = list->head;
    list->head = newElement;
}

void delElement(Linkedlist *list, int dataX) {
    ElementList *current = list->head;
    ElementList *previous = NULL;

    while (current != NULL && current->data != dataX) {
        previous = current;
        current = current->next;
    }

    if (current != NULL) {
        if (previous == NULL) {
            list->head = current->next;
        } else {
            previous->next = current->next;
        }
        free(current);
    }
}

ElementList* search(Linkedlist *list, int dataX) {
    ElementList *current = list->head;

    while (current != NULL && current->data != dataX) {
        current = current->next;
    }

    return current;
}

void destroy(Linkedlist *list) {
    ElementList *current = list->head;

    while (current != NULL) {
        ElementList *nextElement = current->next;
        free(current);
        current = nextElement;
    }

    list->head = NULL;
}

int main() {
    Linkedlist list;

    init(&list);
    addElement(&list, 10);
    addElement(&list, 20);
    addElement(&list, 30);

    printf("List setelah penambahan elemen:\n");
    ElementList *current = list.head;
    while (current != NULL) {
        printf("%d\n", current->data);
        current = current->next;
    }

    delElement(&list, 20);

    printf("\nList setelah penghapusan elemen 20:\n");
    current = list.head;
    while (current != NULL) {
        printf("%d\n", current->data);
        current = current->next;
    }

    ElementList *found = search(&list, 10);
    if (found != NULL) {
        printf("\nElemen %d ditemukan.\n", found->data);
    } else {
        printf("\nElemen tidak ditemukan.\n");
    }

    destroy(&list);

    if (list.head == NULL) {
        printf("\nList berhasil dihancurkan.\n");
    }

    return 0;
}
