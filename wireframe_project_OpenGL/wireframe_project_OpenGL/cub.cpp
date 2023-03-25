#include "glos.h"

#include "gl.h"
#include "glu.h"
#include "glaux.h"

static GLfloat alfaX = 0.0f;

double vertices[8][3] = {
    { 1.0f, 1.0f, 1.0f}, //0
    { 1.0f, 1.0f,-1.0f}, //1
    { 1.0f,-1.0f,-1.0f}, //2
    {-1.0f,-1.0f,-1.0f}, //3
    {-1.0f,-1.0f, 1.0f}, //4
    {-1.0f, 1.0f, 1.0f}, //5
    {-1.0f, 1.0f,-1.0f}, //6
    { 1.0f,-1.0f, 1.0f}  //7
};

int indices[12][2] = {
    {5,4},
    {5,0},

    {4,7},
    {7,0},

    {6,5},
    {1,0},

    {3,4},
    {2,7},

    {6,3},
    {6,1},

    {3,2},
    {2,1}
};


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
    glBegin(GL_LINES);
    glBegin(GL_LINES);

    for (int i = 0; i < 12; i += 1) {

        glVertex3f(vertices[indices[i][0]][0], vertices[indices[i][0]][1], vertices[indices[i][0]][2]);
        glVertex3f(vertices[indices[i][1]][0], vertices[indices[i][1]][1], vertices[indices[i][1]][2]);
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
    gluPerspective(2.0, (GLfloat)w / (GLfloat)h, 1.0, 1000.0);
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
