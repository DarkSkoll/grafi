#include "GL/freeglut.h"
#include "GL/gl.h"
#include <iostream> 
#include <vector>
#include <stdlib.h>
#include <math.h>

struct Punto{
    GLfloat x;
    GLfloat y;
};

std::vector<struct Punto> puntos;

void genpuntos(){
    float a = 0.001;
    float b = 0.005347;
    float radian = 57.29578;
    float x, y;
    struct Punto tmp;
    for(int i = 0; i < 2000; i++){
        x = a*cos(i*radian)*exp(b*i);
        y = a*sin(i*radian)*exp(b*i);
        tmp.x = (GLfloat) x;
        tmp.y = (GLfloat) y;
        if(i%17 == 0) puntos.push_back(tmp);
    }
}

void dibujarFibonacci(){
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glLineWidth(1.0);
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
    glColor3f(1.0, 1.25, 1.0);
        glBegin(GL_LINES);
        for(int i = 1; i < puntos.size(); i++){
            glVertex2f((puntos[i-1].x),(puntos[i-1].y));
            glVertex2f((puntos[i].x),(puntos[i].y));
        }
        glEnd();
    glFlush();
}

int main(int argc, char **argv){
    genpuntos();
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Fibonacci");
    glutDisplayFunc(dibujarFibonacci);
    glutMainLoop();
    return 0;
}
