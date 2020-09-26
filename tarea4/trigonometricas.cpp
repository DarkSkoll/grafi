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

std::vector<struct Punto> seno;
std::vector<struct Punto> coseno;

void generadorSeno(){
    struct Punto tmp;
    float y;
    for(float x = -5; x <= 5; x += 0.001){
        tmp.x = (GLfloat) x;
        y = sin(x);
        tmp.y = (GLfloat) y;
        seno.push_back(tmp);
    }
} 

void generadorCoseno(){ 
    struct Punto tmp;
    float y;
    for(float x = -5; x <= 5; x += 0.001){
        tmp.x = (GLfloat) x;
        y = cos(x);
        tmp.y = (GLfloat) y;
        coseno.push_back(tmp);
    }
} 

void dibujarGrafica(){
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glLineWidth(1.0);
    glScalef(0.2,0.5,0.0);
    glColor3f(0.5, 0.5, 0.5);
        glBegin(GL_LINES);
            glVertex2f(0.0,1.5);
            glVertex2f(0.0,-1.5);
        glEnd();
        glBegin(GL_LINES);
            glVertex2f(6.0,0.0);
            glVertex2f(-6.0,0.0);
        glEnd();
    glPointSize(3.0);
    glColor3f(0.0, 0.0, 1.0);
        glBegin(GL_POINTS);
        for(int i = 0; i < seno.size(); i++){
            glVertex2f((seno[i].x),(seno[i].y));
        }
        glEnd();
    glColor3f(1.0, 0.0, 0.0);
        glBegin(GL_POINTS);
        for(int i = 0; i < coseno.size(); i++){
            glVertex2f((coseno[i].x),(coseno[i].y));
        }
        glEnd();
    glScalef(5.0,2.0,0.0);
    glFlush();
}

int main(int argc, char **argv){
    generadorSeno();
    generadorCoseno();
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Trigonometricas");
    glutDisplayFunc(dibujarGrafica);
    glutMainLoop();
    return 0;
}
