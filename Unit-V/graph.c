/*
 * graph.c
 * 
 * This file implements various graph operations using both adjacency list and adjacency matrix representations. 
 * Author: gandiram
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define a structure to represent a graph using an adjacency list
struct Node {
    int vertex;
    struct Node* next;
};

struct Graph {
    int numVertices;
    struct Node** adjLists;
};

// Create a graph
struct Graph* createGraph(int vertices) {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
    graph->adjLists = malloc(vertices * sizeof(struct Node*));

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
    }
    return graph;
}

// Add edge to the graph (for undirected graph)
void addEdge(struct Graph* graph, int src, int dest) {
    // Add edge from src to dest
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->vertex = dest;
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Add edge from dest to src
    newNode = malloc(sizeof(struct Node));
    newNode->vertex = src;
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// Depth First Search (DFS) Traverse the graph
void DFSUtil(int vertex, bool* visited, struct Graph* graph) {
    visited[vertex] = true;
    printf("Visited %d \n", vertex);

    struct Node* adjList = graph->adjLists[vertex];
    while (adjList != NULL) {
        int connectedVertex = adjList->vertex;
        if (!visited[connectedVertex])
            DFSUtil(connectedVertex, visited, graph);
        adjList = adjList->next;
    }
}

void DFS(struct Graph* graph, int startVertex) {
    bool* visited = malloc(graph->numVertices * sizeof(bool));
    for (int i = 0; i < graph->numVertices; i++) {
        visited[i] = false;
    }
    DFSUtil(startVertex, visited, graph);
}

// Breadth First Search (BFS) Traverse the graph
void BFS(struct Graph* graph, int startVertex) {
    bool* visited = malloc(graph->numVertices * sizeof(bool));
    for (int i = 0; i < graph->numVertices; i++) {
        visited[i] = false;
    }

    int queue[graph->numVertices];
    int front = 0, rear = 0;

    visited[startVertex] = true;
    queue[rear++] = startVertex;

    while (front < rear) {
        int currentVertex = queue[front++];
        printf("Visited %d \n", currentVertex);

        struct Node* adjList = graph->adjLists[currentVertex];
        while (adjList != NULL) {
            int connectedVertex = adjList->vertex;
            if (!visited[connectedVertex]) {
                visited[connectedVertex] = true;
                queue[rear++] = connectedVertex;
            }
            adjList = adjList->next;
        }
    }
}

// Main function for testing
int main() {
    struct Graph* graph = createGraph(5);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    printf("Depth First Search starting from vertex 0: \n");
    DFS(graph, 0);

    printf("Breadth First Search starting from vertex 0: \n");
    BFS(graph, 0);

    return 0;
}