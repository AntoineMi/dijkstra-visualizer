#ifndef _DRAW_H_
#define _DRAW_H_

#include "graph.h"

/* dessiner un graphe à partir de sa matrice */
void drawGraph(int matrix[NNODES][NNODES]);

/* dessiner un sommet avec son numéro, une position x y, et une couleur */
void drawNode(int num, double x, double y, int r, int g, int b);

#endif