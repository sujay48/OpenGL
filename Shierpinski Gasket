#include<windows.h>
#include<GL/glut.h>
#include<stdio.h>
float v[][3]={{-1,-0.5,0},{1,-0.5,0},{0,1,0},{0,0,1}};
int n;
void init()
{
    glClearColor(1,1,1,0);
    glOrtho(-2,2,-2,2,0,0);
    glEnable(GL_DEPTH_TEST);
}
void draw(float *a,float *b,float *c)
{
    glVertex2fv(a);
    glVertex2fv(b);
    glVertex2fv(c);
}
void tetra(float *a,float *b,float *c,float *d)
{
    glColor3f(0,1,0);
    draw(a,c,d);
    glColor3f(0,0,1);
    draw(c,d,b);
    glColor3f(1,0.5,1);
    draw(a,b,d);
    glColor3f(1,0,0);
    draw(a,b,c);
}
void divideTetra(float *v0,float *v1,float *v2,float *v3,int n)
{
    float m[6][3];
    int i;
    if(n>0)
    {
        for(i=0;i<3;i++)
        {
            m[0][i]=(v0[i]+v2[i])/2;
            m[1][i]=(v0[i]+v3[i])/2;
            m[2][i]=(v0[i]+v1[i])/2;
            m[3][i]=(v1[i]+v3[i])/2;
            m[4][i]=(v1[i]+v2[i])/2;
            m[5][i]=(v3[i]+v2[i])/2;
        }
        divideTetra(m[1],m[3],m[5],v3,n-1);
        divideTetra(v0,m[2],m[0],m[1],n-1);
        divideTetra(m[2],v1,m[4],m[3],n-1);
        divideTetra(m[0],m[4],v2,m[5],n-1);
    }
    else
    {
        tetra(v0,v1,v2,v3);
    }
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glBegin(GL_TRIANGLES);
    divideTetra(v[0],v[1],v[2],v[3],n);
    glEnd();
    glFlush();
}
int main()
{
    printf("Enter the no of divisions\n");
    scanf("%d",&n);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_DEPTH);
    glutInitWindowSize(600,600);
    glutCreateWindow("Sierpinski Gasket");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
}
