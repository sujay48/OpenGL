#include<windows.h>
#include<GL/glut.h>
#include<stdio.h>
int x0,y0,x1,y1,x,y;
void init()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0,0,0,1);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-100,100,-100,100);
}
void plotpixel(int x,int y)
{
    glBegin(GL_POINTS);
    glVertex2i(x,y);
    glEnd();
}
void drawline(int x0,int y0,int x,int y)
{
    int dx,dy,pk,incx,incy,i;
    dx=x1-x0;
    dy=y1-y0;
    if(dx<0)
        dx=-dx;
    if(dy<0)
        dy=-dy;
    incx=1;
    if(x1<0)
        incx=-1;
    incy=1;
    if(y1<y0)
        incy=-1;
    x=x0;
    y=y0;
    plotpixel(x,y);
    pk=2*dy-dx;
    for(i=0;i<dx;i++)
    {
        if(pk<0)
        {
            pk+=2*dy;
        }
        else
        {
            y=y+incy;
            pk+=2*(dy-dx);
        }
        x=x+incx;
        plotpixel(x,y);
    }
    plotpixel(x,y);
    for(int i=0;i<dy;i++)
    {
        if(pk<0)
        {
            x=x+incx;
            pk=pk+2*dx;
        }
    }
}
void display()
{
    drawline(x0,y0,x1,y1);
    glFlush();
}
int main(int args,char** argv)
{
    printf("Enter x0,y0,x1,y1\n");
    scanf("%d %d %d %d",&x0,&y0,&x1,&y1);
    glutInit(&args,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Bresenham's Line Algorithm");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
