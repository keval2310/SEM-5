#include <stdio.h>
#define V 9

    int visited[V];

void DFSHelper(int v, int graph[V][V]) {
    visited[v] = 1;
    printf("%d ", v);

    for (int i = 0; i < V; i++) {
        if (graph[v][i] && !visited[i]) {
            DFSHelper(i, graph);
        }
    }
}

int main() {
    int graph[V][V] = {
        {0, 1, 1, 0, 0, 0, 0, 0},
        {1, 0, 0, 1, 1, 0, 0, 0},
        {1, 0, 0, 0, 0, 1, 0, 0},
        {0, 1, 0, 0, 0, 0, 1, 0},
        {0, 1, 0, 0, 0, 0, 0, 1},
        {0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 0}
    };

    for (int i = 0; i < V; i++)
        visited[i] = 0;

    printf("DFS traversal starting from vertex 0:\n");
    DFSHelper(0, graph);
    printf("\n");

    return 0;
}