#ifndef _GRAPH_H_
#define _GRAPH_H_

#define NNODES 5
#define INF 1000
#define PI 3.1415

int start;

typedef struct Node {
    int x, y;
    int num;
    int r, g, b;
    int showCost;
} Node;

typedef struct Edge {
    Node start, dest;
    int cost;
    int r, g, b;
} Edge;

/* afficher dans la console la matrice passée en paramètre */
void printMatrix(int matrix[NNODES][NNODES]);

/* calculer le plus court chemin depuis start vers les autres sommets */
int * solveDijkstra(int matrix[NNODES][NNODES], int start);

#endif
