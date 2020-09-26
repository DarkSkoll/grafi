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

std::vector<struct Punto> f1;
std::vector<struct Punto> f2;

void generadorF1(){
    struct Punto tmp;
    float y;
    for(float x = -30; x <= 30; x += 0.001){
        tmp.x = (GLfloat) x;
        y = (x+1)/(x+3);
        tmp.y = (GLfloat) y;
        f1.push_back(tmp);
    }
} 

void generadorF2(){ 
    struct Punto tmp;
    float y;
    for(float x = -30; x <= 30; x += 0.001){
        tmp.x = (GLfloat) x;
        y = (2*pow(x,2))/(x+3);
        tmp.y = (GLfloat) y;
        f2.push_back(tmp);
    }
} 

void dibujarGrafica(){
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glLineWidth(1.0);
    glScalef(0.04,0.04,0.0);
    glColor3f(0.5, 0.5, 0.5);
        glBegin(GL_LINES);
            glVertex2f(0.0,50.0);
            glVertex2f(0.0,-50.0);
        glEnd();
        glBegin(GL_LINES);
            glVertex2f(50.0,0.0);
            glVertex2f(-50.0,0.0);
        glEnd();
    glPointSize(3.0);
    glColor3f(0.0, 0.0, 1.0);
        glBegin(GL_POINTS);
        for(int i = 0; i < f1.size(); i++){
            glVertex2f((f1[i].x),(f1[i].y));
        }
        glEnd();
    glColor3f(1.0, 0.0, 0.0);
        glBegin(GL_POINTS);
        for(int i = 0; i < f2.size(); i++){
            glVertex2f((f2[i].x),(f2[i].y));
        }
        glEnd();
    glScalef(25.0,25.0,0.0);
    glFlush();
}

int main(int argc, char **argv){
    generadorF1();
    generadorF2();
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Funciones");
    glutDisplayFunc(dibujarGrafica);
    glutMainLoop();
    return 0;
}
