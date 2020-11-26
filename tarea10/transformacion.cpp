#define _USE_MATH_DEFINES
#include "GL/freeglut.h"
#include "GL/gl.h"
#include <iostream> 
#include <unistd.h>
#include <vector>
#include <stdlib.h>
#include <cmath>
#include <math.h>
#define rango 100

struct Punto{
    GLfloat x;
    GLfloat y;
};

std::vector<struct Punto> puntos;
std::vector<struct Punto> escala;
std::vector<struct Punto> traslacion;
std::vector<struct Punto> rotacion;


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

void trasladar(float tx, float ty){
    struct Punto tmp;
    for(int i = 0; i < puntos.size(); i++){
        tmp.x = (GLfloat)(puntos[i].x+tx);
        tmp.y = (GLfloat)(puntos[i].y+ty);
        traslacion.push_back(tmp);
    }
}

void escalar(float sx, float sy){
    struct Punto tmp;
    for(int i = 0; i < puntos.size(); i++){
        tmp.x = (GLfloat)(puntos[i].x*sx);
        tmp.y = (GLfloat)(puntos[i].y*sy);
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

void dibujarGrafica(){
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glLineWidth(1.0);
    glScalef(0.01,0.01,0.0);
    glTranslatef(-80.0,-80.0,0.0);
    glColor3f(0.5, 0.5, 0.5);
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
    glPointSize(3.0);
    glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_POINTS);
            for(int i = 0; i < puntos.size(); i++){
                glVertex2f(puntos[i].x,puntos[i].y);
            }
        glEnd();
    glColor3f(1.0, 0.0, 0.0);
        glBegin(GL_POINTS);
            for(int i = 0; i < puntos.size(); i++){
                glVertex2f(rotacion[i].x,rotacion[i].y);
            }
        glEnd();
    glColor3f(0.0, 1.0, 0.0);
        glBegin(GL_POINTS);
            for(int i = 0; i < puntos.size(); i++){
                glVertex2f(escala[i].x,escala[i].y);
            }
        glEnd();
    glColor3f(0.0, 0.0, 1.0);
        glBegin(GL_POINTS);
            for(int i = 0; i < puntos.size(); i++){
                glVertex2f(traslacion[i].x,traslacion[i].y);
            }
        glEnd();
    glTranslatef(80.0,80.0,0.0);
    glScalef(100.0,100.0,0.0);
    glFlush();
}

int main(int argc, char **argv){
    generarPuntos();
    rotar(56);
    escalar(12,40);
    trasladar(12,34);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Transformaciones");
    glutDisplayFunc(dibujarGrafica);
    glutMainLoop();
    return 0;
}
