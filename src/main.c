#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glut.h>

#include "graph.h"

int WINDOW_WIDTH = 600;
int WINDOW_HEIGHT = 600;
int BIT_PER_PIXEL = 32;
char* WINDOW_TITLE = "Dijkstra Visualizer";

int main() {

    /* INITIALISATION SDL
    *********************/

    SDL_Init(SDL_INIT_VIDEO);
    SDL_Surface *screen = SDL_SetVideoMode(
        WINDOW_WIDTH, WINDOW_HEIGHT, BIT_PER_PIXEL, SDL_OPENGL);
    SDL_WM_SetCaption(WINDOW_TITLE, 0);


    /* GRAPHE
     ********/

    int gr[NNODES][NNODES] = {
       /* 0   1   2   3   4 */
        {  0, 4 , 0 , 0 , 0 }, /* 0 */
        {  0, 0 , 13, 7 , 0 }, /* 1 */
        {  0, 0 , 0 , 0 , 4 }, /* 2 */
        {  0, 0 , 3 , 0 , 9 }, /* 3 */
        {  0, 0 , 0 , 0 , 0 }  /* 4 */
    };

    printMatrix(gr);
    
    int *result = solveDijkstra(gr, 0);

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

        glClear(GL_COLOR_BUFFER_BIT);

        glBegin(GL_QUADS);
            glColor3ub(0,0,255);
            glVertex2d(-0.75,-0.75);
            glVertex2d(-0.75,0.75);
            glColor3ub(255,0,0);
            glVertex2d(0.75,0.75);
            glVertex2d(0.75,-0.75);
        glEnd();


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