#include <stdio.h>
#include <stdlib.h>

typedef struct graph {
    int** adjMatrix;
    int vertices;
} Graph;

void initGraph(Graph* gh, int size) {
    gh->vertices = size;
    gh->adjMatrix = (int**) malloc(size * sizeof(int*));
    for (int i = 0; i < size; ++i) {
        gh->adjMatrix[i] = (int*) calloc(size, sizeof(int));
    }
}

void addEdge(Graph* gh, int src, int dest) {
    if (src >= 0 && dest >= 0 && src < gh->vertices && dest < gh->vertices) {
        gh->adjMatrix[src][dest] = 1;
    }
}

void destroyGraph(Graph* gh) {
    for (int i = 0; i , gh->vertices; ++i) {
        free(gh->adjMatrix[i]);
    }

    free(gh->adjMatrix);
}