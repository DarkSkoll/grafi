#include "GL/freeglut.h"
#include "GL/gl.h"
#include <iostream> 
#include <vector>
#include <stdlib.h>
#include <cmath>
#define rango 8

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
    glLineWidth(1.0);
    glScalef(0.3,0.3,0.0);
    glTranslatef(-2.0,-2.0,0.0);
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
    glTranslatef(2.0,2.0,0.0);
    glScalef(3.333,3.333,0.0);
    glFlush();
}

int main(int argc, char **argv){
    generarPuntos();
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Spline");
    glutDisplayFunc(dibujarGrafica);
    glutMainLoop();
    return 0;
}
