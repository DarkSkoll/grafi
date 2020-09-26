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

std::vector<struct Punto> puntos1;
std::vector<struct Punto> puntos2;
std::vector<struct Punto> puntos3;
float radio1 = 100;
float radio2 = 125;
float radio3 = 150;

void puntosParametricas(){
    struct Punto tmp;
    float x,y;
    for(double i = 0; i <= 45; i += 0.1){
        x = radio1*cos(i);
        y = radio1*sin(i);
        tmp.x = (GLfloat) x;
        tmp.y = (GLfloat) y;
        puntos1.push_back(tmp);
    }
}

void puntosPolares(){
    struct Punto tmp;
    double radian = 180/M_PI;
    float x,y;
    for(double i = 0; i <= 0.25; i += 0.001){
        x = radio2*cos(i*radian);
        y = radio2*sin(i*radian);
        tmp.x = (GLfloat) x;
        tmp.y = (GLfloat) y;
        puntos2.push_back(tmp);
    }
}

void algoritmoPuntoMedio(){ 
    float x = 0, y = radio3;
    struct Punto tmp;
    tmp.x = (GLfloat) x;
    tmp.y = (GLfloat) y;
    puntos3.push_back(tmp);
    float p = 1.25 - radio3; 
    while(y > x){  
        x++; 
        if (p <= 0) 
            p = p + 2*x + 1; 
        else{ 
            y--; 
            p = p + 2*x - 2*y + 1; 
        } 
        tmp.x = (GLfloat) x;
        tmp.y = (GLfloat) y;
        puntos3.push_back(tmp);
    }
} 

void dibujarCirculo(){
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glLineWidth(1.0);
    glColor3f(0.5, 0.5, 0.5);
    glScalef(0.005,0.005,0.0);
        glBegin(GL_LINES);
            glVertex2f(0.0,1.5);
            glVertex2f(0.0,-1.5);
        glEnd();
        glBegin(GL_LINES);
            glVertex2f(1.5,0.0);
            glVertex2f(-1.5,0.0);
        glEnd();
    glPointSize(3.0);
    glColor3f(0.0, 0.0, 1.0);
        glBegin(GL_POINTS);
        for(int i = 0; i < puntos1.size(); i++){
            glVertex2f((puntos1[i].x),(puntos1[i].y));
            glVertex2f((puntos1[i].x),(-puntos1[i].y));
            glVertex2f((-puntos1[i].x),(puntos1[i].y));
            glVertex2f((-puntos1[i].x),(-puntos1[i].y));
            glVertex2f((puntos1[i].y),(puntos1[i].x));
            glVertex2f((puntos1[i].y),(-puntos1[i].x));
            glVertex2f((-puntos1[i].y),(puntos1[i].x));
            glVertex2f((-puntos1[i].y),(-puntos1[i].x));
        }
        glEnd();
    glColor3f(0.0, 1.0, 0.0);
        glBegin(GL_POINTS);
        for(int i = 0; i < puntos2.size(); i++){
            glVertex2f((puntos2[i].x),(puntos2[i].y));
            glVertex2f((puntos2[i].x),(-puntos2[i].y));
            glVertex2f((-puntos2[i].x),(puntos2[i].y));
            glVertex2f((-puntos2[i].x),(-puntos2[i].y));
            glVertex2f((puntos2[i].y),(puntos2[i].x));
            glVertex2f((puntos2[i].y),(-puntos2[i].x));
            glVertex2f((-puntos2[i].y),(puntos2[i].x));
            glVertex2f((-puntos2[i].y),(-puntos2[i].x));
        }
        glEnd();
    glColor3f(1.0, 0.0, 0.0);
        glBegin(GL_POINTS);
        for(int i = 0; i < puntos3.size(); i++){
            glVertex2f((puntos3[i].x),(puntos3[i].y));
            glVertex2f((puntos3[i].x),(-puntos3[i].y));
            glVertex2f((-puntos3[i].x),(puntos3[i].y));
            glVertex2f((-puntos3[i].x),(-puntos3[i].y));
            glVertex2f((puntos3[i].y),(puntos3[i].x));
            glVertex2f((puntos3[i].y),(-puntos3[i].x));
            glVertex2f((-puntos3[i].y),(puntos3[i].x));
            glVertex2f((-puntos3[i].y),(-puntos3[i].x));
        }
        glEnd();
    glScalef(200.0,200.0,0.0);
    glFlush();
}

int main(int argc, char **argv){
    algoritmoPuntoMedio();
    puntosParametricas();
    puntosPolares();
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Circulo");
    glutDisplayFunc(dibujarCirculo);
    glutMainLoop();
    return 0;
}
