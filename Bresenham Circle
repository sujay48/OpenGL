#include "windows.h"
#include <GL/glut.h>
void init()
{
    glClearColor(1,1,1,0);
    gluOrtho2D(-100,100,-100,100);
}
void plotpixel(int x,int y)
{
    glBegin(GL_POINTS);
    glColor3f(0,0,0);
    glPointSize(5.0);
    glVertex2i(x,y);
    glEnd();
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    float r=50;
    float x=0,y=r;
    float p=5/4-r;
    while(y>x)
    {
        x++;
        if (p<0)
        {
            p+=2*x+1;
        }
        else
        {
            y--;
            p+=2*(x-y)+1;
        }
        plotpixel(x,y);
        plotpixel(x,-y);
        plotpixel(-x,y);
        plotpixel(-x,-y);
        plotpixel(y,x);
        plotpixel(-y,x);
        plotpixel(y,-x);
        plotpixel(-y,-x);
        glFlush();
    }
}
int main()
{
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(600,600);
    glutCreateWindow("Circle Drawing Algorithm");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
}
