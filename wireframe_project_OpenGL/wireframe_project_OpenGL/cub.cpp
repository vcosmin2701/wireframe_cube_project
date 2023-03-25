#include "glos.h"

#include "gl.h"
#include "glu.h"
#include "glaux.h"

static GLfloat alfaX = 0.0f;
static GLfloat alfaY = 0.0f;
static GLfloat alfaZ = 0.0f;


void myInit() {
    glClearColor(0.1f, 0.1f, 0.1f, 1.0);
}

void CALLBACK RotesteXStanga()
{
    alfaX = alfaX - 10;
}

void CALLBACK RotesteXDreapta()
{
    alfaX = alfaX + 10;
}


void CALLBACK RotesteYStanga()
{
    alfaY = alfaY - 10;
}

void CALLBACK RotesteYDreapta()
{
    alfaY = alfaY + 10;
}

void CALLBACK RotesteZStanga()
{
    alfaZ = alfaZ - 10;
}

void CALLBACK RotesteZDreapta()
{
    alfaZ = alfaZ + 10;
}

void CALLBACK display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glLoadIdentity();
    glTranslatef(0, 0, -500.0);
    glRotatef(30, 1.0, 1.0, 0.0);
    glRotatef(alfaX, 1.0, 0.0, 0.0);
    glRotatef(alfaY, 0.0, 1.0, 0.0);
    glRotatef(alfaZ, 0.0, 0.0, 1.0);

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glColor3f(1.0f, 0.0f, 0.0f);
    
    
    glBegin(GL_TRIANGLES);
    //Back
    glVertex3f(100.0f, -100.0f, -100.0f);
    glVertex3f(100.0f, 100.0f, -100.0f);
    glVertex3f(-100.0f, -100.0f, -100.0f);
    glVertex3f(-100.0f, -100.0f, -100.0f);
    glVertex3f(-100.0f, 100.0f, -100.0f);
    glVertex3f(100.0f, 100.0f, -100.0f);
    //Front
    glVertex3f(100.0f, -100.0f, 100.0f);
    glVertex3f(100.0f, 100.0f, 100.0f);
    glVertex3f(-100.0f, -100.0f, 100.0f);
    glVertex3f(-100.0f, -100.0f, 100.0f);
    glVertex3f(-100.0f, 100.0f, 100.0f);
    glVertex3f(100.0f, 100.0f, 100.0f);
    //Top
    glVertex3f(100.0f, 100.0f, 100.0f);
    glVertex3f(100.0f, 100.0f, -100.0f);
    glVertex3f(-100.0f, 100.0f, 100.0f);
    glVertex3f(-100.0f, 100.0f, 100.0f);
    glVertex3f(-100.0f, 100.0f, -100.0f);
    glVertex3f(100.0f, 100.0f, -100.0f);
    //Bottom
    glVertex3f(100.0f, -100.0f, 100.0f);
    glVertex3f(100.0f, -100.0f, -100.0f);
    glVertex3f(-100.0f, -100.0f, 100.0f);
    glVertex3f(-100.0f, -100.0f, 100.0f);
    glVertex3f(-100.0f, -100.0f, -100.0f);
    glVertex3f(100.0f, -100.0f, -100.0f);
    //Left
    glVertex3f(100.0f, -100.0f, 100.0f);
    glVertex3f(100.0f, -100.0f, -100.0f);
    glVertex3f(100.0f, 100.0f, -100.0f);
    glVertex3f(100.0f, 100.0f, -100.0f);
    glVertex3f(100.0f, 100.0f, 100.0f);
    glVertex3f(100.0f, -100.0f, 100.0f);
    //Right
    glVertex3f(-100.0f, -100.0f, 100.0f);
    glVertex3f(-100.0f, -100.0f, -100.0f);
    glVertex3f(-100.0f, 100.0f, -100.0f);
    glVertex3f(-100.0f, 100.0f, -100.0f);
    glVertex3f(-100.0f, 100.0f, 100.0f);
    glVertex3f(-100.0f, -100.0f, 100.0f);

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
    auxInitWindow("My CUBE");
    myInit();
    auxKeyFunc(AUX_q, RotesteXStanga);
    auxKeyFunc(AUX_a, RotesteXDreapta);

    auxKeyFunc(AUX_w, RotesteYStanga);
    auxKeyFunc(AUX_s, RotesteYDreapta);

    auxKeyFunc(AUX_e, RotesteZStanga);
    auxKeyFunc(AUX_d, RotesteZDreapta);

    auxReshapeFunc(myReshape);
    auxMainLoop(display);
    return(0);
}
