#include<stdio.h>

struct  Edge {
    int source;
    int desitnation;
    int weight;
};

void sortEdge(struct Edge edges[], int E) {
    for(int i = 1; i < E; i++) {
        struct Edge key = edges[i];

        int j = i - 1;

        while (j>=0 && key.weight < edges[j].weight) {
            edges[j + 1] = edges[j];
            j--;
        }
        
    }
}

int find(int parent[], int i) {
    if(parent[i] == i) {
        return i;
    }
    return find(parent, parent[i]);
}

void unionSet(int parent[], int u, int v){
    parent[u] = v;
}

void kruskal(struct Edge edges[], int E, int V) {
    struct Edge result[V];
    int parent[V];

    for(int i = 0; i < V; i++) {
        parent[i] = i;
    }

    sortEdge(edges, E);

    int e = 0;
    int i = 0;

    while(e < V - 1 && i < E) {
        struct Edge next_edge = edges[i++];
        int x = find(parent, next_edge.source);
        int y = find(parent, next_edge.desitnation);

        if(x != y) {
            result[e++] = next_edge;
            unionSet(parent, x, y);
        }
    }

    printf("Edges in the constructed MST:\n");
    for(int j = 0; j < e; j++) {
        printf("%d -- %d == %d\n", result[j].source, result[j].desitnation, result[j].weight);
    }
}


int main() {
    int V = 4;  
    int E = 5; 

    struct Edge edges[] = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    kruskal(edges, E, V);
    return 0;
        
}