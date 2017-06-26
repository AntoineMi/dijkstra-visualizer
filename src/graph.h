#ifndef _GRAPH_H_
#define _GRAPH_H_

#define NNODES 5
#define INF 1000

/* afficher dans la console la matrice passée en paramètre */
void printMatrix(int matrix[NNODES][NNODES]);

/* dessiner un graphe à partir de sa matrice */
void drawGraph(int matrix[NNODES][NNODES]);

/* calculer le plus court chemin depuis start vers les autres sommets */
int* solveDijkstra(int matrix[NNODES][NNODES], int start);

#endif
