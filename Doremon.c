#include<windows.h>
#include<GL/glut.h>
#include<math.h>
void init()
{
    glClearColor(1,1,1,0);
    gluOrtho2D(-500,500,-500,500);
}
void circle(int r,int s,int e)
{
    glBegin(GL_LINE_STRIP);
    glColor3f(0,0,0);
    float theta;
    for(int i=s;i<=e;i++)
    {
        theta=(i*3.142)/180;
        glVertex2f(r*cos(theta),r*sin(theta));
    }
    glEnd();
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    //Face(Outer Curve)
    circle(300,-40,218);
    glPushMatrix();
    glTranslatef(0,-20,0);
    //Face(Inner Curve)
    circle(250,-40,61);
    circle(250,119,218);
    glPopMatrix();
    //EyeSection
    glPushMatrix();
    glTranslatef(0,200,0);
    //Left Eye
    glPushMatrix();
    glTranslatef(-61,0,0);
    glScalef(1.2,1,0);
    circle(50,0,360);
    glPopMatrix();
    //Right Eye
    glPushMatrix();
    glTranslatef(61,0,0);
    glScalef(1.2,1,0);
    circle(50,0,360);
    glPopMatrix();
    //EyeBalls
    glPushMatrix();
    //Right Eyeball
    glTranslatef(25,0,0);
    circle(15,0,360);
    glPopMatrix();
    glPushMatrix();
    //Left EyeBall
    glTranslatef(-25,0,0);
    circle(15,0,360);
    glPopMatrix();
    glPopMatrix();
    //Nose
    glPushMatrix();
    glTranslatef(0,135,0);
    circle(32,0,360);
    glPopMatrix();
    glBegin(GL_LINES);
    glVertex2d(0,105);
    glVertex2d(0,-125);
    glEnd();
    //Mouth
    glPushMatrix();
    glTranslatef(0,50,0);
    glScalef(1.199,1,0);
    circle(170,180,360);
    glPopMatrix();
    glPushMatrix();
    glBegin(GL_LINES);
    glVertex2f(-50,0);
    glVertex2f(-230,15);
    glEnd();
    glTranslatef(0,50,0);
    glBegin(GL_LINES);
    glVertex2f(-50,0);
    glVertex2f(-230,25);
    glEnd();
    glTranslatef(0,50,0);
    glBegin(GL_LINES);
    glVertex2f(-50,0);
    glVertex2f(-230,40);
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glBegin(GL_LINES);
    glVertex2f(50,0);
    glVertex2f(230,15);
    glEnd();
    glTranslatef(0,50,0);
    glBegin(GL_LINES);
    glVertex2f(50,0);
    glVertex2f(230,25);
    glEnd();
    glTranslatef(0,50,0);
    glBegin(GL_LINES);
    glVertex2f(50,0);
    glVertex2f(230,40);
    glEnd();
    glPopMatrix();
    glFlush();
}
int main()
{
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(600,600);
    glutCreateWindow("Doremon");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
}
