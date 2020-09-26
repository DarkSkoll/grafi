#define _USE_MATH_DEFINES
#include "GL/freeglut.h"
#include "GL/gl.h"
#include <iostream> 
#include <vector>
#include <stdlib.h>
#include <math.h>
#include <cmath>

struct Punto{
    GLfloat x;
    GLfloat y;
};

std::vector<struct Punto> puntos;

void generadorParteSuperior(){
    struct Punto tmp;
    float y;
    for(float x = -2; x <= 2; x += 0.001){
        tmp.x = (GLfloat) x;
        y = sqrt(1-pow((abs(x)-1),2));
        tmp.y = (GLfloat) y;
        puntos.push_back(tmp);
    }
} 

void generadorParteInferior(){ 
    struct Punto tmp;
    float y;
    for(float x = -2; x <= 2; x += 0.001){
        tmp.x = (GLfloat) x;
        y = acos(1-abs(x))-M_PI;
        tmp.y = (GLfloat) y;
        puntos.push_back(tmp);
    }
} 

void dibujarCorazon(){
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glLineWidth(1.0);
    glTranslatef(0.0,0.5,0.0);
    glScalef(0.4,0.4,0.0);
    glColor3f(0.5, 0.5, 0.5);
        glBegin(GL_LINES);
            glVertex2f(0.0,5.0);
            glVertex2f(0.0,-5.0);
        glEnd();
        glBegin(GL_LINES);
            glVertex2f(5.0,0.0);
            glVertex2f(-5.0,0.0);
        glEnd();
    glPointSize(3.0);
    glColor3f(1.0, 0.0, 0.0);
        glBegin(GL_POINTS);
        for(int i = 0; i < puntos.size(); i++){
            glVertex2f((puntos[i].x),(puntos[i].y));
        }
        glEnd();
    glScalef(2.5,2.5,0.0);
    glTranslatef(0.0,-0.5,0.0);
    glFlush();
}

int main(int argc, char **argv){
    generadorParteInferior();
    generadorParteSuperior();
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Corazon");
    glutDisplayFunc(dibujarCorazon);
    glutMainLoop();
    return 0;
}
