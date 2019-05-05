#include<windows.h>
#include<GL/glut.h>
#include<math.h>
void circle(int x,int y,int r,int s,int e)
{
    glBegin(GL_POLYGON);
    float theta;
    for(int i=s;i<=e;i++)
    {
        theta=(i*3.142)/180;
        glVertex2f(x+r*cos(theta),y+r*sin(theta));
    }
    glEnd();
}
void init()
{
    glClearColor(1,1,1,0);
    gluOrtho2D(0,1000,0,1000);
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0,0,1);
    circle(250,500,200,0,360);
    glColor3f(0,0.8,1);
    circle(750,500,200,0,360);
    glColor3f(1,1,1);
    circle(180,550,25,0,360);
    glColor3f(1,1,1);
    circle(320,550,25,0,360);
    glColor3f(1,1,1);
    circle(680,550,25,0,360);
    glColor3f(1,1,1);
    circle(820,550,25,0,360);
    glColor3f(1,1,1);
    circle(250,400,25,0,360);
    glColor3f(1,1,1);
    glBegin(GL_TRIANGLES);
    glVertex2f(715,400);
    glVertex2f(785,400);
    glVertex2f(750,365);
    glEnd();
    glFlush();
}
int main()
{
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(600,600);
    glutCreateWindow("Emoji");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
}
