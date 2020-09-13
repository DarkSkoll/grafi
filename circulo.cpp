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
GLfloat cx;
GLfloat cy;
float radio;

void algoritmoPuntoMedio(){ 
    if(radio <= 0){ 
        std::cout << "ERROR: Radio invalido" << std::endl;
        exit(EXIT_FAILURE);
    } 
    float x = 0, y = radio;
    struct Punto tmp;
    tmp.x = (GLfloat) x;
    tmp.y = (GLfloat) y;
    puntos.push_back(tmp);
    float p = 1.25 - radio; 
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
        puntos.push_back(tmp);
    }
} 

void dibujarCirculo(){
    int var = 2*puntos.size();
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
    glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_POINTS);
        for(int i = 0; i < puntos.size(); i++){
            glVertex2f((puntos[i].x+cx)/var,(puntos[i].y+cy)/var);
            glVertex2f((puntos[i].x+cx)/var,(-puntos[i].y+cy)/var);
            glVertex2f((-puntos[i].x+cx)/var,(puntos[i].y+cy)/var);
            glVertex2f((-puntos[i].x+cx)/var,(-puntos[i].y+cy)/var);
            glVertex2f((puntos[i].y+cx)/var,(puntos[i].x+cy)/var);
            glVertex2f((puntos[i].y+cx)/var,(-puntos[i].x+cy)/var);
            glVertex2f((-puntos[i].y+cx)/var,(puntos[i].x+cy)/var);
            glVertex2f((-puntos[i].y+cx)/var,(-puntos[i].x+cy)/var);
        }
        glEnd();
    glFlush();
}

int main(int argc, char **argv){
    if(argc != 4){
        std::cout << "Ingrese el radio, coordenada en X, coordenada en y" << std::endl;
        return -1;
    }
    radio = atof(argv[1]);
    cx = atof(argv[2]);
    cy = atof(argv[3]);
    algoritmoPuntoMedio();
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Circulo");
    glutDisplayFunc(dibujarCirculo);
    glutMainLoop();
    return 0;
}
