#include <stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>

#include "graph.h"

void printMatrix(int matrix[NNODES][NNODES]) {
    int i, j;
    for (i = 0; i < NNODES; i++) {
        for (j = 0; j < NNODES; j++) {
            printf( "%3d ", matrix[i][j] );
        }
        printf("\n");
    }
}

void drawGraph(int matrix[NNODES][NNODES]) {
    printf("do\n");
}

int* solveDijkstra(int graphMatrix[NNODES][NNODES], int start) {
    int count, smallest, next, i, j;

    /* tableau des distances */
    static int distances[NNODES];

    /* tableau des prédécesseurs de chaque sommet */
    int predecessors[NNODES];

    /* tableaux des visites */
    int visited[NNODES] = { 0 }; /* aucun sommet visité */

    /* matrice des coûts */
    int costMatrix[NNODES][NNODES];

    for (i = 0; i < NNODES; i++) {
        for (j = 0; j < NNODES; j++) {

            /* si les sommets ne sont pas reliés, coût infini */
            if (graphMatrix[i][j] == 0)
                costMatrix[i][j] = INF;
            /* sinon, on remplit avec le coût de chaque arête */
            else
                costMatrix[i][j] = graphMatrix[i][j];
        }
    }
    
    /* distance depuis start jusqu'à chaque sommet */
    for (i = 0; i < NNODES; i++) {
        distances[i] = costMatrix[start][i]; /* coût si relié, infini sinon */
        predecessors[i] = start; /* nous passons par chaque sommet depuis start */
    }
    
    distances[start] = 0;
    visited[start] = 1;
    count = 1;
    
    while(count < NNODES - 1) {
        smallest = INF;
        
        /* recherche du sommet le moins distant */
        for (i = 0; i < NNODES; i++)
            if ( (distances[i] < smallest)
            &&   (!visited[i]) ) {
                
                smallest = distances[i];
                next = i;
            }
            
            /* recherche d'un chemin plus court via le sommet suivant */          
            visited[next] = 1;
            for (i = 0; i < NNODES; i++) {
                if (!visited[i]) {
                    if (smallest + costMatrix[next][i] < distances[i]) {
                        distances[i] = smallest + costMatrix[next][i];
                        predecessors[i] = next;
                    }
                }
            }
        
        count++;
    }

    /* affichage */
    for (i = 0; i < NNODES; i++) {
        if (i != start) {
            
            printf("\nJusqu'au sommet %d\n", i);
            printf("Distance : %d\n", distances[i]);
            
            printf("Chemin : %d", i);
            j = i;
            do {
                j = predecessors[j];
                printf(" <-- %d", j);
            } while (j != start);
            printf("\n");
        }
    }

    return distances;
}