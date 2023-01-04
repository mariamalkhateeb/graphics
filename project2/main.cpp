#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <math.h>
#include<iostream>
#include<mmsystem.h>

float xRotated = 90.0, yRotated = 0.0, zRotated = 0.0;
float angle_player_1=0.0;
float angle_player_2=0.0;
static char score_1[20], score_2[20];
int player1_score = 0, player2_score = 0;


//------------------------------  KeyBoardFunc  ---------------------------------
void keyBoard(unsigned char key,int x,int y){
    if(key=='l'){
        if(angle_player_1<3.0)//up player1
            {
             angle_player_1 +=0.3;
        }
        glutPostRedisplay();
    }
    else if(key=='o' ) //down player1
        {
        if(angle_player_1>-3.0){
            angle_player_1 -=0.3;

        }
        glutPostRedisplay();
    }
    else if(key=='w') //up player2
    {
        if(angle_player_2<3.0){
            angle_player_2 +=0.3;
        }
        glutPostRedisplay();
    }
    else if(key=='s') //down player2
    {
        if(angle_player_2>-3.0){
            angle_player_2 -=0.3;
        }
        glutPostRedisplay();
    }
    glutPostRedisplay();
}

//----------------------------- draw text on screen ----------------------------
void drawStrokeText(char*string, int x, int y, int z)
{
    char *c;
    glPushMatrix();
    //glTranslatef(x, y+8,z);
    // glScalef(0.09f,-0.08f,z);
    for (c=string; *c != '\0'; c++)
    {
        glutStrokeCharacter(GLUT_STROKE_ROMAN , *c);
    }
    glPopMatrix();
}

//------------------------------  ScoreFunc  ---------------------------------

void scoreFunc(){
    // draw the score on the left for player 1
    snprintf (score_1, sizeof(score_1), "%d", player1_score);
    drawStrokeText(score_1, -3, 8, 0);

    // draw the score on the left for player 2
    snprintf (score_2, sizeof(score_2), "%d", player2_score);
    drawStrokeText(score_2, 3, 8, 0);

    // swap the current frame with the drawn frame
 glutPostRedisplay();
   // glutSwapBuffers();
    //glFlush();
}
//------------------------------  SoundFunc  ---------------------------------

void Sound(){
   //sndPlaySound("mixkit-retro-game-emergency-alarm-1000.wav",SND_ASYNC);
   PlaySound(TEXT("mixkit-retro-game-emergency-alarm-1000.wav") ,NULL, SND_FILENAME|SND_ASYNC|SND_LOOP);
}

//------------------------------  reshapeFunc  ---------------------------------

void reshapeFunc (int w, int h)
{
    glViewport(0,0,(GLsizei)w,(GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glFrustum(-1,1,-1,1,2,10);
    glLoadIdentity();
    gluPerspective (40.0, (GLdouble)w / (GLdouble)h, 0.001, 1000.0);
    glMatrixMode(GL_MODELVIEW);
}
//------------------------------  TableFunc  ---------------------------------
void Table(){
    glTranslatef (0.0,-1,-15.0);
    gluLookAt(0,3,2,0,0,0,0,1,0);
   // glRotatef(40,0,1,0);
   // glRotatef(zRotated,0,1,0);
glColor3f(0.0,0.8,0.4);
    glPushMatrix();
    glScalef(1.5,0.05,1);//for make the table
    glutSolidCube(6.0);
    glPopMatrix();
// inner part
    glPushMatrix();
    glTranslatef(0,0.5,-2.5);
    glRotatef(90,0,0,1);
    glScalef(0.05,1.5,0.05);//for make the table
    glutSolidCube(6.0);
    glPopMatrix();
// front part
     glPushMatrix();
    glTranslatef(0,0.5,3);
    glRotatef(90,0,0,1);
    glScalef(0.05,1.5,0.05);//for make the table
    glutSolidCube(6.0);
    glPopMatrix();

//right player
glTranslatef(0,0,angle_player_1);
glColor3f(0.0,0.0,1.0);
    glPushMatrix();
    glTranslatef(4.5,0.5,0);
    glRotatef(90,1,0,0);
    glScalef(0.2,1,0.2);//for make the table
    glutSolidCube(1.0);
    glPopMatrix();

//left player
glColor3f(1.0,0.0,0.0);
    glPushMatrix();
    glTranslatef(-4.5,0.5,0);
    glRotatef(90,1,0,0);
    glScalef(0.2,1,0.2);//for make the table
    glutSolidCube(1.0);
    glPopMatrix();
    }
//------------------------------  ballFunc  ---------------------------------

void ball(){

    glColor3f(0.9,0.9,0.3);
     glPushMatrix();
    glutSolidSphere (0.3, 30, 30);
    glPopMatrix();
}
//------------------------------  cubeFunc  ---------------------------------

void CubeFunc(){
    //glRotatef(.1,0,0,1);
    glPushMatrix();
    //glTranslatef(0,4.5,-0.5);

    //back
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
    glPopMatrix();

}


//------------------------------  StarFunc  ---------------------------------
void StarFunc(){
    //glRotatef       (0.1,1,1,0);

glColor3f(0.9,0.9,0.3);
glPushMatrix();
glTranslatef(4,7,0);
//1st  side
    glPushMatrix();
    glTranslatef(0,0.5,0);

    glBegin(GL_POLYGON);
   // glColor3f(1.0,0.0,0.0);

    glVertex3f(-0.5,-0.5,-0.5);
    glVertex3f(0.5,-0.5,-0.5);
    glVertex3f(0.0,0.5,0.0);

    glEnd();

    glBegin(GL_POLYGON);
    //glColor3f(0.0,1.0,0.0);

    glVertex3f(-0.5,-0.5,0.5);
    glVertex3f(0.5,-0.5,0.5);
    glVertex3f(0.0,0.5,0.0);

    glEnd();

    glBegin(GL_POLYGON);
   // glColor3f(0.0,0.0,1.0);

    glVertex3f(-0.5,-0.5,-0.5);
    glVertex3f(-0.5,-0.5,0.5);
    glVertex3f(0.0,0.5,0.0);

    glEnd();

    glBegin(GL_POLYGON);
   // glColor3f(0.0,0.0,0.0);

    glVertex3f(0.5,-0.5,-0.5);
    glVertex3f(0.5,-0.5,0.5);
    glVertex3f(0.0,0.5,0.0);

    glEnd();


    glBegin(GL_POLYGON);
   // glColor3f(1.0,1.0,0.0);

    glVertex3f(0.5,-0.5,-0.5);
    glVertex3f(0.5,-0.5,0.5);
    glVertex3f(0.0,0.5,0.0);

    glEnd();

    glBegin(GL_POLYGON);
   // glColor3f(0.0,1.0,1.0);

    glVertex3f(-0.5,-0.5,0.5);
    glVertex3f(-0.5,-0.5,-0.5);
    glVertex3f(0.0,0.5,0.0);

    glEnd();

    glPopMatrix();


//2nd side
    glPushMatrix();
    glTranslatef(0,-0.5,0);
    glRotatef(180,0,0,1);

    glBegin(GL_POLYGON);
   // glColor3f(1.0,0.0,0.0);

    glVertex3f(-0.5,-0.5,-0.5);
    glVertex3f(0.5,-0.5,-0.5);
    glVertex3f(0.0,0.5,0.0);

    glEnd();

    glBegin(GL_POLYGON);
    //glColor3f(0.0,1.0,0.0);

    glVertex3f(-0.5,-0.5,0.5);
    glVertex3f(0.5,-0.5,0.5);
    glVertex3f(0.0,0.5,0.0);

    glEnd();

    glBegin(GL_POLYGON);
  //  glColor3f(0.0,0.0,1.0);

    glVertex3f(-0.5,-0.5,-0.5);
    glVertex3f(-0.5,-0.5,0.5);
    glVertex3f(0.0,0.5,0.0);

    glEnd();

    glBegin(GL_POLYGON);
  //  glColor3f(0.0,0.0,0.0);

    glVertex3f(0.5,-0.5,-0.5);
    glVertex3f(0.5,-0.5,0.5);
    glVertex3f(0.0,0.5,0.0);

    glEnd();


    glBegin(GL_POLYGON);
  //  glColor3f(1.0,1.0,0.0);

    glVertex3f(0.5,-0.5,-0.5);
    glVertex3f(0.5,-0.5,0.5);
    glVertex3f(0.0,0.5,0.0);

    glEnd();

    glBegin(GL_POLYGON);
  //  glColor3f(0.0,1.0,1.0);

    glVertex3f(-0.5,-0.5,0.5);
    glVertex3f(-0.5,-0.5,-0.5);
    glVertex3f(0.0,0.5,0.0);

    glEnd();

    glPopMatrix();


//3rd side
    glPushMatrix();
    glTranslatef(-0.5,0,0);
    glRotatef(90,0,0,1);

    glBegin(GL_POLYGON);
   // glColor3f(1.0,0.0,0.0);

    glVertex3f(-0.5,-0.5,-0.5);
    glVertex3f(0.5,-0.5,-0.5);
    glVertex3f(0.0,0.5,0.0);

    glEnd();

    glBegin(GL_POLYGON);
   // glColor3f(0.0,1.0,0.0);

    glVertex3f(-0.5,-0.5,0.5);
    glVertex3f(0.5,-0.5,0.5);
    glVertex3f(0.0,0.5,0.0);

    glEnd();

    glBegin(GL_POLYGON);
  //  glColor3f(0.0,0.0,1.0);

    glVertex3f(-0.5,-0.5,-0.5);
    glVertex3f(-0.5,-0.5,0.5);
    glVertex3f(0.0,0.5,0.0);

    glEnd();

    glBegin(GL_POLYGON);
    //glColor3f(0.0,0.0,0.0);

    glVertex3f(0.5,-0.5,-0.5);
    glVertex3f(0.5,-0.5,0.5);
    glVertex3f(0.0,0.5,0.0);

    glEnd();


    glBegin(GL_POLYGON);
  //  glColor3f(1.0,1.0,0.0);

    glVertex3f(0.5,-0.5,-0.5);
    glVertex3f(0.5,-0.5,0.5);
    glVertex3f(0.0,0.5,0.0);

    glEnd();

    glBegin(GL_POLYGON);
   // glColor3f(0.0,1.0,1.0);

    glVertex3f(-0.5,-0.5,0.5);
    glVertex3f(-0.5,-0.5,-0.5);
    glVertex3f(0.0,0.5,0.0);

    glEnd();

    glPopMatrix();

//4rth side
    glPushMatrix();
    glTranslatef(0.5,0,0);
    glRotatef(-90,0,0,1);

    glBegin(GL_POLYGON);
  //  glColor3f(1.0,0.0,0.0);

    glVertex3f(-0.5,-0.5,-0.5);
    glVertex3f(0.5,-0.5,-0.5);
    glVertex3f(0.0,0.5,0.0);

    glEnd();

    glBegin(GL_POLYGON);
    //glColor3f(0.0,1.0,0.0);

    glVertex3f(-0.5,-0.5,0.5);
    glVertex3f(0.5,-0.5,0.5);
    glVertex3f(0.0,0.5,0.0);

    glEnd();

    glBegin(GL_POLYGON);
   // glColor3f(0.0,0.0,1.0);

    glVertex3f(-0.5,-0.5,-0.5);
    glVertex3f(-0.5,-0.5,0.5);
    glVertex3f(0.0,0.5,0.0);

    glEnd();

    glBegin(GL_POLYGON);
    //glColor3f(0.0,0.0,0.0);

    glVertex3f(0.5,-0.5,-0.5);
    glVertex3f(0.5,-0.5,0.5);
    glVertex3f(0.0,0.5,0.0);

    glEnd();


    glBegin(GL_POLYGON);
  //  glColor3f(1.0,1.0,0.0);

    glVertex3f(0.5,-0.5,-0.5);
    glVertex3f(0.5,-0.5,0.5);
    glVertex3f(0.0,0.5,0.0);

    glEnd();

    glBegin(GL_POLYGON);
   // glColor3f(0.0,1.0,1.0);

    glVertex3f(-0.5,-0.5,0.5);
    glVertex3f(-0.5,-0.5,-0.5);
    glVertex3f(0.0,0.5,0.0);

    glEnd();

    glPopMatrix();

    glPopMatrix();

}

//------------------------------  cloudFunc  ---------------------------------
void cloud (){
//cloud 1
glColor3f(1.0,1.0,1.0);
    glPushMatrix();
    glTranslatef(-3,7,0);
    glutSolidSphere (0.7, 30, 30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-3.7,7,0);
   glutSolidSphere (0.7, 30, 30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-4.4,7,0);
   glutSolidSphere (0.7, 30, 30);
    glPopMatrix();

//cloud 2
    glPushMatrix();
    glTranslatef(-1,8,0);
   glutSolidSphere (0.6, 30, 30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.7,8,0);
   glutSolidSphere (0.6, 30, 30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-2.4,8,0);
   glutSolidSphere (0.6, 30, 30);
    glPopMatrix();


    glutPostRedisplay();
}

////------------------------------  display   -------------------------------
void display (void)
{
    //GLfloat Pos[]= {0,1,0,1};
    //GLfloat Col[]= {1,0,0,1};
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity ();
    //glLightfv(GL_LIGHT0,GL_POSITION,Pos);
  // glLightfv(GL_LIGHT0,GL_POSITION,Col);

       Table();
       glPushMatrix();
       ball();
       glPopMatrix();
       cloud();

       glPushMatrix();
       glTranslatef(0,4.5,-0.5);
       glRotatef(.1,0,0,1);
       CubeFunc();
       glPopMatrix();
scoreFunc();
       glPushMatrix();
       StarFunc();
       glPopMatrix();

    glutSwapBuffers();
    glutPostRedisplay();
}

//--------------------------------  idleFunc  ----------------------------------

//void idleFunc (void)
//{
//    zRotated += 0.01;
//    glutPostRedisplay();
//}

void texture (void)
{

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
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE); // buffer mode
    glEnable(GL_DEPTH_TEST);
    glutInitWindowSize     (800, 800);
    glutInitWindowPosition (700, 200);
    glutCreateWindow       ("20100067/20109328");
    glRotatef(1,1,0,0);
// gluPerspective(90,2.5,0.5,20);
    glClearColor (1.0, 1.0, 1.0, 1.0);


    glutReshapeFunc (reshapeFunc);
    glutDisplayFunc (display);
//    glutIdleFunc    (idleFunc);
   glClearColor(0,0.2,0.4,1); //COLOR FOR THE PACKGROUND
    texture(); // Lighting and textures
    Sound();

    glutMainLoop();
}

