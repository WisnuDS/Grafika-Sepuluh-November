//
// Created by infraspinatus on 11/11/19.
//
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include "Bom.h"

#ifndef OPENGLLINUXTEST_PESAWAT_H
#define OPENGLLINUXTEST_PESAWAT_H


class Pesawat {
public:
    static int jumlahBom;
    Bom bom[10];
    int moveX;

    void pesawatt() {
        glPushMatrix();
        glScalef(0.8f, 0.8f, 0.0f);
        glTranslated(-20, 20, 0);
        glBegin(GL_POLYGON);
        glColor3ub(169, 169, 169);
        glVertex2f(31, 80);
        glVertex2f(31, 85);
        glVertex2f(3, 85);
        glVertex2f(3, 80);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(0, 0, 0);
        glVertex2f(13, 84);
        glVertex2f(31, 84);
        glVertex2f(31, 85);
        glVertex2f(13, 85);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(105, 105, 105);
        glVertex2f(16, 85);
        glVertex2f(28, 85);
        glVertex2f(28, 86);
        glVertex2f(16, 86);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(105, 105, 105);
        glVertex2f(19, 86);
        glVertex2f(25, 86);
        glVertex2f(25, 87);
        glVertex2f(19, 87);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(105, 105, 105);
        glVertex2f(16, 85);
        glVertex2f(28, 85);
        glVertex2f(28, 86);
        glVertex2f(16, 86);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(105, 105, 105);
        glVertex2f(31, 82);
        glVertex2f(33, 82);
        glVertex2f(33, 84);
        glVertex2f(31, 84);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(169, 169, 169);
        glVertex2f(31, 82);
        glVertex2f(33, 82);
        glVertex2f(33, 84);
        glVertex2f(31, 84);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(169, 169, 169);
        glVertex2f(33, 82);
        glVertex2f(36, 82);
        glVertex2f(36, 83);
        glVertex2f(33, 83);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(169, 169, 169);
        glVertex2f(2, 82);
        glVertex2f(3, 82);
        glVertex2f(3, 84);
        glVertex2f(2, 84);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(0, 0, 0);
        glVertex2f(1, 90);
        glVertex2f(5, 90);
        glVertex2f(10, 85);
        glVertex2f(10, 84);
        glVertex2f(2, 84);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(0, 0, 0);
        glVertex2f(1, 90);
        glVertex2f(5, 90);
        glVertex2f(10, 85);
        glVertex2f(10, 84);
        glVertex2f(2, 84);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(0, 0, 0);
        glVertex2f(1, 90);
        glVertex2f(5, 90);
        glScalef(2.0f, 2.0f, 1.0f);
        glVertex2f(10, 85);
        glVertex2f(10, 84);
        glVertex2f(2, 84);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(119, 136, 153);
        glVertex2f(2, 89);
        glVertex2f(4, 89);
        glVertex2f(8, 85);
        glVertex2f(3, 85);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(0, 0, 0);
        glVertex2f(10, 85);
        glVertex2f(13, 85);
        glVertex2f(13, 84);
        glVertex2f(10, 84);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(0, 0, 0);
        glVertex2f(13, 85);
        glVertex2f(16, 85);
        glVertex2f(16, 86);
        glVertex2f(13, 86);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(0, 0, 0);
        glVertex2f(16, 86);
        glVertex2f(19, 86);
        glVertex2f(19, 87);
        glVertex2f(16, 87);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(0, 0, 0);
        glVertex2f(19, 87);
        glVertex2f(25, 87);
        glVertex2f(25, 88);
        glVertex2f(19, 88);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(0, 0, 0);
        glVertex2f(25, 86);
        glVertex2f(28, 86);
        glVertex2f(28, 87);
        glVertex2f(25, 87);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(0, 0, 0);
        glVertex2f(28, 85);
        glVertex2f(31, 85);
        glVertex2f(31, 86);
        glVertex2f(28, 86);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(0, 0, 0);
        glVertex2f(31, 84);
        glVertex2f(33, 84);
        glVertex2f(33, 85);
        glVertex2f(31, 85);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(0, 0, 0);
        glVertex2f(33, 83);
        glVertex2f(36, 83);
        glVertex2f(36, 84);
        glVertex2f(33, 84);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(0, 0, 0);
        glVertex2f(36, 82);
        glVertex2f(38, 82);
        glVertex2f(38, 83);
        glVertex2f(36, 83);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(0, 0, 0);
        glVertex2f(31, 81);
        glVertex2f(36, 81);
        glVertex2f(36, 82);
        glVertex2f(31, 82);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(0, 0, 0);
        glVertex2f(24, 80);
        glVertex2f(31, 80);
        glVertex2f(31, 81);
        glVertex2f(24, 81);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(0, 0, 0);
        glVertex2f(23, 81);
        glVertex2f(23, 80);
        glVertex2f(13, 80);
        glVertex2f(13, 81);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(0, 0, 0);
        glVertex2f(24, 80);
        glVertex2f(24, 78);
        glVertex2f(13, 78);
        glVertex2f(13, 80);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(0, 0, 0);
        glVertex2f(23, 78);
        glVertex2f(23, 76);
        glVertex2f(14, 76);
        glVertex2f(14, 78);
        glEnd();

        glBegin(GL_POLYGON);//Kemungkinan Ganti warna
        glColor3ub(119, 136, 153);
        glVertex2f(14, 79);
        glVertex2f(23, 79);
        glVertex2f(23, 80);
        glVertex2f(14, 80);
        glEnd();

        glBegin(GL_POLYGON);//Kemungkinan Ganti warna
        glColor3ub(93, 138, 168);
        glVertex2f(15, 77);
        glVertex2f(20, 77);
        glVertex2f(20, 78);
        glVertex2f(15, 78);
        glEnd();

        glBegin(GL_POLYGON);//Kemungkinan Ganti warna
        glColor3ub(119, 136, 153);
        glVertex2f(21, 77);
        glVertex2f(22, 77);
        glVertex2f(22, 78);
        glVertex2f(21, 78);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(0, 0, 0);
        glVertex2f(13, 80);
        glVertex2f(13, 79);
        glVertex2f(9, 79);
        glVertex2f(9, 80);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(0, 0, 0);
        glVertex2f(3, 79);
        glVertex2f(4, 79);
        glVertex2f(4, 80);
        glVertex2f(3, 80);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(0, 0, 0);
        glVertex2f(4, 78);
        glVertex2f(9, 78);
        glVertex2f(9, 81);
        glVertex2f(4, 81);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(0, 0, 0);
        glVertex2f(5, 76);
        glVertex2f(8, 76);
        glVertex2f(8, 78);
        glVertex2f(5, 78);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(0, 0, 0);
        glVertex2f(8, 77);
        glVertex2f(9, 77);
        glVertex2f(9, 78);
        glVertex2f(8, 78);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(0, 0, 0);
        glVertex2f(9, 78);
        glVertex2f(11, 78);
        glVertex2f(11, 79);
        glVertex2f(9, 79);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(119, 136, 153);
        glVertex2f(5, 79);
        glVertex2f(9, 79);
        glVertex2f(9, 80);
        glVertex2f(5, 80);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(119, 136, 153);
        glVertex2f(6, 77);
        glVertex2f(8, 77);
        glVertex2f(8, 78);
        glVertex2f(6, 78);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(0, 0, 0);
        glVertex2f(2, 80);
        glVertex2f(3, 80);
        glVertex2f(3, 82);
        glVertex2f(2, 82);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(0, 0, 0);
        glVertex2f(1, 82);
        glVertex2f(2, 82);
        glVertex2f(2, 84);
        glVertex2f(1, 84);
        glEnd();

        glPopMatrix();

    }

    void movePesawat() {
        glPushMatrix();
        glTranslated(moveX, 0, 0);
        pesawatt();
        glPopMatrix();
    }
};


#endif //OPENGLLINUXTEST_PESAWAT_H
