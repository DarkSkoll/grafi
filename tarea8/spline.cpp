#include "GL/freeglut.h"
#include "GL/gl.h"
#include <iostream> 
#include <vector>
#include <stdlib.h>
#include <cmath>

struct Punto{
    GLfloat x;
    GLfloat y;
};

std::vector<struct Punto> puntos;
std::vector<struct Punto> puntos1;

void generarPuntos(){
    struct Punto tmp;
    float y;
    float a,b,c,d;
    for(float x = 2; x < 6; x += 0.01){
        y = (0.0542*pow(x,3))-(0.3252*pow(x,2))-(0.2168*x)+5.301;
        tmp.x = (GLfloat) x;
        tmp.y = (GLfloat) y;
        puntos.push_back(tmp);
    }
    for(float x = 6; x < 7; x += 0.01){
        y = -(0.3849*pow(x,3))+(7.578*pow(x,2))-(47.64*x)+100.14;
        tmp.x = (GLfloat) x;
        tmp.y = (GLfloat) y;
        puntos.push_back(tmp);
    }
    for(float x = 7; x < 12; x += 0.01){
        y = (0.03361*pow(x,3))-(1.21*pow(x,2))+(13.88*x)-43.4;
        tmp.x = (GLfloat) x;
        tmp.y = (GLfloat) y;
        puntos.push_back(tmp);
    }
    for(float x = 2; x < 4; x += 0.01){
        y = (0.333*pow(x,3))-(2*pow(x,2))+(3.1667*x)+4;
        tmp.x = (GLfloat) x;
        tmp.y = (GLfloat) y;
        puntos1.push_back(tmp);
    }
    for(float x = 4; x < 5; x += 0.01){
        y = -(2.1667*pow(x,3))+(28*pow(x,2))-(116.83*x)+164;
        tmp.x = (GLfloat) x;
        tmp.y = (GLfloat) y;
        puntos1.push_back(tmp);
    }
    for(float x = 5; x < 8; x += 0.01){
        y = (1.2778*pow(x,3))-(23.667*pow(x,2))+(141.5*x)-266.56;
        tmp.x = (GLfloat) x;
        tmp.y = (GLfloat) y;
        puntos1.push_back(tmp);
    }
    for(float x = 8; x < 10; x += 0.001){
        y = -(1.1667*pow(x,3))+(35*pow(x,2))-(327.83*x)+985;
        tmp.x = (GLfloat) x;
        tmp.y = (GLfloat) y;
        puntos1.push_back(tmp);
    }
}

void dibujarGrafica(){
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glLineWidth(1.0);
    glScalef(0.1,0.1,0.0);
    glTranslatef(-8.0,-8.0,0.0);
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
    glColor3f(1.0, 0.0, 0.0);
        glBegin(GL_POINTS);
        for(int i = 0; i < puntos.size(); i++){
            glVertex2f(puntos[i].x,puntos[i].y);
        }
        glEnd();
    glColor3f(0.0, 0.0, 1.0);
        glBegin(GL_POINTS);
        for(int i = 0; i < puntos1.size(); i++){
            glVertex2f(puntos1[i].x,puntos1[i].y);
        }
        glEnd();
    glTranslatef(8.0,8.0,0.0);
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
    glutDisplayFunc(dibujarGrafica);
    glutMainLoop();
    return 0;
}
