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

void createGraph(int matrix[NNODES][NNODES]) {
    int i, j;

    /* remplir les tableaux de sommets et d'arêtes */
    for (i = 0; i < NNODES; i++) {
        nodeArr[i].num = i;
        nodeArr[i].r = 0;
        nodeArr[i].g = 0;
        nodeArr[i].b = 0;
    }

    for (i = 0; i < 6; i++) {
        edgeArr[i].r = 0;
        edgeArr[i].g = 0;
        edgeArr[i].b = 0;
    }

    /* IMPLÉMENTATION "EN DUR"
     *************************/

    nodeArr[0].x = 200;
    nodeArr[0].y = 400;

    nodeArr[1].x = 300;
    nodeArr[1].y = 200;

    nodeArr[2].x = 500;
    nodeArr[2].y = 200;

    nodeArr[3].x = 400;
    nodeArr[3].y = 400;

    nodeArr[4].x = 600;
    nodeArr[4].y = 400;


    edgeArr[0].start = nodeArr[0];
    edgeArr[0].dest = nodeArr[1];
    edgeArr[0].cost = 4;

    edgeArr[1].start = nodeArr[1];
    edgeArr[1].dest = nodeArr[2];
    edgeArr[1].cost = 13;

    edgeArr[2].start = nodeArr[1];
    edgeArr[2].dest = nodeArr[3];
    edgeArr[2].cost = 7;

    edgeArr[3].start = nodeArr[2];
    edgeArr[3].dest = nodeArr[4];
    edgeArr[3].cost = 4;

    edgeArr[4].start = nodeArr[3];
    edgeArr[4].dest = nodeArr[2];
    edgeArr[4].cost = 3;

    edgeArr[5].start = nodeArr[3];
    edgeArr[5].dest = nodeArr[4];
    edgeArr[5].cost = 9;

}

void drawGraph() {
    int i;
    for (i = 0; i < 6; i++)
        drawEdge(i);
    for (i = 0; i < NNODES; i++)
        drawNode(i);
}

void drawNode(int num) {
    double x, y;
    char str[2];
    char *c;

    /* carré */
    x = nodeArr[num].x;
    y = nodeArr[num].y;
    glBegin(GL_QUADS);
        glColor3ub(nodeArr[num].r, nodeArr[num].g, nodeArr[num].b);
        glVertex2d(x - 25, y - 25);
        glVertex2d(x - 25, y + 25);
        glVertex2d(x + 25, y + 25);
        glVertex2d(x + 25, y - 25);
    glEnd();


    /* texte */
    glColor3ub(255, 255, 255);
    glRasterPos2i(x - 5, y + 5);
    sprintf(str, "%d", num);
    for (c = str; *c != '\0'; c++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
    }
}

void drawEdge(int num) {
    double x1, y1, x2, y2;
    double trX1, trX2, trX3, trY1, trY2, trY3;
    int centerX, centerY;
    char str[2];
    char *c;

    /* ligne */
    x1 = edgeArr[num].start.x;
    y1 = edgeArr[num].start.y;
    x2 = edgeArr[num].dest.x;
    y2 = edgeArr[num].dest.y;

    glColor3ub(edgeArr[num].r, edgeArr[num].g, edgeArr[num].b);
    glBegin(GL_LINES);
        glColor3ub(edgeArr[num].r, edgeArr[num].g, edgeArr[num].b);
        glVertex2d(x1, y1);
        glVertex2d(x2, y2);
    glEnd();


    /* texte */
    centerX = fabs(x1 + x2) / 2;
    centerY = fabs(y1 + y2) / 2;

    glColor3ub(0, 0, 255);
    glRasterPos2i(centerX + 10, centerY - 10);
    sprintf(str, "%d", edgeArr[num].cost);
    for (c = str; *c != '\0'; c++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
    }


    /* triangle */
    if (y1 != y2) {
        if (y1 > y2) {
            trX1 = centerX;
            trY1 = centerY;
            trX2 = centerX + 3;
            trY2 = centerY + 17;
            trX3 = centerX - 17;
            trY3 = centerY + 5;
        } else {
            trX1 = centerX;
            trY1 = centerY;
            trX2 = centerX - 17;
            trY2 = centerY - 5;
            trX3 = centerX + 3;
            trY3 = centerY - 17;
        }
    } else {
        trX1 = centerX;
        trY1 = centerY;
        trX2 = centerX - 15;
        trY2 = centerY + 10;
        trX3 = centerX - 15;
        trY3 = centerY - 10;
    }

    glColor3ub(edgeArr[num].r, edgeArr[num].g, edgeArr[num].b);
    glBegin(GL_TRIANGLES);
        glVertex2d(trX1, trY1);
        glVertex2d(trX2, trY2);
        glVertex2d(trX3, trY3);
    glEnd();
}

/*
void createGraph(int matrix[NNODES][NNODES]) {
    int i, j;
    int posX, posY, ySwitch;

    / remplir le tableau de sommets et assigner des coordonnées /
    posX = 50;
    posY = 250;
    ySwitch = 0;
    for (i = 0; i < NNODES; i++) {
        nodeArr[i].num = matrix[i][i];
        nodeArr[i].x = posX;
        nodeArr[i].y = posY;
        nodeArr[i].r = 255;
        nodeArr[i].g = 0;
        nodeArr[i].b = 0;
 
        posX += 100;
        posY += (ySwitch ? -100 : 100);
        ySwitch = (ySwitch ? 0 : 1);
    }

    / remplir le tableau d'arêtes et assigner /
    for (i = 0; i < NNODES; i++) {
        for (j = 0; j < NNODES; j++) {
            if (matrix[i][j] > 0) {
                edgeArr[j].start = nodeArr[j];
                edgeArr[j].dest = nodeArr[i];
                edgeArr[j].cost = matrix[i][j];
                edgeArr[i].r = 0;
                edgeArr[i].g = 0;
                edgeArr[i].b = 0;
            }
        }
    }

}
*/