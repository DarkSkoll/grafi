#include "GL/freeglut.h"
#include "GL/gl.h"
#include <iostream>
#include <unistd.h>
#include <vector>
#include <stdlib.h>
#include <cmath>
#define rango 10

struct Punto{
    GLfloat x;
    GLfloat y;
};

std::vector<struct Punto> puntos;

void generarPuntos(){
    struct Punto tmp;
    float x,y;
    for(float t = 0; t < 1; t = t+0.001){
        x = (2*pow(t,2))+2*t+1;
        y = -(4*pow(t,2))+6*t+1;
        tmp.x = (GLfloat) x;
        tmp.y = (GLfloat) y;
        puntos.push_back(tmp);
    }
}

void dibujarGrafica(){
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(3.0);
    glLineWidth(1.0);
    glScalef(0.1,0.1,0.0);
    glColor3f(0.5,0.5,0.5);
    glBegin(GL_LINES);
    glVertex2f(0.0,rango);
    glVertex2f(0.0,-rango);
    glEnd();
    glBegin(GL_LINES);
    glVertex2f(rango,0.0);
    glVertex2f(-rango,0.0);
    glEnd();
    glBegin(GL_LINES);
    for(float i = -rango; i <= rango; i++){
        glVertex2f(i,-0.2);
        glVertex2f(i,0.2);
        glVertex2f(-0.2,i);
        glVertex2f(0.2,i);
    }
    glEnd();
    glBegin(GL_POINTS);
    for(int i = 0; i < puntos.size(); i++){
    glColor3f(1.0,1.0,1.0);
        glVertex2f(puntos[i].x,puntos[i].y);
    glColor3f(1.0,0.0,0.0);
        glVertex2f(-puntos[i].x,puntos[i].y);
    glColor3f(1.0,0.647,0.0);
        glVertex2f(puntos[i].x,-puntos[i].y);
    glColor3f(0.0,1.0,0.0);
        glVertex2f(-puntos[i].x,-puntos[i].y);
    glColor3f(0.0,0.0,1.0);
        glVertex2f(puntos[i].y,puntos[i].x);
    }
    glEnd();
    glScalef(10.0,10.0,0.0);
    glFlush();
}

int main(int argc, char **argv){
    generarPuntos();
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Transformaciones");
    glutDisplayFunc(dibujarGrafica);
    glutMainLoop();
    return 0;
}
