#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct graph{
    int **adjMatrix;
    int nodes;
} Graph;

void initializeGraph(Graph *graf, int numNodes) {
    graf->nodes = numNodes;
    graf->adjMatrix = (int **)malloc(numNodes * sizeof(int *));
    for(int i = 0; i < numNodes; i++) {
        graf->adjMatrix[i] = (int *)malloc(numNodes * sizeof(int));
    }
    for(int i = 0; i < numNodes; i++) {
        for(int j = 0; j < numNodes; j++) {
            graf->adjMatrix[i][j] = 0;
        }
    }
}

void addEdge(Graph *graf, int v1, int v2, int weight) {
    graf->adjMatrix[v1][v2] = weight;
}

int findMinDistance(int *dist, int *visited, int numNodes) {
    int min = INT_MAX, minIndex = -1;
    for(int v = 0; v < numNodes; v++) {
        if(!visited[v] && dist[v] < min) {
            min = dist[v];
            minIndex = v;
        }
    }
    return minIndex;
}

void printPath(int *parent, int current) {
    if(current == -1) return;
    printPath(parent, parent[current]);
    printf("%d ", current);
}

void dijkstra(Graph *graf, int source, int destination) {
    int numNodes = graf->nodes;
    int dist[numNodes];
    int visited[numNodes];
    int parent[numNodes];

    for(int i = 0; i < numNodes; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
        parent[i] = -1; 
    }
    dist[source] = 0;

    for(int count = 0; count < numNodes - 1; count++) {
        int u = findMinDistance(dist, visited, numNodes);
        visited[u] = 1;

        for(int v = 0; v < numNodes; v++) {
            if(!visited[v] && graf->adjMatrix[u][v] && dist[u] != INT_MAX && dist[u] + graf->adjMatrix[u][v] < dist[v]) {
                dist[v] = dist[u] + graf->adjMatrix[u][v];
                parent[v] = u; // Perbarui parent
            }
        }
    }

    if(dist[destination] == INT_MAX) {
        printf("Tidak ada jalur dari Node %d ke Node %d.\n", source, destination);
    } else{
        printf("Jarak terpendek dari Node %d ke Node %d adalah: %d\n", source, destination, dist[destination]);
        printf("Jalur yang dilalui: ");
        printPath(parent, destination);
        printf("\n");
    }
}

void freeGraph(Graph *graf) {
    for(int i = 0; i < graf->nodes; i++) {
        free(graf->adjMatrix[i]);
    }
    free(graf->adjMatrix);
}

int main() {
    Graph graf;
    int numNodes, numEdges, maxEdge, v1, v2, weight, source, destination;

    printf("Masukkan jumlah Node dalam Graf: ");
    scanf("%d", &numNodes);
    initializeGraph(&graf, numNodes);
    maxEdge = numNodes * (numNodes - 1);
    
    do{
        printf("Masukkan jumlah Edge: ");
        scanf("%d", &numEdges);

        if(numEdges > maxEdge){
            printf("Jumlah Edge Tidak Boleh lebih dari %d!\n", maxEdge);
        }
    } while(numEdges > maxEdge);

    printf("\nNOTES: Titik dengan index Terkecil Harus Diawali 0!!!\n");
    for(int i = 0; i < numEdges; i++) {
        printf("%d. Masukkan 2 Titik untuk membentuk Edge (v1 v2): ", i+1);
        scanf("%d %d", &v1, &v2);
        printf("Berikan Bobot pada Edge %d%d: ", v1, v2);
        scanf(" %d", &weight);
        addEdge(&graf, v1, v2, weight);
        printf("\n");
    }

    printf("Masukkan Node Titik Awal Pencarian (Source): ");
    scanf("%d", &source);
    printf("Masukkan Titik Tujuan (Destination): ");
    scanf("%d", &destination);

    dijkstra(&graf, source, destination);
    freeGraph(&graf);

    return 0;
}
