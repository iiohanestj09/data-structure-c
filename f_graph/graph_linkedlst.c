#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Node untuk adjacency list
typedef struct Node {
    int dest;          // Simpul tujuan
    int weight;        // Bobot edge
    struct Node* next; // Pointer ke node berikutnya
} Node;

// ADT untuk AdjList
typedef struct AdjList {
    Node* head;        // Pointer ke head (awal) dari linked list
} AdjList;

// Graph dengan ADT AdjList
typedef struct Graph {
    int nodes;         // Jumlah simpul dalam graf
    AdjList* arr;    // Array dari adjacency list (menggunakan ADT AdjList)
} Graph;

// Inisialisasi Graph
void initializeGraph(Graph* graf, int numNodes) {
    graf->nodes = numNodes;
    graf->arr = (AdjList*)malloc(numNodes * sizeof(AdjList));
    for (int i = 0; i < numNodes; i++) {
        graf->arr[i].head = NULL;  // Setiap adjacency list di-inisialisasi sebagai kosong
    }
}

// Menambahkan edge ke adjacency list
void addEdge(Graph* graf, int v1, int v2, int weight) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->dest = v2;
    newNode->weight = weight;
    newNode->next = graf->arr[v1].head;  // Masukkan ke awal linked list
    graf->arr[v1].head = newNode;
}

// Fungsi untuk menemukan node dengan jarak minimum
int findMinDistance(int* dist, int* visited, int numNodes) {
    int minDist = INT_MAX;
    int minIndex = -1;
    for (int v = 0; v < numNodes; v++) {
        if (!visited[v] && dist[v] < minDist) {
            minDist = dist[v];
            minIndex = v;
        }
    }
    return minIndex;
}

// Mencetak jalur dari source ke destination
void printPath(int* parent, int current) {
    if (current == -1) return;
    printPath(parent, parent[current]);
    printf("%d ", current);
}

// Dijkstra untuk menghitung jarak terpendek
void dijkstra(Graph* graf, int source, int destination) {
    int numNodes = graf->nodes;
    int dist[numNodes];
    int visited[numNodes];
    int parent[numNodes];

    for (int i = 0; i < numNodes; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
        parent[i] = -1;
    }
    dist[source] = 0;

    for (int count = 0; count < numNodes - 1; count++) {
        int u = findMinDistance(dist, visited, numNodes);
        if (u == -1) break; // Jika tidak ada node yang tersisa untuk diproses
        visited[u] = 1;

        Node* temp = graf->arr[u].head;  // Traversal linked list dari node u
        while (temp != NULL) {
            int v = temp->dest;
            if (!visited[v] && dist[u] != INT_MAX && dist[u] + temp->weight < dist[v]) {
                dist[v] = dist[u] + temp->weight;
                parent[v] = u;
            }
            temp = temp->next;
        }
    }

    if (dist[destination] == INT_MAX) {
        printf("Tidak ada jalur dari Node %d ke Node %d.\n", source, destination);
    } else {
        printf("Jarak terpendek dari Node %d ke Node %d adalah: %d\n", source, destination, dist[destination]);
        printf("Jalur yang dilalui: ");
        printPath(parent, destination);
        printf("\n");
    }
}

// Membebaskan memori graf
void freeGraph(Graph* graf) {
    for (int i = 0; i < graf->nodes; i++) {
        Node* current = graf->arr[i].head;
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(graf->arr);
}

int main() {
    Graph graf;
    int numNodes, numEdges, maxEdge, v1, v2, weight, source, destination;

    printf("Masukkan jumlah Node dalam Graf: ");
    scanf("%d", &numNodes);
    initializeGraph(&graf, numNodes);
    maxEdge = numNodes * (numNodes - 1);

    do {
        printf("Masukkan jumlah Edge: ");
        scanf("%d", &numEdges);

        if (numEdges > maxEdge) {
            printf("Jumlah Edge Tidak Boleh lebih dari %d!\n", maxEdge);
        }
    } while (numEdges > maxEdge);

    printf("\nNOTES: Node dengan index Terkecil Harus Diawali 0!!!\n");
    for (int i = 0; i < numEdges; i++) {
        printf("%d. Masukkan 2 Titik untuk membentuk Edge (v1 v2): ", i + 1);
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
