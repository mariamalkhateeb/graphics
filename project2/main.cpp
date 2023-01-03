#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include <stdlib.h>
#include <windows.h>
#include <math.h>
#include<iostream>
#include<mmsystem.h>
float angle_player_1=0.0;
float angle_player_2=0.0;

//------------------------------  SoundFunc  ---------------------------------

void Sound(){
   sndPlaySound("mixkit-retro-game-emergency-alarm-1000.wav",SND_ASYNC);
}

//------------------------------  StarFunc  ---------------------------------
void StarFunc(){
   // glClearColor(1,1,1,0);
    glClear        (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_COLOR_BUFFER_BIT);
    glRotatef       (0.1,1,1,0);

    glPushMatrix();
    glTranslatef(0,0.5,0);

    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,0.0);

    glVertex3f(-0.5,-0.5,-0.5);
    glVertex3f(0.5,-0.5,-0.5);
    glVertex3f(0.0,0.5,0.0);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0,1.0,0.0);

    glVertex3f(-0.5,-0.5,0.5);
    glVertex3f(0.5,-0.5,0.5);
    glVertex3f(0.0,0.5,0.0);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,1.0);

    glVertex3f(-0.5,-0.5,-0.5);
    glVertex3f(-0.5,-0.5,0.5);
    glVertex3f(0.0,0.5,0.0);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,0.0);

    glVertex3f(0.5,-0.5,-0.5);
    glVertex3f(0.5,-0.5,0.5);
    glVertex3f(0.0,0.5,0.0);

    glEnd();


    glBegin(GL_POLYGON);
    glColor3f(1.0,1.0,0.0);

    glVertex3f(0.5,-0.5,-0.5);
    glVertex3f(0.5,-0.5,0.5);
    glVertex3f(0.0,0.5,0.0);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0,1.0,1.0);

    glVertex3f(-0.5,-0.5,0.5);
    glVertex3f(-0.5,-0.5,-0.5);
    glVertex3f(0.0,0.5,0.0);

    glEnd();

    glPopMatrix();



    glPushMatrix();
    glTranslatef(0,-0.5,0);
    glRotatef(180,0,0,1);

    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,0.0);

    glVertex3f(-0.5,-0.5,-0.5);
    glVertex3f(0.5,-0.5,-0.5);
    glVertex3f(0.0,0.5,0.0);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0,1.0,0.0);

    glVertex3f(-0.5,-0.5,0.5);
    glVertex3f(0.5,-0.5,0.5);
    glVertex3f(0.0,0.5,0.0);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,1.0);

    glVertex3f(-0.5,-0.5,-0.5);
    glVertex3f(-0.5,-0.5,0.5);
    glVertex3f(0.0,0.5,0.0);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,0.0);

    glVertex3f(0.5,-0.5,-0.5);
    glVertex3f(0.5,-0.5,0.5);
    glVertex3f(0.0,0.5,0.0);

    glEnd();


    glBegin(GL_POLYGON);
    glColor3f(1.0,1.0,0.0);

    glVertex3f(0.5,-0.5,-0.5);
    glVertex3f(0.5,-0.5,0.5);
    glVertex3f(0.0,0.5,0.0);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0,1.0,1.0);

    glVertex3f(-0.5,-0.5,0.5);
    glVertex3f(-0.5,-0.5,-0.5);
    glVertex3f(0.0,0.5,0.0);

    glEnd();

    glPopMatrix();





    glPushMatrix();
    glTranslatef(-0.5,0,0);
    glRotatef(90,0,0,1);

    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,0.0);

    glVertex3f(-0.5,-0.5,-0.5);
    glVertex3f(0.5,-0.5,-0.5);
    glVertex3f(0.0,0.5,0.0);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0,1.0,0.0);

    glVertex3f(-0.5,-0.5,0.5);
    glVertex3f(0.5,-0.5,0.5);
    glVertex3f(0.0,0.5,0.0);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,1.0);

    glVertex3f(-0.5,-0.5,-0.5);
    glVertex3f(-0.5,-0.5,0.5);
    glVertex3f(0.0,0.5,0.0);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,0.0);

    glVertex3f(0.5,-0.5,-0.5);
    glVertex3f(0.5,-0.5,0.5);
    glVertex3f(0.0,0.5,0.0);

    glEnd();


    glBegin(GL_POLYGON);
    glColor3f(1.0,1.0,0.0);

    glVertex3f(0.5,-0.5,-0.5);
    glVertex3f(0.5,-0.5,0.5);
    glVertex3f(0.0,0.5,0.0);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0,1.0,1.0);

    glVertex3f(-0.5,-0.5,0.5);
    glVertex3f(-0.5,-0.5,-0.5);
    glVertex3f(0.0,0.5,0.0);

    glEnd();

    glPopMatrix();





    glPushMatrix();
    glTranslatef(0.5,0,0);
    glRotatef(-90,0,0,1);

    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,0.0);

    glVertex3f(-0.5,-0.5,-0.5);
    glVertex3f(0.5,-0.5,-0.5);
    glVertex3f(0.0,0.5,0.0);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0,1.0,0.0);

    glVertex3f(-0.5,-0.5,0.5);
    glVertex3f(0.5,-0.5,0.5);
    glVertex3f(0.0,0.5,0.0);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,1.0);

    glVertex3f(-0.5,-0.5,-0.5);
    glVertex3f(-0.5,-0.5,0.5);
    glVertex3f(0.0,0.5,0.0);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,0.0);

    glVertex3f(0.5,-0.5,-0.5);
    glVertex3f(0.5,-0.5,0.5);
    glVertex3f(0.0,0.5,0.0);

    glEnd();


    glBegin(GL_POLYGON);
    glColor3f(1.0,1.0,0.0);

    glVertex3f(0.5,-0.5,-0.5);
    glVertex3f(0.5,-0.5,0.5);
    glVertex3f(0.0,0.5,0.0);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0,1.0,1.0);

    glVertex3f(-0.5,-0.5,0.5);
    glVertex3f(-0.5,-0.5,-0.5);
    glVertex3f(0.0,0.5,0.0);

    glEnd();

    glPopMatrix();



    glFlush();
    glutSwapBuffers();
    glutPostRedisplay();


}
//------------------------------  KeyBoardFunc  ---------------------------------
void keyBoard(int key,int x,int y){
    if(key==GLUT_KEY_UP)
        angle_player_1 +=.03;
    else if(key==GLUT_KEY_DOWN)
        angle_player_1 -=.3;

    else if(key==119) //w button
        angle_player_2 +=.3;

    else if(key==115) //s button
        angle_player_2 -=.3;


}

//------------------------------  CubeFunc  ---------------------------------
void CubeFunc(){

    //glClearColor(1,1,1,0);
    glClear        (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_COLOR_BUFFER_BIT);
    glTranslatef(0,angle_player_1,0);
    //glRotatef       (.1,0,1,0);

    //back
    glPopMatrix();
    glBegin(GL_POLYGON);
    glColor3f(0.0,1.0,0.0);

    glVertex3f(0.5,-0.5,0.5);
    glVertex3f(0.5,0.5,0.5);
    glVertex3f(-0.5,0.5,0.5);
    glVertex3f(-0.5,-0.5,0.5);

    glEnd();

    //front
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,1.0);

    glVertex3f(0.5,-0.5,-0.5);
    glVertex3f(0.5,0.5,-0.5);
    glVertex3f(-0.5,0.5,-0.5);
    glVertex3f(-0.5,-0.5,-0.5);

    glEnd();

    //right
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,1.0);

    glVertex3f(0.5,-0.5,-0.5);
    glVertex3f(0.5,0.5,-0.5);
    glVertex3f(0.5,0.5,0.5);
    glVertex3f(0.5,-0.5,0.5);

    glEnd();

    //left

    glBegin(GL_POLYGON);
    glColor3f(0.0,1.0,0.0);

    glVertex3f(0.5,-0.5,0.5);
    glVertex3f(-0.5,0.5,0.5);
    glVertex3f(-0.5,0.5,-0.5);
    glVertex3f(-0.5,-0.5,-0.5);

    glEnd();

    //top
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,0.0);

    glVertex3f(0.5,0.5,0.5);
    glVertex3f(0.5,0.5,-0.5);
    glVertex3f(-0.5,0.5,-0.5);
    glVertex3f(-0.5,0.5,0.5);

    glEnd();

    //bottom
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,0.0);

    glVertex3f(0.5,-0.5,-0.5);
    glVertex3f(0.5,-0.5,0.5);
    glVertex3f(-0.5,-0.5,0.5);
    glVertex3f(-0.5,-0.5,-0.5);

    glEnd();


    glFlush();
    glutSwapBuffers();
    glutPostRedisplay();

}


//------------------------------  reshapeFunc  ---------------------------------

void reshapeFunc (int w, int h)
{
    glViewport(0,0,(GLsizei)w,(GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
   // gluPerspective (60.0, (GLdouble)w / (GLdouble)h, 0.5, 20.0);
    glMatrixMode(GL_MODELVIEW);
}

//------------------------------  display   -------------------------------
int zRotated=0;
void display (void)
{
    CubeFunc();
     // StarFunc();
    //PlaySound(TEXT("mixkit-retro-game-emergency-alarm-1000.wav") ,NULL, SND_FILENAME|SND_ASYNC|SND_LOOP);

}

//--------------------------------  idleFunc  ----------------------------------

void idleFunc (void)
{
    zRotated += 1;
    glutPostRedisplay();
}

void texture (void){

const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);


}

//----------------------------------  main  ------------------------------------


int main (int argc, char **argv)
{

    glutInit               (&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize     (800, 800);
    glutInitWindowPosition (100,100);
    glutCreateWindow       ("20100067/20109328");
    //x-y-z axis
    glOrtho(-10,10,-10,10,-10,10);

    Sound();
    glClearColor (1.0, 1.0, 1.0, 0.0);
    glRotatef(1,1,0,0);

    glutDisplayFunc (display);
    glutSpecialFunc(keyBoard);

   glutReshapeFunc (reshapeFunc);
    glutIdleFunc    (idleFunc);

    glClearColor(1,1,1,1);
   texture();

    glutMainLoop();
}
