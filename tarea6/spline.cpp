#include "GL/freeglut.h"
#include "GL/gl.h"
#include <iostream> 
#include <vector>
#include <stdlib.h>

struct Punto{
    GLfloat x;
    GLfloat y;
};

std::vector<struct Punto> puntos;

void generarPuntos(){
    struct Punto tmp;
    float y;
    for(float x = 2; x < 6; x += 0.01){
        y = 4;
        tmp.x = (GLfloat) x;
        tmp.y = (GLfloat) y;
        puntos.push_back(tmp);
    }
    for(float x = 6; x < 7; x += 0.01){
        y = (2*x)-8;
        tmp.x = (GLfloat) x;
        tmp.y = (GLfloat) y;
        puntos.push_back(tmp);
    }
    for(float x = 7; x < 12; x += 0.01){
        y = (x/5)+4.6;
        tmp.x = (GLfloat) x;
        tmp.y = (GLfloat) y;
        puntos.push_back(tmp);
    }
}

void dibujarCirculo(){
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glLineWidth(1.0);
    glScalef(0.1,0.1,0.0);
    glTranslatef(-5.0,-5.0,0.0);
    glColor3f(0.5, 0.5, 0.5);
        glBegin(GL_LINES);
            glVertex2f(0.0,1.5);
            glVertex2f(0.0,-1.5);
        glEnd();
        glBegin(GL_LINES);
            glVertex2f(1.5,0.0);
            glVertex2f(-1.5,0.0);
        glEnd();
    glPointSize(3.0);
    glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_POINTS);
        for(int i = 0; i < puntos.size(); i++){
            glVertex2f(puntos[i].x,puntos[i].y);
        }
        glEnd();
    glTranslatef(5.0,5.0,0.0);
    glScalef(10.0,10.0,0.0);
    glFlush();
}

int main(int argc, char **argv){
    generarPuntos();
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Spline");
    glutDisplayFunc(dibujarCirculo);
    glutMainLoop();
    return 0;
}
