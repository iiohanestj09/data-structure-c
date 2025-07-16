#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int dest;
    struct node* next;
} Node;

typedef struct graph {
    Node** adjList;
    int vertices;
} Graph;

void initGraph(Graph* gh, int size) {
    gh->vertices = size;
    gh->adjList = (Node**) malloc(size * sizeof(Node*));
    for (int i = 0; i < size; ++i) {
        gh->adjList[i] = NULL;
    }
}

void addEdge(Graph* gh, int srcX, int destX) {
    if (srcX < 0 || destX < 0 || srcX >= gh->vertices || destX >= gh->vertices) {
        printf("Gagal menambah edge\n");
        return;
    } else {
        Node* newNode = (Node*) malloc(sizeof(Node));
        newNode->dest = destX;
        newNode->next = gh->adjList[srcX];
        gh->adjList[srcX] = newNode;

        printf("Berhasil Menambahkan Edge\n");
    }
}

void destroyGraph(Graph* gh) {
    for (int i = 0; i < gh->vertices; ++i) {
        Node* temp = gh->adjList[i];
        while (temp != NULL) {
            Node* toDelete = temp;
            temp = temp->next;
            free(toDelete);
        }
    }

    free(gh->adjList);
}