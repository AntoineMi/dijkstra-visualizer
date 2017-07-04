#ifndef _DRAW_H_
#define _DRAW_H_

#include "graph.h"

Node nodeArr[NNODES];
Edge edgeArr[NNODES * NNODES];

/* créer un graphe à partir de sa matrice */
void createGraph();

void drawGraph();

/* dessiner un sommet */
void drawNode(int num);

/* dessiner une arête */
void drawEdge(int num);

/* dessiner sous un sommet le coût depuis start */
void drawCost(int num, int node);

#endif