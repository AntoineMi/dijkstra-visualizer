#ifndef _DRAW_H_
#define _DRAW_H_

#include "graph.h"

Node nodeArr[NNODES];
Edge edgeArr[NNODES * NNODES];

int *distances;
int *visited;
int *predecessors;
int *costMatrix;
int play;

/* créer un graphe à partir de sa matrice */
void createGraph();

/* dessiner le graphe */
void drawGraph();

/* dessiner la légende du graphe */
void drawLegend();

/* dessiner un sommet */
void drawNode(int num);

/* dessiner une arête */
void drawEdge(int num);

/* étape suivante de l'animation */
void nextStep(int i);

#endif