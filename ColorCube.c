#include "windows.h"
#include <GL/glut.h>
int axis;
float angle[2]={0,0};

void init()
{
    glClearColor(1,1,1,0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-200,200,-200,200,-200,200);
    glMatrixMode(GL_MODELVIEW);
    glEnable(GL_DEPTH_TEST);
}
void mymove(int btn,int st,int x,int y)
{
    if(st==GLUT_DOWN&&btn==GLUT_LEFT_BUTTON)
    {
        axis=0;
    }
    if(st==GLUT_DOWN&&btn==GLUT_RIGHT_BUTTON)
    {
        axis=1;
    }
}
void spin()
{
    if(angle[axis]<360)
    {
        angle[axis]+=0.1;
    }
    else
        angle[axis]=0;
}
void display(void)
{
    int x,y,z;
    float i,j,k;
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glRotatef(angle[1],1,0,0);
    glRotatef(angle[0],0,1,0);
    for(x=-80,i=0.4;x<=80;x=x+80,i+=0.2)
    {
        for(y=-80,j=0.4;y<=80;y=y+80,j+=0.2)
        {
            for(z=80,k=0.4;z>=-80;z=z-80,k+=0.2)
            {
                glPushMatrix();
                glTranslatef(x,y,z);
                glColor3f(i,j,k);
                glutSolidCube(50);
                glPopMatrix();
                glEnd();
            }
        }
    }
    glFlush();
    glutSwapBuffers();
    glutPostRedisplay();
}
int main()
{
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutInitWindowSize(600,600);
    glutCreateWindow("Solid Cube");
    init();
    glutIdleFunc(spin);
    glutDisplayFunc(display);
    glutMouseFunc(mymove);
    glutMainLoop();
}
