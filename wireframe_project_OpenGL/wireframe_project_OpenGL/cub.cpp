#include "glos.h"

#include "gl.h"
#include "glu.h"
#include "glaux.h"

static GLfloat alfaX = 0.0f;

void myInit() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
}

void CALLBACK RotesteXStanga()
{
    alfaX = alfaX - 10;
}

void CALLBACK RotesteXDreapta()
{
    alfaX = alfaX + 10;
}

void CALLBACK display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glLoadIdentity();
    glTranslatef(0, 0, -500.0);
    glRotatef(30, 1.0, 1.0, 0.0);
    glRotatef(alfaX, 1.0, 0.0, 0.0);

    glColor3f(1, 0, 0);
    glBegin(GL_QUADS);
    {
        glVertex3f(-100.0f, 100.0f, -100.0f);
        glVertex3f(-100.0f, -100.0f, -100.0f);
        glVertex3f(100.0f, -100.0f, -100.0f);
        glVertex3f(100.0f, 100.0f, -100.0f);
    }
    glEnd();

    glFlush();
}

void CALLBACK myReshape(GLsizei w, GLsizei h)
{
    if (!h) return;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (GLfloat)w / (GLfloat)h, 1.0, 1000.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
    auxInitDisplayMode(AUX_SINGLE | AUX_RGB);
    auxInitPosition(0, 0, 800, 600);
    auxInitWindow("Un inceput de cub");
    myInit();
    auxKeyFunc(AUX_q, RotesteXStanga);
    auxKeyFunc(AUX_w, RotesteXDreapta);

    auxReshapeFunc(myReshape);
    auxMainLoop(display);
    return(0);
}
