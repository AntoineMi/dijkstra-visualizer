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
