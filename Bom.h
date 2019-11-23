//
// Created by infraspinatus on 11/11/19.
//
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <complex>

#ifndef OPENGLLINUXTEST_BOM_H
#define OPENGLLINUXTEST_BOM_H


class Bom {
public:
    float moveBomX;
    float moveBomY;
    float relativeYBomA = 0;
    float relativeYBomB = 0;
    float relativeXBomA = 0;
    float relativeXBomB = 0;
    float bomColisionPoint[2][2] = {
            {15, 86},
            {20, 80}
    };
private:
    void doCirclefill(double x, double y, double radius) {
        int i;
        int triangleAmount = 20; //# of triangles used to draw circle
        float PI = 3.14159265358979323846;
        //GLfloat radius = 0.8f; //radius
        GLfloat twicePi = 2.0f * PI;

        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(0, 0, 0);
        glVertex2f(x, y); // center of circle
        for (i = 0; i <= triangleAmount; i++) {
            glVertex2f(
                    x + (radius * std::cos(i * twicePi / triangleAmount)),
                    y + (radius * std::sin(i * twicePi / triangleAmount))
            );
        }
        glEnd();
    }

public:
    void bom() {
        //colision
        glPushMatrix();
        glTranslated(-20,0,0);
        glPushMatrix();
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glBegin(GL_POLYGON);
        glColor4f(0, 0, 0, 0);
        glVertex2f(15.5, 86);
        glVertex2f(20.5, 86);
        glVertex2f(20.5, 80.5);
        glVertex2f(15.5, 80.5);
        glEnd();
        glPopMatrix();

        glBegin(GL_POLYGON);
        glColor3ub(90, 24, 22);
        glVertex2f(17.8, 84.5);
        glVertex2f(18.3, 84.5);
        glVertex2f(18.3, 87);
        glVertex2f(17.8, 87);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(255, 255, 255);
        glVertex2f(17.8, 84.5);
        glVertex2f(18.3, 84.5);
        glVertex2f(18.3, 86.5);
        glVertex2f(17.8, 86.5);
        glEnd();

        doCirclefill(18, 83, 2.5);

        glBegin(GL_POLYGON);
        glColor3ub(0, 0, 0);
        glVertex2f(17.5, 84.5);
        glVertex2f(18.5, 84.5);
        glVertex2f(18.5, 86);
        glVertex2f(17.5, 86);
        glEnd();
        glPopMatrix();

    }

    void movebom() {
        relativeXBomA = (bomColisionPoint[0][0]-20) + moveBomX;
        relativeXBomB = (bomColisionPoint[1][0]-20) + moveBomX;
        relativeYBomA = (bomColisionPoint[0][1]) + moveBomY;
        relativeYBomB = (bomColisionPoint[1][1]) + moveBomY;
        glPushMatrix();
        glTranslated(moveBomX, moveBomY, 0);
        bom();
        glPopMatrix();

    }

    bool glCollision(float tomoColisionPoint[2][2]){
//        printf("Relative Y A = %f Relative Y B = %f\n", relativeXBomA,relativeXBomB);
        return (((relativeXBomA >= tomoColisionPoint[0][0]) && (relativeXBomA <= tomoColisionPoint[1][0])) &&
                (relativeYBomB == tomoColisionPoint[0][1])) ||
               (((relativeXBomB >= tomoColisionPoint[0][0]) && (relativeXBomB <= tomoColisionPoint[1][0])) &&
                (relativeYBomB == tomoColisionPoint[0][1]));
    }

};


#endif //OPENGLLINUXTEST_BOM_H
