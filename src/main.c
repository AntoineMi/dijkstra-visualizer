#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glut.h>

#include "draw.h"
#include "graph.h"

int WINDOW_WIDTH = 800;
int WINDOW_HEIGHT = 600;
int BIT_PER_PIXEL = 32;
char* WINDOW_TITLE = "Dijkstra Visualizer";

int main(int argc, char *argv[]) {

    /* RÉCUPÉRATION DU SOMMET DE DÉPART
    ***********************************/

    int start;
    if ((argc != 2)) {
        start = 0;
        printf("Argument(s) incorrect(s), sommet de départ = 0\n");
    } else {
        start = atoi(argv[1]);

        /* Vérifier si le sommet demandé existe */
        if (start >= NNODES) {
            start = NNODES - 1;
            printf("Il n'y a que %d sommets, sommet de départ = %d\n", NNODES, start);
        } else if (start < 0) {
            start = 0;
            printf("Sommet de départ = 0\n");
        } else
            printf("Sommet de départ = %d\n", start);
    }

    /* INITIALISATION SDL ET GLUT
    *****************************/

    SDL_Init(SDL_INIT_VIDEO);
    SDL_Surface *screen = SDL_SetVideoMode(
        WINDOW_WIDTH, WINDOW_HEIGHT, BIT_PER_PIXEL, SDL_OPENGL);
    SDL_WM_SetCaption(WINDOW_TITLE, 0);

    glutInit(&argc, argv);


    /* GRAPHE
     ********/

    int gr[NNODES][NNODES] = {
       /* 0   1   2   3   4 */
        { 0 , 4 , 0 , 0 , 0 }, /* 0 */
        { 0 , 0 , 13, 7 , 0 }, /* 1 */
        { 0 , 0 , 0 , 0 , 4 }, /* 2 */
        { 0 , 0 , 3 , 0 , 9 }, /* 3 */
        { 0 , 0 , 0 , 0 , 0 }  /* 4 */
    };

    printMatrix(gr);

    int *result = solveDijkstra(gr, start);

    /* LOOP
     ******/

    SDL_Event event;
    int loop = 1;
    while (loop) {

        /* CONTRÔLES
        ************/

        if (SDL_PollEvent(&event)) {
            switch (event.type) {
                
                case SDL_QUIT: /* fermeture de la fenêtre */
                    loop = 0;

                case SDL_KEYDOWN: /* interaction clavier */
                    if (event.key.keysym.sym == SDLK_ESCAPE)
                        loop = 0;

                    if (event.key.keysym.sym == 's')
                        printf("s pressed\n");

                    if (event.key.keysym.sym == 'p')
                        printf("p pressed\n");
            }
        }

        /* DESSIN
        *********/

        /* Nettoyer le buffer et afficher un fond blanc */
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(1, 1, 1, 1);

        /* Origine du repère en haut à gauche, de la taille de la fenêtre */
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(0, WINDOW_WIDTH, WINDOW_HEIGHT, 0, 0, 1);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();


        drawNode(0, 100, 100, 255, 0, 0);







        /*
        glBegin(GL_QUADS);
            glColor3ub(0,0,255);
            glVertex2d(-0.75,-0.75);
            glVertex2d(-0.75,0.75);
            glColor3ub(255,0,0);
            glVertex2d(0.75,0.75);
            glVertex2d(0.75,-0.75);
        glEnd();
        */


        /* AFFICHAGE
        ************/

        glFlush();
        SDL_GL_SwapBuffers();

    }

    /* FIN
    ******/

    SDL_Quit();

    return 0;
}