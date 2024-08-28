#include<GL/glut.h>
#include<stdio.h>
#include<math.h>

int n;

void init()
{
   glClearColor(0.0,0.0,0.0,0.0);
   glMatrixMode(GL_PROJECTION);
   gluOrtho2D(0,500,0,500);
}

int round1(double number)
{
   return (number>=0) ? (int)(number+0.5):(int)(number-0.5);
}

void setPixel(GLint x,GLint y)
{
   glBegin(GL_POINTS);
   glVertex2f(x,y);
   glEnd();
}

void LineWithDDA(int x0,int y0,int x1,int y1)
{
   int dy=y1-y0;
   int dx=x1-x0;
   int steps,i;
   float xinc,yinc,x=x0,y=y0;
   if(abs(dx)>abs(dy))
   {
     steps=abs(dx);
   }
   else
   {
     steps=abs(dy);
   }
   xinc=(float)dx/(float)steps;
   yinc=(float)dy/(float)steps;
   setPixel(round1(x),round1(y));
   for(i=0;i<steps;i++)
   {
     x+=xinc;
     y+=yinc;
     setPixel(round1(x),round1(y));
   }
   glutSwapBuffers();
}

int k=1;
int X[10],Y[10];

void mouseClick(int button, int state, int x, int y)
{
   switch(button)
   {
      case GLUT_LEFT_BUTTON:
      if (state == GLUT_DOWN)
      {   
            X[k]=x;
            Y[k]=500-y;
            if(k%2==0)
              LineWithDDA(X[k-1],Y[k-1],X[k],Y[k]);
            else if(k>1 && k%2!=0)
              LineWithDDA(X[k-1],Y[k-1],X[k],Y[k]);
            glutSwapBuffers();
            k++; 
      }

