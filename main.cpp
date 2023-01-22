#include <bits/stdc++.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <windows.h>
#include <stdlib.h>
#include <mmsystem.h>

using namespace std;
int posx = 0, posz = 0;
GLfloat x = 0,dx = 0.05;
void animate(int value){
    glutPostRedisplay();
    glutTimerFunc(1000/60,animate,0);

    if(x > 4) dx = -0.05;
    else if(x < -4) dx = 0.05;
    x += dx;

    glutPostRedisplay();
}


   void display(){


       /* clear window */
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    /* future matrix manipulations should affect the modelview matrix */
    glMatrixMode(GL_MODELVIEW);




    /* draw scene */
    glPushMatrix();
    glTranslated(posx, 0, posz);
    // house
    glPushMatrix();
    glColor3d(1,1,0);
    glutSolidCube(2);                 // building

    glTranslatef(0,1,0);
    glPushMatrix();                   // roof
    glRotatef(-90,1,0,0);
    glutSolidCone(1.5,1,16,8);
    glPopMatrix();

    glTranslatef(.75,.5,-.75);
    glPushMatrix();                   // chimney
    glScalef(1,3,1);
    glutSolidCube(.25);
    glPopMatrix();
    glPopMatrix();

    glTranslatef(x,-.65,2);

    // car
    glPushMatrix();
    glPushMatrix();    // body
    glScalef(2,.5,1);
    glutSolidCube(.5);
    glPopMatrix();
    glTranslatef(0,0,.25);
    glPushMatrix();
    glTranslatef(-.4,-.2,0);
    glutSolidTorus(.05,.1,8,8);       // wheel
    glTranslatef(.8,0,0);
    glutSolidTorus(.05,.1,8,8);       // wheel
    glPopMatrix();
    glTranslatef(0,0,-.5);
    glPushMatrix();
    glTranslatef(-.4,-.2,0);
    glColor4d(1,0,1,1);
    glutSolidTorus(.05,.1,8,8);       // wheel
    glTranslatef(.8,0,0);
    glutSolidTorus(.05,.1,8,8);       // wheel
    glPopMatrix();
    glPopMatrix();

    glPopMatrix();



    /* flush drawing routines to the window */
    glutSwapBuffers();
}

void reshape ( int width, int height ) {

    /* define the viewport transformation */
    glViewport(0,0,width,height);
}
void kbinput(int key, int x, int y){
    if(key == GLUT_KEY_LEFT) posx--;
    else if(key == GLUT_KEY_RIGHT) posx++;
    else if(key == GLUT_KEY_UP) posz++;
    else if(key == GLUT_KEY_DOWN) posz--;
}
void initGL(){
    glClearColor(18.0 / 255, 192.0 / 255, 222/255.0, 1);
    glClearDepth(1);
    glEnable(GL_DEPTH_TEST);
    glShadeModel(GL_SMOOTH);
}
int main ( int argc, char * argv[] ) {

    /* initialize GLUT, using any commandline parameters passed to the
       program */
    glutInit(&argc,argv);

    /* setup the size, position, and display mode for new windows */
    glutInitWindowSize(500,500);
    glutInitWindowPosition(0,0);
    glutInitDisplayMode(GLUT_DOUBLE);

    /* create and set up a window */
    glutCreateWindow("19200334");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutSpecialFunc(kbinput);
    /* set up depth-buffering */
    glEnable(GL_DEPTH_TEST);

    /* turn on default lighting */
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    /* define the projection transformation */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(40,1,4,20);

    /* define the viewing transformation */
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(5.0,5.0,5.0,0.0,0.0,0.0,0.0,1.0,0.0);
    initGL();
    glutTimerFunc(0,animate,0);
    PlaySound(TEXT("C:/Users/nazas/Downloads/nada2/sound.wav"),NULL,SND_ASYNC|SND_FILENAME);
    /* tell GLUT to wait for events */

    glutMainLoop();
}
