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
    }

    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->dest = destX;
    newNode->next = gh->adjList[srcX];
    gh->adjList[srcX] = newNode;

    printf("Berhasil Menambahkan Edge\n");
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
    free(gh);
}

int main() {
    Graph* gh = (Graph*) malloc(sizeof(Graph));
    initGraph(gh, 4);

    addEdge(gh, 0, 1);
    addEdge(gh, 1, 2);
    addEdge(gh, 2, 3);
    addEdge(gh, 3, 0);
    addEdge(gh, 1, 3);

    destroyGraph(gh);
    return 0;
}