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

struct Punto{
    GLfloat x;
    GLfloat y;
    GLfloat z;
};

std::vector<struct Punto> puntos;
std::vector<struct Punto> escala;
std::vector<struct Punto> traslacion;
std::vector<struct Punto> rotacion;


void generarPuntos(){
    struct Punto tmp;
    float x,y,z;
}

void trasladar(float tx,float ty,float tz){
    struct Punto tmp;
    for(int i = 0; i < puntos.size(); i++){
        tmp.x = (GLfloat)(puntos[i].x+tx);
        tmp.y = (GLfloat)(puntos[i].y+ty);
        tmp.z = (GLfloat)(puntos[i].z+tz);
        traslacion.push_back(tmp);
    }
}

void escalar(float sx,float sy,float sz){
    struct Punto tmp;
    for(int i = 0; i < puntos.size(); i++){
        tmp.x = (GLfloat)(puntos[i].x*sx);
        tmp.y = (GLfloat)(puntos[i].y*sy);
        tmp.y = (GLfloat)(puntos[i].z*sz);
        escala.push_back(tmp);
    }
}

void rotar(double rx){
    double theta = (rx*M_PI/180);
    struct Punto tmp;
    float x,y;
    for(int i = 0; i < puntos.size(); i++){
        x = (float)puntos[i].x;
        y = (float)puntos[i].y;
        tmp.x = (GLfloat)((x*cos(theta))-(y*sin(theta)));
        tmp.y = (GLfloat)((x*sin(theta))+(y*cos(theta)));
        rotacion.push_back(tmp);
    }
}

void drawGrafic(){
    glClearColor(0.0,0.0,0.0,1.0);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glScalef(0.01,0.01,0.01);
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
    glScalef(100.0,100.0,100.0);
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
    generarPuntos();
    //rotar(56);
    //escalar(12,40);
    //trasladar(12,34);
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
