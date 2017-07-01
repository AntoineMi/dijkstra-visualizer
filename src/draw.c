#include <stdio.h>
#include <math.h>
#include <GL/gl.h>
#include <GL/glut.h>

#include "draw.h"
#include "graph.h"

/* GL_QUADS
1) top left
2) bottom left
3) top right
4) bottom right */

void drawGraph(int matrix[NNODES][NNODES]) {
    int i, j;
    char *c;
    int posX, posY, ySwitch;
    
    Node nodeArr[NNODES];
    Edge edgeArr[(NNODES + 1) * 2];

    /* remplir le tableau de sommets et assigner des coordonnées */
    posX = 20;
    posY = 350;
    ySwitch = 0;
    for (i = 0; i < NNODES; i++) {
        nodeArr[i].num = matrix[i][i];
        nodeArr[i].x = posX;
        nodeArr[i].y = posY;
 
        posX += 50;
        posY += (ySwitch ? -50 : 50);
        ySwitch += (ySwitch ? -1 : 1);
    }

    /* remplir le tableau d'arêtes et assigner */
    for (i = 0; i < NNODES; i++) {
        for (j = 0; j < NNODES; j++) {
            if (matrix[i][j] > 0) {
                edgeArr[j].start = nodeArr[j];
                edgeArr[j].dest = nodeArr[i];
                edgeArr[j].cost = matrix[i][j];
            }
        }
    }

    for (i = 0; i < NNODES; i++) {
        *c = i;
        drawNode(c, nodeArr[i].y, nodeArr[i].y, 255, 0, 0);
    }

}

void drawNode(char *num, double x, double y, int r, int g, int b) {
    /* carré */
    glBegin(GL_QUADS);
        glColor3ub(r, g, b);
        glVertex2d(x - 15, y - 15);
        glVertex2d(x - 15, y + 15);
        glVertex2d(x + 15, y + 15);
        glVertex2d(x + 15, y - 15);
    glEnd();

    /* texte */
    glColor3ub(0, 0, 0);
    glRasterPos2i(x - 5, y + 5);
    char *c;
    for (c = num; *c != '\0'; c++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
    }
}