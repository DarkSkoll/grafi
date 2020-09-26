#include "GL/freeglut.h"
#include "GL/gl.h"
#include <unistd.h>

void dibujarPuntos(){
    glClearColor(1.0, 1.0, 1.0, 0.4);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
    glPointSize(15.0);
        glBegin(GL_POINTS);
            glColor3f(1.0,0.0,0.0);
            glVertex3f(0.2,0.3,0.0);
            glColor3f(1.0,0.0,0.0);
            glVertex3f(-0.3,0.4,0.0);
            glColor3f(1.0,0.0,0.0);
            glVertex3f(0.5,-0.6,0.0);
            glColor3f(1.0,0.0,0.0);
            glVertex3f(-0.4,-0.3,0.0);
        glEnd();
    glFlush();
}

void dibujarLinea(){
    glClearColor(1.0, 1.0, 1.0, 0.4);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
    glLineWidth(10.0);
        glBegin(GL_LINES);
            glColor3f(1.0,0.0,0.0);
            glVertex3f(0.2,0.3,0.0);
            glColor3f(1.0,0.0,0.0);
            glVertex3f(-0.3,0.4,0.0);
        glEnd();
        glBegin(GL_LINES);
            glColor3f(1.0,0.0,0.0);
            glVertex3f(0.5,-0.6,0.0);
            glColor3f(1.0,0.0,0.0);
            glVertex3f(-0.4,-0.3,0.0);
        glEnd();
    glFlush();
}

void dibujarTriangulo(){
    glClearColor(1.0, 1.0, 1.0, 0.4);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
        glBegin(GL_TRIANGLES);
            glColor3f(1.0, 0.0, 0.0);
            glVertex3f(-0.5, 0.5, 0.0);
            glColor3f(1.0,0.0,0.0);
            glVertex3f(0.5, 0.5, 0.0);
            glColor3f(1.0,0.0,0.0);
            glVertex3f(0.0, -0.5, 0.0);
        glEnd();
    glFlush();
}

void dibujarCuadrilatero(){
    glClearColor(1.0, 1.0, 1.0, 0.4);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
        glBegin(GL_QUADS);
            glColor3f(1.0,0.0,0.0);
            glVertex3f(-0.2,-0.3,0.0);
            glColor3f(1.0,0.0,0.0);
            glVertex3f(-0.3,0.4,0.0);
            glColor3f(1.0,0.0,0.0);
            glVertex3f(0.5,0.6,0.0);
            glColor3f(1.0,0.0,0.0);
            glVertex3f(0.4,-0.3,0.0);
        glEnd();
    glFlush();
}

void dibujarPoligono(){
    glClearColor(1.0, 1.0, 1.0, 0.4);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
        glBegin(GL_POLYGON);
            glColor3f(1.0,0.0,0.0);
            glVertex3f(0.0,0.7,0.0);
            glColor3f(1.0,0.0,0.0);
            glVertex3f(0.5,0.5,0.0);
            glColor3f(1.0,0.0,0.0);
            glVertex3f(0.0,0.2,0.0);
            glColor3f(1.0,0.0,0.0);
            glVertex3f(0.4,-0.7,0.0);
            glColor3f(1.0,0.0,0.0);
            glVertex3f(0.0,-0.5,0.0);
            glColor3f(1.0,0.0,0.0);
            glVertex3f(-0.6,-0.7,0.0);
            glColor3f(1.0,0.0,0.0);
            glVertex3f(0.0,-0.4,0.0);
            glColor3f(1.0,0.0,0.0);
            glVertex3f(-0.6,0.5,0.0);
        glEnd();
    glFlush();
}

void dibujarTrianguloStrip(){
    glClearColor(1.0, 1.0, 1.0, 0.4);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
        glBegin(GL_TRIANGLE_STRIP);
            glColor3f(1.0, 0.0, 0.0);
            glVertex3f(-0.5, 0.5, 0.0);
            glColor3f(1.0,0.0,0.0);
            glVertex3f(0.5, 0.5, 0.0);
            glColor3f(1.0,0.0,0.0);
            glVertex3f(0.0, -0.5, 0.0);
            glColor3f(0.0,1.0,0.0);
            glVertex3f(0.7, -0.2, 0.0);
        glEnd();
    glFlush();
}

void dibujarCuadrilateroStrip(){
    glClearColor(1.0, 1.0, 1.0, 0.4);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
        glBegin(GL_QUAD_STRIP);
            glColor3f(1.0,0.0,0.0);
            glVertex3f(-0.4,0.4,0.0);
            glColor3f(1.0,0.0,0.0);
            glVertex3f(0.4,0.4,0.0);
            glColor3f(1.0,0.0,0.0);
            glVertex3f(-0.4,0.0,0.0);
            glColor3f(1.0,0.0,0.0);
            glVertex3f(0.4,0.0,0.0);
            glColor3f(0.0,0.0,1.0);
            glVertex3f(0.0,-0.3,0.0);
            glColor3f(0.0,0.0,1.0);
            glVertex3f(0.4,-0.3,0.0);
        glEnd();
    glFlush();
}

void dibujarPrimitivas(){
    dibujarPuntos();
    usleep(1500000);
    dibujarLinea();
    usleep(1500000);
    dibujarTriangulo();
    usleep(1500000);
    dibujarCuadrilatero();
    usleep(1500000);
    dibujarPoligono();
    usleep(1500000);
    dibujarTrianguloStrip();
    usleep(1500000);
    dibujarCuadrilateroStrip();
}

int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Figuras");
    glutDisplayFunc(dibujarPrimitivas());
    glutMainLoop();
    return 0;
}
