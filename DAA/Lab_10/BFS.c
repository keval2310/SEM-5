#include<stdio.h>

#define V 8

void BFSHelper(int graph[V][V], int start) {
    int queue[V], front = 0, rear = 0;
    int visited[V] = {0};

    queue[rear++] = start;
    visited[start] = 1;

}
void main(){
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

    printf("BFS traversal starting from vertex %d:\n", );
    BFSHelper(graph);
}