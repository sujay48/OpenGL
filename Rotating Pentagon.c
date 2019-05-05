#include "windows.h"
#include <GL/glut.h>
float angle=0;
void init()
{
    glClearColor(1,1,1,0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-300,300,-200,600,-500,500);
    glMatrixMode(GL_MODELVIEW);
    glEnable(GL_DEPTH_TEST);
}
void spin()
{
    if(angle<360)
    {
        angle+=0.1;
    }
    else
        angle=0;
}
void display(void)
{
    int i,j,m;
    float k,l;
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glRotatef(120,1,0,0);
    glRotatef(angle,0,0,1);
    GLUquadricObj *obj = gluNewQuadric();
    glBegin(GL_POLYGON);
    glColor3f(0.37,0.37,1);
    gluCylinder(obj,200,200,30,1000,50);
    glEnd();
    for(i=-30,j=190,k=0.4,l=0.4,m=18;i>=-590;i-=30,j=j-9,k+=0.03,l+=0.03,m=(m+18)%360)
    {
        glPushMatrix();
        glTranslatef(0,0,i);
        glRotatef(m,0,0,1);
        glBegin(GL_POLYGON);
        glColor3f(l,k,1);
        gluCylinder(obj,j,j,30,5,30);
        glEnd();
        glPopMatrix();
    }
    glFlush();
    glutSwapBuffers();
    glutPostRedisplay();
}
int main()
{
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutInitWindowSize(600,600);
    glutCreateWindow("Pentagon");
    init();
    glutIdleFunc(spin);
    glutDisplayFunc(display);
    glutMainLoop();
}
