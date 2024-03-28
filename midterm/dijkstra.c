#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Structure to represent a node in the adjacency list
struct Node {
    int vertex;
    int weight;
    struct Node* next;
};

// Function to create a new node in the adjacency list
struct Node* createNode(int v, int w) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->weight = w;
    newNode->next = NULL;
    return newNode;
}

// Function to add an edge to the adjacency list
void addEdge(struct Node* adjList[], int src, int dest, int weight) {
    struct Node* newNode = createNode(dest, weight);
    newNode->next = adjList[src];
    adjList[src] = newNode;
}

// Function to find the vertex with minimum distance value
int findMinDistance(int distances[], int visited[], int V) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++) {
        if (!visited[v] && distances[v] <= min) {
            min = distances[v];
            min_index = v;
        }
    }

    return min_index;
}

// Function to print the shortest distances from the source vertex
void printSolution(int distances[], int V) {
    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < V; i++) {
        printf("%d \t %d\n", i, distances[i]);
    }
}

// Dijkstra's Algorithm to find the shortest paths from a source vertex to all other vertices
void dijkstraSSSP(struct Node* adjList[], int src, int V) {
    int distances[V]; // Array to store the shortest distances from the source vertex
    int visited[V];   // Array to mark visited vertices

    // Initialize distances and visited array
    for (int i = 0; i < V; i++) {
        distances[i] = INT_MAX;
        visited[i] = 0;
    }

    // Distance from source to itself is 0
    distances[src] = 0;

    // Implement Dijkstra's Algorithm using a min heap (priority queue)
    for (int count = 0; count < V - 1; count++) {
        int u = findMinDistance(distances, visited, V);
        visited[u] = 1;

        struct Node* temp = adjList[u];
        while (temp != NULL) {
            int v = temp->vertex;
            int weight = temp->weight;

            if (!visited[v] && distances[u] != INT_MAX &&
                distances[u] + weight < distances[v]) {
                distances[v] = distances[u] + weight;
            }

            temp = temp->next;
        }
    }

    // Print the result
    printSolution(distances, V);
}

int main() {
    int V = 6; // Number of vertices in the graph
    struct Node* adjList[V]; // Array of adjacency lists

    // Initialize adjacency lists as empty
    for (int i = 0; i < V; i++) {
        adjList[i] = NULL;
    }

    // Add edges to the adjacency list representation
    addEdge(adjList, 0, 1, 4);
    addEdge(adjList, 0, 2, 0);
    addEdge(adjList, 1, 2, 8);
    addEdge(adjList, 1, 3, 0);
    addEdge(adjList, 2, 3, 7);
    addEdge(adjList, 2, 5, 4);
    addEdge(adjList, 3, 4, 9);
    addEdge(adjList, 3, 5, 14);
    addEdge(adjList, 4, 5, 10);

    // Call Dijkstra's Algorithm with source vertex 0
    dijkstraSSSP(adjList, 0, V);

    return 0;
}
