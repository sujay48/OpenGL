#include<windows.h>
#include<GL/glut.h>
#include<math.h>
void init()
{
    glClearColor(1,1,1,0);
    gluOrtho2D(0,1000,0,1000);
}
void elipse(int x,int y,int m,int n,int s,int e)
{
    glBegin(GL_LINE_STRIP);
    float theta;
    for(int i=s;i<=e;i++)
    {
        theta=(i*3.142)/180;
        glVertex2f(x+m*cos(theta),y+n*sin(theta));
    }
    glEnd();
}
void circle(int x,int y,int r,int s,int e)
{
    glBegin(GL_LINE_STRIP);
    float theta;
    for(int i=s;i<=e;i++)
    {
        theta=(i*3.142)/180;
        glVertex2f(x+r*cos(theta),y+r*sin(theta));
    }
    glEnd();
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0,0,0);
    circle(250,725,150,-20,285);
    circle(750,725,150,-105,200);
    circle(500,450,250,65,117);
    circle(500,450,250,149,270);
    circle(500,450,250,-90,33);
    elipse(450,525,28,50,0,360);
    elipse(550,525,28,50,0,360);
    elipse(545,504,11,21,0,360);
    elipse(457,504,11,21,0,360);
    elipse(500,397,50,28,0,360);
    elipse(500,355,150,90,190,350);
    glFlush();
}
int main()
{
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(600,600);
    glutCreateWindow("Mickey Mouse");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
}
