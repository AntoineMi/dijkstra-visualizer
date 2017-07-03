#ifndef _DRAW_H_
#define _DRAW_H_

#include "graph.h"

Node nodeArr[NNODES];
Edge edgeArr[NNODES * NNODES];

/* créer un graphe à partir de sa matrice */
void createGraph(int matrix[NNODES][NNODES]);

void drawGraph();

/* dessiner un sommet */
void drawNode(int num);

/* dessiner une arête */
void drawEdge(int num);

#endif