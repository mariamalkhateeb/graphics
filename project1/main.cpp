#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <windows.h>
#include<math.h>

void display();
void reshape(int w,int h);
 void timer(int);
 void timer2(int);

void init(){
   // glClearColor(0.74902,0.847059,0.847059,1.0);
    glClearColor(0.68627451,0.93333333,0.93333333,1.0);
}
int main(int argc,char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB);

    glutInitWindowSize(1200,800);
    glutInitWindowPosition(200,0);
    glutCreateWindow("20100067/20109328");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
       glutTimerFunc(0,timer,0);

    init();
    glutMainLoop();
}

float s_x_step=0; //counter for sabara animation
float x_step=-4.5;//counter begin from circle center points for circle animation on x axis
float y_step=-2.5;//counter begin from circle center points for circle animation on y axis
float x_position=0.0; // counter for increasing radius
int state=1;//for move from states
 int s_state=1;//for move from states for sabara

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
 glLineWidth(2.0);


    //line in bottom
    glColor3f(0,0,0);
    glPushMatrix();
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glVertex2f(-7,-6);
    glVertex2f(7,-6);
    glEnd();
    glPopMatrix();

    //grass
    glPushMatrix();
    glLineWidth(2.0);
    glBegin(GL_POLYGON);
    glColor3f(0.19607843,0.80392157,0.19607843);
    glVertex2f(-1,-5);
    glVertex2f(-1.2,-6);
    glVertex2f(-0.8,-6);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glLineWidth(2.0);
    glBegin(GL_POLYGON);
    glVertex2f(-0.5,-5);
    glVertex2f(-0.8,-6);
    glVertex2f(-0.3,-6);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glLineWidth(2.0);
    glBegin(GL_POLYGON);
    glVertex2f(0,-5);
    glVertex2f(-0.2,-6);
    glVertex2f(0.2,-6);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glLineWidth(2.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.5,-5);
    glVertex2f(0.2,-6);
    glVertex2f(0.7,-6);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glLineWidth(2.0);
    glBegin(GL_POLYGON);
    glVertex2f(-2,-5);
    glVertex2f(-2.2,-6);
    glVertex2f(-1.8,-6);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glLineWidth(2.0);
    glBegin(GL_POLYGON);
    glVertex2f(-1.5,-5);
    glVertex2f(-1.8,-6);
    glVertex2f(-1.3,-6);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glLineWidth(2.0);
    glBegin(GL_POLYGON);
    glVertex2f(1,-5);
    glVertex2f(1.2,-6);
    glVertex2f(0.8,-6);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glLineWidth(2.0);
    glBegin(GL_POLYGON);
    glVertex2f(1.5,-5);
    glVertex2f(1.2,-6);
    glVertex2f(1.7,-6);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glBegin(GL_POLYGON);
    glLineWidth(2.0);
    glVertex2f(2,-5);
    glVertex2f(2.2,-6);
    glVertex2f(1.8,-6);
    glEnd();
    glPopMatrix();

    //sun
    glPushMatrix();
    glLineWidth(2.0);
    glRotatef(180,0,1,0);

    glBegin(GL_POLYGON);
    glColor3f(255,255,0);
    for(int i=0;i<360;i++){
        double angle =i*3.14/180; //convert from degree to radian
         glVertex2f(6+1.5*cos(angle),7.5+1.5*sin(angle));
    }
    glEnd();
    glPopMatrix();




//top cloud
glPushMatrix();
glLineWidth(2.0);
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    for(int i=0;i<360;i++){
        double angle =i*3.14/180; //convert from degree to radian
         glVertex2f(-4+1*cos(angle),8+1*sin(angle));
    }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    for(int i=0;i<360;i++){
        double angle =i*3.14/180; //convert from degree to radian
         glVertex2f(-4+1*cos(angle),7+1*sin(angle));
    }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glLineWidth(2.0);
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    for(int i=0;i<360;i++){
        double angle =i*3.14/180; //convert from degree to radian
         glVertex2f(-5+1*cos(angle),8+1*sin(angle));
    }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glLineWidth(2.0);
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    for(int i=0;i<360;i++){
        double angle =i*3.14/180; //convert from degree to radian
         glVertex2f(-5+1*cos(angle),7+1*sin(angle));
    }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glLineWidth(2.0);
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    for(int i=0;i<360;i++){
        double angle =i*3.14/180; //convert from degree to radian
         glVertex2f(-6+1*cos(angle),8+1*sin(angle));
    }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glLineWidth(2.0);
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    for(int i=0;i<360;i++){
        double angle =i*3.14/180; //convert from degree to radian
         glVertex2f(-6+1*cos(angle),7+1*sin(angle));
    }
    glEnd();
    glPopMatrix();


    //bottom cloud
    glPushMatrix();
    glLineWidth(2.0);
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    for(int i=0;i<360;i++){
        double angle =i*3.14/180; //convert from degree to radian
         glVertex2f(1+1*cos(angle),5+1*sin(angle));
    }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glLineWidth(2.0);
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    for(int i=0;i<360;i++){
        double angle =i*3.14/180; //convert from degree to radian
         glVertex2f(1+1*cos(angle),4+1*sin(angle));
    }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glLineWidth(2.0);
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    for(int i=0;i<360;i++){
        double angle =i*3.14/180; //convert from degree to radian
         glVertex2f(0+1*cos(angle),5+1*sin(angle));
    }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glLineWidth(2.0);
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    for(int i=0;i<360;i++){
        double angle =i*3.14/180; //convert from degree to radian
         glVertex2f(0+1*cos(angle),4+1*sin(angle));
    }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glLineWidth(2.0);
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    for(int i=0;i<360;i++){
        double angle =i*3.14/180; //convert from degree to radian
         glVertex2f(-1+1*cos(angle),5+1*sin(angle));
    }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glLineWidth(2.0);
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    for(int i=0;i<360;i++){
        double angle =i*3.14/180; //convert from degree to radian
         glVertex2f(-1+1*cos(angle),4+1*sin(angle));
    }
    glEnd();
    glPopMatrix();



    //tall sabara
    glPushMatrix();
    glLineWidth(2.0);
    //glRotatef(360,1,0,0);
    glTranslated(s_x_step,0,0);
    glBegin(GL_POLYGON);

    glColor3f(0.19607843,0.80392157,0.19607843);
    for(int i=0;i<180;i++){
        double angle =i*3.14/180; //convert from degree to radian
         glVertex2f(4.5+1*cos(angle),1+1*sin(angle));//4.5 >>x point , 1 >>y point
    }
    glVertex2f(4,-4);
    glVertex2f(5,-4);

    glEnd();
    //glPopMatrix();


        //forks of top sabara
           // glPushMatrix();
    glLineWidth(6.0);
    glBegin(GL_LINES);
    glColor3f(0,0,0);

    glVertex2f(3.6,1.4);
    glVertex2f(3.3,1.65);

    glVertex2f(4.5,2);
    glVertex2f(4.5,2.55);

    glVertex2f(5.4,1.4);
    glVertex2f(5.7,1.65);

    glVertex2f(5.3,-0.7);
    glVertex2f(5.7,-0.7);

    glVertex2f(3.7,-0.7);
    glVertex2f(3.3,-0.7);

    glVertex2f(5.2,-2);
    glVertex2f(5.6,-2);

    glVertex2f(3.8,-2);
    glVertex2f(3.4,-2);
    glEnd();

    // base of tall sabara
  //  glPushMatrix();
    glLineWidth(2.0);
    glBegin(GL_LINE_STRIP);
    glColor3f(0,0,0);
    glVertex2f(3.5,-5);
    glVertex2f(4,-6);
    glVertex2f(5,-6);
    glVertex2f(5.5,-5);
    glEnd();
 //   glPopMatrix();

   // glPushMatrix();
    glLineWidth(2.0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(6,-5);
    glVertex2f(6,-4);
    glVertex2f(3,-4);
    glVertex2f(3,-5);
    glEnd();
   // glPopMatrix();

    //eyes of tall sabara
   // glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(0,0,0);
    for(int i=0;i<360;i++){
        double angle =i*3.14/180; //convert from degree to radian
         glVertex2f(4+0.1*cos(angle),0.5+0.1*sin(angle));
    }
    glEnd();
    //glPopMatrix();

   // glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(0,0,0);
    for(int i=0;i<360;i++){
        double angle =i*3.14/180; //convert from degree to radian
         glVertex2f(5+0.1*cos(angle),0.5+0.1*sin(angle));
    }
    glEnd();
   // glPopMatrix();






        //mouth of tall sabara
   // glPushMatrix();

    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex2f(4.3,-2);
    glVertex2f(4.7,-2);
    glEnd();
    glPopMatrix();

    //short sabara
    glPushMatrix();
    glLineWidth(2.0);
    glRotatef(360,1,0,0);
    glBegin(GL_POLYGON);
    glColor3f(0.19607843,0.80392157,0.19607843);
    for(int i=0;i<180;i++){
        double angle =i*3.14/180; //convert from degree to radian
         glVertex2f(-4.5+1*cos(angle),-0.5+1*sin(angle));
    }
    glVertex2f(-5,-4);
    glVertex2f(-4,-4);

    glEnd();
   // glPopMatrix();







    //forks of bottom sabara

   // glPushMatrix();
    glLineWidth(6.0);
    glBegin(GL_LINES);
    glColor3f(0,0,0);

    glVertex2f(-3.3,0.5);
    glVertex2f(-3.67,0);

    glVertex2f(-4.5,0.5);
    glVertex2f(-4.5,1);

    glVertex2f(-5.32,0);
    glVertex2f(-5.6,0.5);

    glVertex2f(-5.23,-2);
    glVertex2f(-5.6,-2);

    glVertex2f(-3.73,-2);
    glVertex2f(-3.4,-2);

    glVertex2f(-5.10,-3);
    glVertex2f(-5.5,-3);

    glVertex2f(-3.88,-3);
    glVertex2f(-3.5,-3);

    glEnd();
    //glPopMatrix();





    //base of short sabara
   // glPushMatrix();
    glBegin(GL_LINE_STRIP);
    glVertex2f(-3.5,-5);
    glVertex2f(-4,-6);
    glVertex2f(-5,-6);
    glVertex2f(-5.5,-5);
    glEnd();
    //glPopMatrix();

    //glPushMatrix();
    glBegin(GL_LINE_LOOP);
    glVertex2f(-6,-5);
    glVertex2f(-6,-4);
    glVertex2f(-3,-4);
    glVertex2f(-3,-5);
    glEnd();
    //glPopMatrix();

    //eyes of short sabara
    //glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(0,0,0);
    for(int i=0;i<360;i++){
        double angle =i*3.14/180; //convert from degree to radian
         glVertex2f(-4+0.1*cos(angle),-1+0.1*sin(angle));
    }
    glEnd();
  //  glPopMatrix();

   //glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(0,0,0);
    for(int i=0;i<360;i++){
        double angle =i*3.14/180; //convert from degree to radian
         glVertex2f(-5+0.1*cos(angle),-1+0.1*sin(angle));
    }
    glEnd();
   // glPopMatrix();

    //mouth of short sabara
   // glPushMatrix();
    glBegin(GL_POLYGON);
        for(int i=0;i<360;i++){
        double angle =i*3.14/180; //convert from degree to radian
         glVertex2f(-4.5+0.1*cos(angle),-2.5+0.1*sin(angle));
    }

    glEnd();
    glPopMatrix();







    // circle animation
    glPushMatrix();
    glTranslated(x_step,y_step,0);
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.0,1.0);
        for(int i=0;i<360;i++){
        double angle =i*3.14/180; //convert from degree to radian
        // glVertex2f(-4.5+x_position*cos(angle),-2.5+x_position*sin(angle));
        glVertex2f(x_position*cos(angle),x_position*sin(angle));
    }

    glEnd();
    glPopMatrix();
    glFlush();

}
void reshape(int w,int h){

    glViewport(0,0,(GLsizei)w,(GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-10,10,-10,10);
    glMatrixMode(GL_MODELVIEW);
}



 void timer(int){//frame for circle animation
     glutPostRedisplay();
glutTimerFunc(10000/60,timer,0);
switch(state){
   case 1:
 if(x_position<1)
        x_position+=0.1;
 else
    state=-1;
    break;
 case -1:
    if(x_step<3.5&&y_step<1.5){
        x_step+=0.5;y_step+=0.3;}

      else
    state=0;
    break;
     case 0:
    if(x_step>-3.5&&y_step>-1.5){
       glutTimerFunc(0,timer2,0);

  s_x_step=0;
 x_step=-4.5;
 y_step=-2.5;
 x_position=0.1;
  s_state=1;
    state=1;
    break;}

}

}
 void timer2(int){ //frame for sabara animation
     glutPostRedisplay();
glutTimerFunc(10000/60,timer2,0);

switch(s_state){
    case 1:
    if(s_x_step<1){
     s_x_step+=1;}
     else
     s_state=-1;
     break;
    case -1:
   if(s_x_step>-1){
 s_x_step-=1;

 break;
  }
   }



}
