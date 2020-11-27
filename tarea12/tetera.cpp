#define _USE_MATH_DEFINES
#include "GL/freeglut.h"
#include "GL/gl.h"
#include <iostream>
#include <unistd.h>
#include <vector>
#include <stdlib.h>
#include <cmath>
#include <math.h>
#define rango 20

double rX=0;
double rY=0;

float matCol[] = {1,0,0,0};

void drawGrafic(){
    glClearColor(0.0,0.0,0.0,1.0);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glScalef(0.02,0.02,0.02);
    glRotatef(rX,1.0,0.0,0.0);
    glRotatef(rY,0.0,1.0,0.0);
    glLineWidth(5.0);
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_LINES);
        glVertex3f(rango,0.0,0.0);
        glVertex3f(-rango,0.0,0.0);
    glEnd();
    glColor3f(0.0,1.0,0.0);
    glBegin(GL_LINES);
        glVertex3f(0.0,-rango,0.0);
        glVertex3f(0.0,rango,0.0);
    glEnd();
    glColor3f(0.0,0.0,1.0);
    glBegin(GL_LINES);
        glVertex3f(0.0,0.0,-rango);
        glVertex3f(0.0,0.0,rango);
    glEnd();
    glLineWidth(1.0);
    glColor3f(1.0,1.0,1.0);
    glMaterialfv(GL_FRONT,GL_DIFFUSE,matCol);
    glutWireTeapot(30.0);
    glPopMatrix();
    glScalef(50.0,50.0,50.0);
    glFlush();
    glutSwapBuffers();
}

void keyboard(int key, int x, int y){
    if (key == GLUT_KEY_RIGHT){
        rY += 15;
    }
    else if (key == GLUT_KEY_LEFT){
        rY -= 15;
    }
    else if (key == GLUT_KEY_DOWN){
        rX -= 15;
    }
    else if (key == GLUT_KEY_UP){
        rX += 15;
    }
    glutPostRedisplay();
}


int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800,800);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Tetera");
    glEnable(GL_DEPTH_TEST);
    glutDisplayFunc(drawGrafic);
    glutSpecialFunc(keyboard);
    glutMainLoop();
    return 0;
}
