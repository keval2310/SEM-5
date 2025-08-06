#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define V 7

void main(){
    int visited[V] = {0};
    int graph[V][V]={
        {0,1,0,4,0,0,0},
        {1,0,2,6,4,0,0},
        {0,2,0,0,5,6,0},
        {4,6,0,0,3,0,4},
        {0,4,5,3,0,8,7},
        {0,0,6,0,8,0,3},
        {0,0,0,4,7,3,0}
    };
    visited[0]=1;
    int edges = 0;
    int min, x, y;
    int totalCost = 0;
    printf("Edge : Weight\n");
    for(int i = 0; i < V - 1; i++) {
        min = INT_MAX;
        x = y = 0;
        for (int j = 0; j < V; j++) {
            if (visited[j]) {
                for (int k = 0; k < V; k++) {
                    if (!visited[k] && graph[j][k]) {
                        if (min > graph[j][k]) {
                            min = graph[j][k];
                            x = j;
                            y = k;
                        }
                    }
                }
            }
        }
        visited[y] = 1;
        edges++;
        totalCost += min;
        printf("%d - %d : %d\n", x, y, min);
    }
    printf("Total Cost: %d\n", totalCost);
}