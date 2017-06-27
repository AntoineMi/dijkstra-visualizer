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
    printf("e\n");
}

void drawNode(int num, double x, double y, int r, int g, int b) {
    /* carré */
    glBegin(GL_QUADS);
        glColor3ub(r, g, b);
        glVertex2d(x - 20, y - 20);
        glVertex2d(x - 20, y + 20);
        glVertex2d(x + 20, y + 20);
        glVertex2d(x + 20, y - 20);
    glEnd();

    /* texte */
    glRasterPos2i(x, y - 5);
    void *font = GLUT_BITMAP_9_BY_15;
    glutBitmapCharacter(font, num);

}