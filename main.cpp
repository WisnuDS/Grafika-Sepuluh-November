#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <cstring>
#include <iostream>
#include "Bom.h"
#include "Pesawat.h"

//Gambar-Gambar
Pesawat pesawat[5];
int nilaiX[208] = {78, 86, 86, 78, 79, 79, 86, 86, 81, 81, 86, 86, 82, 82, 86, 86, 82, 87, 87, 82, 82, 87, 87, 82, 82,
                   88, 88, 82, 78, 86, 86, 78, 82, 82, 86, 86, 83, 84, 84, 83, 83, 86, 86, 83, 78, 79, 79, 78, 82, 84,
                   84, 82, 80, 88, 88, 80, 81, 88, 88, 81, 82, 88, 88, 82, 83, 88, 88, 83, 83, 87, 87, 83, 84, 86, 86,
                   84, 80, 88, 88, 80, 82, 88, 88, 82, 84, 85, 85, 84, 84, 86, 86, 84, 86, 87, 87, 86, 85, 86, 86, 85,
                   83, 83, 77, 77, 74, 77, 77, 74, 78, 78, 74, 74, 73, 79, 79, 73, 76, 77, 77, 76, 73, 77, 77, 73, 75,
                   76, 76, 75, 75, 76, 76, 75, 74, 75, 75, 74, 77, 79, 79, 77, 75, 77, 77, 75, 74, 75, 75, 74, 72, 73,
                   73, 72, 73, 74, 74, 73, 87, 88, 88, 87, 86, 88, 88, 86, 85, 88, 88, 85, 86, 87, 87, 86, 86, 88, 88,
                   86, 84, 85, 85, 84, 85, 88, 88, 85, 83, 84, 84, 83, 84, 88, 88, 84, 84, 88, 88, 84, 85, 88, 88, 85};

double nilaiXD[8] = {86.44, 86.85, 86.85, 86.44, 87.6, 88, 88, 87.6};
int h = nilaiX[26];
float tomoColisionPoint[2][2] = {
        {43.8, 24},
        {61.8, 1.8}
};

int tomoMove;

int waktuUmum;

int waktuBom;

int menit;

int jam;

int waktuTimer;

int test = 0;

bool mouseColision;

int nyawa = 5;

bool scane3;

void resetAll();

void hati(){
    glPushMatrix();
    glScaled(0.3,0.3,0);
    glTranslated(480,0,0);
    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
    glVertex2f(81,1);
    glVertex2f(82,1);
    glVertex2f(82,2);
    glVertex2f(83,2);
    glVertex2f(83,3);
    glVertex2f(84,3);
    glVertex2f(84,4);
    glVertex2f(85,4);
    glVertex2f(85,5);
    glVertex2f(86,5);
    glVertex2f(86,6);
    glVertex2f(87,6);
    glVertex2f(87,7);
    glVertex2f(88,7);
    glVertex2f(88,13);
    glVertex2f(87,13);
    glVertex2f(87,14);
    glVertex2f(86,14);
    glVertex2f(86,15);
    glVertex2f(83,15);
    glVertex2f(83,14);
    glVertex2f(82,14);
    glVertex2f(82,13);
    glVertex2f(81,13);
    glVertex2f(81,14);
    glVertex2f(80,14);
    glVertex2f(80,15);
    glVertex2f(77,15);
    glVertex2f(77,14);
    glVertex2f(76,14);
    glVertex2f(76,13);
    glVertex2f(75,13);
    glVertex2f(75,7);
    glVertex2f(76,7);
    glVertex2f(76,6);
    glVertex2f(77,6);
    glVertex2f(77,5);
    glVertex2f(78,5);
    glVertex2f(78,4);
    glVertex2f(79,4);
    glVertex2f(79,3);
    glVertex2f(80,3);
    glVertex2f(80,2);
    glVertex2f(81,2);
    glEnd();
    glPopMatrix();

}

void displayNyawa(){
    int a = 0;
    for (int i = 0; i < nyawa; ++i) {
        glPushMatrix();
        glTranslated(a, 0, 0);
        hati();
        glPopMatrix();
        a -= 5;
    }
}

void tomoColision() {
    glPushMatrix();
//    glScaled(0.6,0.6,0);
//    glEnable(GL_BLEND);
//    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glBegin(GL_POLYGON);
    glColor4f(0, 0, 0, 0);
    glVertex2f(tomoColisionPoint[0][0], tomoColisionPoint[1][1]);
    glVertex2f(tomoColisionPoint[1][0], tomoColisionPoint[1][1]);
    glVertex2f(tomoColisionPoint[1][0], tomoColisionPoint[0][1]);
    glVertex2f(tomoColisionPoint[0][0], tomoColisionPoint[0][1]);
    glEnd();
    glPopMatrix();
}

void kaki() {
    glBegin(GL_POLYGON);
    glColor3ub(71, 71, 71);
    glVertex2f(nilaiX[0], 3);
    glVertex2f(nilaiX[1], 3);
    glVertex2f(nilaiX[2], 5);
    glVertex2f(nilaiX[3], 5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(71, 71, 71);
    glVertex2f(nilaiX[4], 5);
    glVertex2f(nilaiX[5], 6);
    glVertex2f(nilaiX[6], 6);
    glVertex2f(nilaiX[7], 5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(71, 71, 71);
    glVertex2f(nilaiX[8], 6);
    glVertex2f(nilaiX[9], 7);
    glVertex2f(nilaiX[10], 7);
    glVertex2f(nilaiX[11], 6);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(71, 71, 71);
    glVertex2f(nilaiX[12], 7);
    glVertex2f(nilaiX[13], 9);
    glVertex2f(nilaiX[14], 9);
    glVertex2f(nilaiX[15], 7);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(36, 40, 15);
    glVertex2f(nilaiX[16], 9);
    glVertex2f(nilaiX[17], 9);
    glVertex2f(nilaiX[18], 12);
    glVertex2f(nilaiX[19], 12);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(36, 40, 15);
    glVertex2f(nilaiX[20], 11);
    glVertex2f(nilaiX[21], 11);
    glVertex2f(nilaiX[22], 15);
    glVertex2f(nilaiX[23], 15);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(36, 40, 15);
    glVertex2f(nilaiX[24], 14);
    glVertex2f(nilaiX[25], 14);
    glVertex2f(nilaiX[26], 17);
    glVertex2f(nilaiX[27], 17);
    glEnd();

    glBegin(GL_POLYGON);//78, 86, 86, 78
    glColor3ub(0, 0, 0);
    glVertex2f(nilaiX[28], 3);
    glVertex2f(nilaiX[29], 3);
    glVertex2f(nilaiX[30], 4);
    glVertex2f(nilaiX[31], 4);
    glEnd();

    glBegin(GL_POLYGON);//82, 88, 88, 82
    glColor3ub(0, 0, 0);
    glVertex2f(nilaiX[32], 8);
    glVertex2f(nilaiX[33], 9);
    glVertex2f(nilaiX[34], 9);
    glVertex2f(nilaiX[35], 8);
    glEnd();

    glBegin(GL_POLYGON);//82, 88, 88, 82
    glColor3ub(0, 0, 0);
    glVertex2f(nilaiX[36], 3);
    glVertex2f(nilaiX[37], 3);
    glVertex2f(nilaiX[38], 5);
    glVertex2f(nilaiX[39], 5);
    glEnd();

    glBegin(GL_POLYGON);//82, 88, 88, 82
    glColor3ub(0, 0, 0);
    glVertex2f(nilaiX[40], 5);
    glVertex2f(nilaiX[41], 5);
    glVertex2f(nilaiX[42], 6);
    glVertex2f(nilaiX[43], 6);
    glEnd();

    glBegin(GL_POLYGON);//82, 88, 88, 82
    glColor3ub(0, 0, 0);
    glVertex2f(nilaiX[44], 4);
    glVertex2f(nilaiX[45], 4);
    glVertex2f(nilaiX[46], 5);
    glVertex2f(nilaiX[47], 5);
    glEnd();

    glBegin(GL_POLYGON);//82, 88, 88, 82
    glColor3ub(0, 0, 0);
    glVertex2f(nilaiX[48], 14);
    glVertex2f(nilaiX[49], 14);
    glVertex2f(nilaiX[50], 11);
    glVertex2f(nilaiX[51], 11);
    glEnd();


    for (int i = 0; i < 52; ++i) {
        nilaiX[i] = (2 * h) - nilaiX[i];
    }

    glBegin(GL_POLYGON);
    glColor3ub(71, 71, 71);
    glVertex2f(nilaiX[0], 3);
    glVertex2f(nilaiX[1], 3);
    glVertex2f(nilaiX[2], 5);
    glVertex2f(nilaiX[3], 5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(71, 71, 71);
    glVertex2f(nilaiX[4], 5);
    glVertex2f(nilaiX[5], 6);
    glVertex2f(nilaiX[6], 6);
    glVertex2f(nilaiX[7], 5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(71, 71, 71);
    glVertex2f(nilaiX[8], 6);
    glVertex2f(nilaiX[9], 7);
    glVertex2f(nilaiX[10], 7);
    glVertex2f(nilaiX[11], 6);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(71, 71, 71);
    glVertex2f(nilaiX[12], 7);
    glVertex2f(nilaiX[13], 9);
    glVertex2f(nilaiX[14], 9);
    glVertex2f(nilaiX[15], 7);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(36, 40, 15);
    glVertex2f(nilaiX[16], 9);
    glVertex2f(nilaiX[17], 9);
    glVertex2f(nilaiX[18], 12);
    glVertex2f(nilaiX[19], 12);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(36, 40, 15);
    glVertex2f(nilaiX[20], 11);
    glVertex2f(nilaiX[21], 11);
    glVertex2f(nilaiX[22], 15);
    glVertex2f(nilaiX[23], 15);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(36, 40, 15);
    glVertex2f(nilaiX[24], 14);
    glVertex2f(nilaiX[25], 14);
    glVertex2f(nilaiX[26], 17);
    glVertex2f(nilaiX[27], 17);
    glEnd();

    glBegin(GL_POLYGON);//78, 86, 86, 78
    glColor3ub(0, 0, 0);
    glVertex2f(nilaiX[28], 3);
    glVertex2f(nilaiX[29], 3);
    glVertex2f(nilaiX[30], 4);
    glVertex2f(nilaiX[31], 4);
    glEnd();

    glBegin(GL_POLYGON);//82, 88, 88, 82
    glColor3ub(0, 0, 0);
    glVertex2f(nilaiX[32], 8);
    glVertex2f(nilaiX[33], 9);
    glVertex2f(nilaiX[34], 9);
    glVertex2f(nilaiX[35], 8);
    glEnd();

    glBegin(GL_POLYGON);//82, 88, 88, 82
    glColor3ub(0, 0, 0);
    glVertex2f(nilaiX[36], 3);
    glVertex2f(nilaiX[37], 3);
    glVertex2f(nilaiX[38], 5);
    glVertex2f(nilaiX[39], 5);
    glEnd();

    glBegin(GL_POLYGON);//82, 88, 88, 82
    glColor3ub(0, 0, 0);
    glVertex2f(nilaiX[40], 5);
    glVertex2f(nilaiX[41], 5);
    glVertex2f(nilaiX[42], 6);
    glVertex2f(nilaiX[43], 6);
    glEnd();

    glBegin(GL_POLYGON);//82, 88, 88, 82
    glColor3ub(0, 0, 0);
    glVertex2f(nilaiX[44], 4);
    glVertex2f(nilaiX[45], 4);
    glVertex2f(nilaiX[46], 5);
    glVertex2f(nilaiX[47], 5);
    glEnd();

    glBegin(GL_POLYGON);//82, 88, 88, 82
    glColor3ub(0, 0, 0);
    glVertex2f(nilaiX[48], 14);
    glVertex2f(nilaiX[49], 14);
    glVertex2f(nilaiX[50], 11);
    glVertex2f(nilaiX[51], 11);
    glEnd();

    for (int i = 0; i < 52; ++i) {
        nilaiX[i] = (2 * h) - nilaiX[i];
    }

}

void badan() {
    glBegin(GL_POLYGON);
    glColor3ub(36, 40, 15);
    glVertex2f(nilaiX[52], 17);
    glVertex2f(nilaiX[53], 17);
    glVertex2f(nilaiX[54], 19);
    glVertex2f(nilaiX[55], 19);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(36, 40, 15);
    glVertex2f(nilaiX[56], 19);
    glVertex2f(nilaiX[57], 19);
    glVertex2f(nilaiX[58], 21);
    glVertex2f(nilaiX[59], 21);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(71, 71, 71);
    glVertex2f(nilaiX[60], 21);
    glVertex2f(nilaiX[61], 21);
    glVertex2f(nilaiX[62], 23);
    glVertex2f(nilaiX[63], 23);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(71, 71, 71);
    glVertex2f(nilaiX[64], 23);
    glVertex2f(nilaiX[65], 23);
    glVertex2f(nilaiX[66], 26);
    glVertex2f(nilaiX[67], 26);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(71, 71, 71);
    glVertex2f(nilaiX[68], 26);
    glVertex2f(nilaiX[69], 26);
    glVertex2f(nilaiX[70], 27);
    glVertex2f(nilaiX[71], 27);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(71, 71, 71);
    glVertex2f(nilaiX[72], 27);
    glVertex2f(nilaiX[73], 27);
    glVertex2f(nilaiX[74], 28);
    glVertex2f(nilaiX[75], 28);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(71, 71, 71);
    glVertex2f(nilaiX[76], 17);
    glVertex2f(nilaiX[77], 17);
    glVertex2f(nilaiX[78], 18);
    glVertex2f(nilaiX[79], 18);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(71, 71, 71);
    glVertex2f(nilaiX[80], 18);
    glVertex2f(nilaiX[81], 18);
    glVertex2f(nilaiX[82], 21);
    glVertex2f(nilaiX[83], 21);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 0);
    glVertex2f(nilaiX[84], 17);
    glVertex2f(nilaiX[85], 17);
    glVertex2f(nilaiX[86], 19);
    glVertex2f(nilaiX[87], 19);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 0);
    glVertex2f(nilaiX[88], 19);
    glVertex2f(nilaiX[89], 19);
    glVertex2f(nilaiX[90], 20);
    glVertex2f(nilaiX[91], 20);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 0);
    glVertex2f(nilaiX[92], 17);
    glVertex2f(nilaiX[93], 17);
    glVertex2f(nilaiX[94], 19);
    glVertex2f(nilaiX[95], 19);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 0);
    glVertex2f(nilaiX[96], 22);
    glVertex2f(nilaiX[97], 22);
    glVertex2f(nilaiX[98], 28);
    glVertex2f(nilaiX[99], 28);
    glEnd();

    for (int i = 52; i < 100; ++i) {
        nilaiX[i] = (2 * h) - nilaiX[i];
    }

    glBegin(GL_POLYGON);
    glColor3ub(36, 40, 15);
    glVertex2f(nilaiX[52], 17);
    glVertex2f(nilaiX[53], 17);
    glVertex2f(nilaiX[54], 19);
    glVertex2f(nilaiX[55], 19);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(36, 40, 15);
    glVertex2f(nilaiX[56], 19);
    glVertex2f(nilaiX[57], 19);
    glVertex2f(nilaiX[58], 21);
    glVertex2f(nilaiX[59], 21);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(71, 71, 71);
    glVertex2f(nilaiX[60], 21);
    glVertex2f(nilaiX[61], 21);
    glVertex2f(nilaiX[62], 23);
    glVertex2f(nilaiX[63], 23);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(71, 71, 71);
    glVertex2f(nilaiX[64], 23);
    glVertex2f(nilaiX[65], 23);
    glVertex2f(nilaiX[66], 26);
    glVertex2f(nilaiX[67], 26);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(71, 71, 71);
    glVertex2f(nilaiX[68], 26);
    glVertex2f(nilaiX[69], 26);
    glVertex2f(nilaiX[70], 27);
    glVertex2f(nilaiX[71], 27);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(71, 71, 71);
    glVertex2f(nilaiX[72], 27);
    glVertex2f(nilaiX[73], 27);
    glVertex2f(nilaiX[74], 28);
    glVertex2f(nilaiX[75], 28);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(71, 71, 71);
    glVertex2f(nilaiX[76], 17);
    glVertex2f(nilaiX[77], 17);
    glVertex2f(nilaiX[78], 18);
    glVertex2f(nilaiX[79], 18);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(71, 71, 71);
    glVertex2f(nilaiX[80], 18);
    glVertex2f(nilaiX[81], 18);
    glVertex2f(nilaiX[82], 21);
    glVertex2f(nilaiX[83], 21);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 0);
    glVertex2f(nilaiX[84], 17);
    glVertex2f(nilaiX[85], 17);
    glVertex2f(nilaiX[86], 19);
    glVertex2f(nilaiX[87], 19);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 0);
    glVertex2f(nilaiX[88], 19);
    glVertex2f(nilaiX[89], 19);
    glVertex2f(nilaiX[90], 20);
    glVertex2f(nilaiX[91], 20);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 0);
    glVertex2f(nilaiX[92], 17);
    glVertex2f(nilaiX[93], 17);
    glVertex2f(nilaiX[94], 19);
    glVertex2f(nilaiX[95], 19);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 0);
    glVertex2f(nilaiX[96], 22);
    glVertex2f(nilaiX[97], 22);
    glVertex2f(nilaiX[98], 28);
    glVertex2f(nilaiX[99], 28);
    glEnd();

    for (int i = 52; i < 100; ++i) {
        nilaiX[i] = (2 * h) - nilaiX[i];
    }

}

void tangan() {
    glBegin(GL_POLYGON);
    glColor3ub(36, 40, 15);
    glVertex2f(nilaiX[100], 27);
    glVertex2f(nilaiX[101], 23);
    glVertex2f(nilaiX[102], 23);
    glVertex2f(nilaiX[103], 27);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(241, 194, 125);
    glVertex2f(nilaiX[104], 23);
    glVertex2f(nilaiX[105], 23);
    glVertex2f(nilaiX[106], 31);
    glVertex2f(nilaiX[107], 31);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(241, 194, 125);
    glVertex2f(nilaiX[108], 31);
    glVertex2f(nilaiX[109], 32);
    glVertex2f(nilaiX[110], 32);
    glVertex2f(nilaiX[111], 31);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(241, 194, 125);
    glVertex2f(nilaiX[112], 32);
    glVertex2f(nilaiX[113], 32);
    glVertex2f(nilaiX[114], 34);
    glVertex2f(nilaiX[115], 34);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(241, 194, 125);
    glVertex2f(nilaiX[116], 34);
    glVertex2f(nilaiX[117], 34);
    glVertex2f(nilaiX[118], 38);
    glVertex2f(nilaiX[119], 38);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(198, 134, 66);
    glVertex2f(nilaiX[120], 32);
    glVertex2f(nilaiX[121], 32);
    glVertex2f(nilaiX[122], 33);
    glVertex2f(nilaiX[123], 33);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(198, 134, 66);
    glVertex2f(nilaiX[124], 31);
    glVertex2f(nilaiX[125], 31);
    glVertex2f(nilaiX[126], 32);
    glVertex2f(nilaiX[127], 32);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(198, 134, 66);
    glVertex2f(nilaiX[128], 34);
    glVertex2f(nilaiX[129], 34);
    glVertex2f(nilaiX[130], 36);
    glVertex2f(nilaiX[131], 36);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(198, 134, 66);
    glVertex2f(nilaiX[132], 33);
    glVertex2f(nilaiX[133], 33);
    glVertex2f(nilaiX[134], 34);
    glVertex2f(nilaiX[135], 34);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 0);
    glVertex2f(nilaiX[136], 34);
    glVertex2f(nilaiX[137], 34);
    glVertex2f(nilaiX[138], 41);
    glVertex2f(nilaiX[139], 41);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 0);
    glVertex2f(nilaiX[140], 36);
    glVertex2f(nilaiX[141], 36);
    glVertex2f(nilaiX[142], 37);
    glVertex2f(nilaiX[143], 37);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 0);
    glVertex2f(nilaiX[144], 34);
    glVertex2f(nilaiX[145], 34);
    glVertex2f(nilaiX[146], 37);
    glVertex2f(nilaiX[147], 37);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 0);
    glVertex2f(nilaiX[148], 31);
    glVertex2f(nilaiX[149], 31);
    glVertex2f(nilaiX[150], 33);
    glVertex2f(nilaiX[151], 33);
    glEnd();

//    posisiTerakhirKiri = nilaiX[151];

    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 0);
    glVertex2f(nilaiX[152], 31);
    glVertex2f(nilaiX[153], 31);
    glVertex2f(nilaiX[154], 32);
    glVertex2f(nilaiX[155], 32);
    glEnd();

    for (int i = 100; i < 156; ++i) {
        nilaiX[i] = (2 * h) - nilaiX[i];
    }

    glBegin(GL_POLYGON);
    glColor3ub(36, 40, 15);
    glVertex2f(nilaiX[100], 27);
    glVertex2f(nilaiX[101], 23);
    glVertex2f(nilaiX[102], 23);
    glVertex2f(nilaiX[103], 27);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(241, 194, 125);
    glVertex2f(nilaiX[104], 23);
    glVertex2f(nilaiX[105], 23);
    glVertex2f(nilaiX[106], 31);
    glVertex2f(nilaiX[107], 31);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(241, 194, 125);
    glVertex2f(nilaiX[108], 31);
    glVertex2f(nilaiX[109], 32);
    glVertex2f(nilaiX[110], 32);
    glVertex2f(nilaiX[111], 31);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(241, 194, 125);
    glVertex2f(nilaiX[112], 32);
    glVertex2f(nilaiX[113], 32);
    glVertex2f(nilaiX[114], 34);
    glVertex2f(nilaiX[115], 34);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(241, 194, 125);
    glVertex2f(nilaiX[116], 34);
    glVertex2f(nilaiX[117], 34);
    glVertex2f(nilaiX[118], 38);
    glVertex2f(nilaiX[119], 38);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(198, 134, 66);
    glVertex2f(nilaiX[120], 32);
    glVertex2f(nilaiX[121], 32);
    glVertex2f(nilaiX[122], 33);
    glVertex2f(nilaiX[123], 33);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(198, 134, 66);
    glVertex2f(nilaiX[124], 31);
    glVertex2f(nilaiX[125], 31);
    glVertex2f(nilaiX[126], 32);
    glVertex2f(nilaiX[127], 32);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(198, 134, 66);
    glVertex2f(nilaiX[128], 34);
    glVertex2f(nilaiX[129], 34);
    glVertex2f(nilaiX[130], 36);
    glVertex2f(nilaiX[131], 36);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(198, 134, 66);
    glVertex2f(nilaiX[132], 33);
    glVertex2f(nilaiX[133], 33);
    glVertex2f(nilaiX[134], 34);
    glVertex2f(nilaiX[135], 34);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 0);
    glVertex2f(nilaiX[136], 34);
    glVertex2f(nilaiX[137], 34);
    glVertex2f(nilaiX[138], 41);
    glVertex2f(nilaiX[139], 41);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 0);
    glVertex2f(nilaiX[140], 36);
    glVertex2f(nilaiX[141], 36);
    glVertex2f(nilaiX[142], 37);
    glVertex2f(nilaiX[143], 37);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 0);
    glVertex2f(nilaiX[144], 34);
    glVertex2f(nilaiX[145], 34);
    glVertex2f(nilaiX[146], 37);
    glVertex2f(nilaiX[147], 37);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 0);
    glVertex2f(nilaiX[148], 31);
    glVertex2f(nilaiX[149], 31);
    glVertex2f(nilaiX[150], 33);
    glVertex2f(nilaiX[151], 33);
    glEnd();

//    posisiTerakhirKanan = nilaiX[151];

    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 0);
    glVertex2f(nilaiX[152], 31);
    glVertex2f(nilaiX[153], 31);
    glVertex2f(nilaiX[154], 32);
    glVertex2f(nilaiX[155], 32);
    glEnd();

    for (int i = 100; i < 156; ++i) {
        nilaiX[i] = (2 * h) - nilaiX[i];
    }
}

void kepala() {
    glBegin(GL_POLYGON);
    glColor3ub(241, 194, 125);
    glVertex2f(nilaiX[156], 26);
    glVertex2f(nilaiX[157], 26);
    glVertex2f(nilaiX[158], 27);
    glVertex2f(nilaiX[159], 27);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(241, 194, 125);
    glVertex2f(nilaiX[160], 27);
    glVertex2f(nilaiX[161], 27);
    glVertex2f(nilaiX[162], 28);
    glVertex2f(nilaiX[163], 28);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(241, 194, 125);
    glVertex2f(nilaiX[164], 28);
    glVertex2f(nilaiX[165], 28);
    glVertex2f(nilaiX[166], 34);
    glVertex2f(nilaiX[167], 34);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 0);
    glVertex2f(nilaiX[168], 31);
    glVertex2f(nilaiX[169], 31);
    glVertex2f(nilaiX[170], 33);
    glVertex2f(nilaiX[171], 33);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 255);
    glVertex2f(nilaiXD[0], 32.01);
    glVertex2f(nilaiXD[1], 32.01);
    glVertex2f(nilaiXD[2], 32.57);
    glVertex2f(nilaiXD[3], 32.57);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 255);
    glVertex2f(nilaiX[172], 28);
    glVertex2f(nilaiX[173], 28);
    glVertex2f(nilaiX[174], 29);
    glVertex2f(nilaiX[175], 29);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(233, 137, 120);
    glVertex2f(nilaiXD[4], 29.8);
    glVertex2f(nilaiXD[5], 29.8);
    glVertex2f(nilaiXD[6], 30.75);
    glVertex2f(nilaiXD[7], 30.75);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(16, 18, 7);
    glVertex2f(nilaiX[176], 30);
    glVertex2f(nilaiX[177], 30);
    glVertex2f(nilaiX[178], 35);
    glVertex2f(nilaiX[179], 35);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(16, 18, 7);
    glVertex2f(nilaiX[180], 34);
    glVertex2f(nilaiX[181], 34);
    glVertex2f(nilaiX[182], 35);
    glVertex2f(nilaiX[183], 35);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(36, 40, 15);
    glVertex2f(nilaiX[184], 31);
    glVertex2f(nilaiX[185], 31);
    glVertex2f(nilaiX[186], 36);
    glVertex2f(nilaiX[187], 36);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(36, 40, 15);
    glVertex2f(nilaiX[188], 35);
    glVertex2f(nilaiX[189], 35);
    glVertex2f(nilaiX[190], 36);
    glVertex2f(nilaiX[191], 36);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(36, 40, 15);
    glVertex2f(nilaiX[192], 36);
    glVertex2f(nilaiX[193], 36);
    glVertex2f(nilaiX[194], 37);
    glVertex2f(nilaiX[195], 37);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(36, 40, 15);
    glVertex2f(nilaiX[196], 37);
    glVertex2f(nilaiX[197], 37);
    glVertex2f(nilaiX[198], 38);
    glVertex2f(nilaiX[199], 38);
    glEnd();

    for (int i = 156; i < 200; ++i) {
        nilaiX[i] = (2 * h) - nilaiX[i];
    }
    for (int i = 0; i < 8; ++i) {
        nilaiXD[i] = (2 * h) - nilaiXD[i];
    }

    glBegin(GL_POLYGON);
    glColor3ub(241, 194, 125);
    glVertex2f(nilaiX[156], 26);
    glVertex2f(nilaiX[157], 26);
    glVertex2f(nilaiX[158], 27);
    glVertex2f(nilaiX[159], 27);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(241, 194, 125);
    glVertex2f(nilaiX[160], 27);
    glVertex2f(nilaiX[161], 27);
    glVertex2f(nilaiX[162], 28);
    glVertex2f(nilaiX[163], 28);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(241, 194, 125);
    glVertex2f(nilaiX[164], 28);
    glVertex2f(nilaiX[165], 28);
    glVertex2f(nilaiX[166], 34);
    glVertex2f(nilaiX[167], 34);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 0);
    glVertex2f(nilaiX[168], 31);
    glVertex2f(nilaiX[169], 31);
    glVertex2f(nilaiX[170], 33);
    glVertex2f(nilaiX[171], 33);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 255);
    glVertex2f(nilaiXD[0], 32.01);
    glVertex2f(nilaiXD[1], 32.01);
    glVertex2f(nilaiXD[2], 32.57);
    glVertex2f(nilaiXD[3], 32.57);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 255);
    glVertex2f(nilaiX[172], 28);
    glVertex2f(nilaiX[173], 28);
    glVertex2f(nilaiX[174], 29);
    glVertex2f(nilaiX[175], 29);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(233, 137, 120);
    glVertex2f(nilaiXD[4], 29.8);
    glVertex2f(nilaiXD[5], 29.8);
    glVertex2f(nilaiXD[6], 30.75);
    glVertex2f(nilaiXD[7], 30.75);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(16, 18, 7);
    glVertex2f(nilaiX[176], 30);
    glVertex2f(nilaiX[177], 30);
    glVertex2f(nilaiX[178], 35);
    glVertex2f(nilaiX[179], 35);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(16, 18, 7);
    glVertex2f(nilaiX[180], 34);
    glVertex2f(nilaiX[181], 34);
    glVertex2f(nilaiX[182], 35);
    glVertex2f(nilaiX[183], 35);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(36, 40, 15);
    glVertex2f(nilaiX[184], 31);
    glVertex2f(nilaiX[185], 31);
    glVertex2f(nilaiX[186], 36);
    glVertex2f(nilaiX[187], 36);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(36, 40, 15);
    glVertex2f(nilaiX[188], 35);
    glVertex2f(nilaiX[189], 35);
    glVertex2f(nilaiX[190], 36);
    glVertex2f(nilaiX[191], 36);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(36, 40, 15);
    glVertex2f(nilaiX[192], 36);
    glVertex2f(nilaiX[193], 36);
    glVertex2f(nilaiX[194], 37);
    glVertex2f(nilaiX[195], 37);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(36, 40, 15);
    glVertex2f(nilaiX[196], 37);
    glVertex2f(nilaiX[197], 37);
    glVertex2f(nilaiX[198], 38);
    glVertex2f(nilaiX[199], 38);
    glEnd();

    for (int i = 156; i < 200; ++i) {
        nilaiX[i] = (2 * h) - nilaiX[i];
    }
    for (int i = 0; i < 8; ++i) {
        nilaiXD[i] = (2 * h) - nilaiXD[i];
    }
}

void tomo(void) {
    glPushMatrix();
    glScaled(0.6, 0.6, 0);
    kaki();
    badan();
    tangan();
    kepala();
    glPopMatrix();
}

void backgroundJalan(void) { //Function Buat Jalan
    int width = 171;
    int heigh = 91;
    glBegin(GL_POLYGON);//Ini Layer yang bawah sendiri
    glColor3ub(194, 194, 194);
    glVertex2f(0, 0);
    glVertex2f(0, 3);
    glVertex2f(width, 3);
    glVertex2f(width, 0);
    glEnd();

    glBegin(GL_POLYGON);//Ini atasnya
    glColor3ub(180, 180, 180);
    glVertex2f(0, 3);
    glVertex2f(0, 5);
    glVertex2f(width, 5);
    glVertex2f(width, 3);
    glEnd();

    glBegin(GL_POLYGON);//Atasnya lagi
    glColor3ub(158, 158, 158);
    glVertex2f(0, 5);
    glVertex2f(0, 14);
    glVertex2f(width, 14);
    glVertex2f(width, 5);
    glEnd();

    glBegin(GL_POLYGON);//Atasnya lagi yang agak gelap
    glColor3ub(117, 117, 117);
    glVertex2f(0, 14);
    glVertex2f(0, 16);
    glVertex2f(width, 16);
    glVertex2f(width, 14);
    glEnd();

    int garisPutus[4];//Ini koordinat X dari jalan aku bikin Array supaya Bisa Aku ubah nilainya
    garisPutus[0] = 5;
    garisPutus[1] = 5;
    garisPutus[2] = 29;
    garisPutus[3] = 29;
    for (int i = 0; i < 5; ++i) {//Ini perulangan buat jalan putus"nya biar ga capek bikin
        glBegin(GL_POLYGON);
        glColor3ub(255, 255, 255);
        glVertex2f(garisPutus[0], 5);
        glVertex2f(garisPutus[1], 7);
        glVertex2f(garisPutus[2], 7);
        glVertex2f(garisPutus[3], 5);
        glEnd();
        garisPutus[0] += 34;//Koordinat Xnya Aku tambahin biar gambar selanjutnya geser
        garisPutus[1] += 34;
        garisPutus[2] += 34;
        garisPutus[3] += 34;
    }

}

void tumbuhan(void) {//Ini buat rumput biar Ga capek aku pake perulangan juga jadi hemat code
    int posX[27] = {0, 0, 2, 4, 4, 6, 6, 8, 8, 10, 10, 14, 14, 16, 16, 18, 18, 22, 22, 24, 24, 26, 26, 28, 28};
    for (int i = 0; i < 7; ++i) {
        glBegin(GL_POLYGON);
        glColor3ub(4, 48, 16);
        glVertex2f(posX[0], 16);
        glVertex2f(posX[1], 27);
        glVertex2f(posX[2], 27);
        glVertex2f(posX[3], 27);
        glVertex2f(posX[4], 25);
        glVertex2f(posX[5], 25);
        glVertex2f(posX[6], 23);
        glVertex2f(posX[7], 23);
        glVertex2f(posX[8], 25);
        glVertex2f(posX[9], 25);
        glVertex2f(posX[10], 27);
        glVertex2f(posX[11], 27);
        glVertex2f(posX[12], 25);
        glVertex2f(posX[13], 25);
        glVertex2f(posX[14], 23);
        glVertex2f(posX[15], 23);
        glVertex2f(posX[16], 29);
        glVertex2f(posX[17], 29);
        glVertex2f(posX[18], 27);
        glVertex2f(posX[19], 27);
        glVertex2f(posX[20], 25);
        glVertex2f(posX[21], 25);
        glVertex2f(posX[22], 23);
        glVertex2f(posX[23], 23);
        glVertex2f(posX[24], 16);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(34, 191, 47);
        glVertex2f(posX[0], 16);
        glVertex2f(posX[1], 26);
        glVertex2f(posX[2], 26);
        glVertex2f(posX[3], 26);
        glVertex2f(posX[4], 24);
        glVertex2f(posX[5], 24);
        glVertex2f(posX[6], 22);
        glVertex2f(posX[7], 22);
        glVertex2f(posX[8], 24);
        glVertex2f(posX[9], 24);
        glVertex2f(posX[10], 26);
        glVertex2f(posX[11], 26);
        glVertex2f(posX[12], 24);
        glVertex2f(posX[13], 24);
        glVertex2f(posX[14], 22);
        glVertex2f(posX[15], 22);
        glVertex2f(posX[16], 28);
        glVertex2f(posX[17], 28);
        glVertex2f(posX[18], 26);
        glVertex2f(posX[19], 26);
        glVertex2f(posX[20], 24);
        glVertex2f(posX[21], 24);
        glVertex2f(posX[22], 22);
        glVertex2f(posX[23], 22);
        glVertex2f(posX[24], 16);
        glEnd();

        for (int j = 0; j < 25; ++j) {
            posX[j] += 28;
        }
    }

}

void perkotaan(void) {
    int nilaix[12] = {0, 8, 8, 0, 14, 19, 19, 24, 24, 29, 29, 14};
    for (int i = 0; i < 5; ++i) {
        glBegin(GL_POLYGON);
        glColor3ub(130, 52, 0);
        glVertex2f(nilaix[0], 50);
        glVertex2f(nilaix[1], 50);
        glVertex2f(nilaix[2], 16);
        glVertex2f(nilaix[3], 16);
        glEnd();
        glBegin(GL_POLYGON);
        glColor3ub(130, 52, 0);
        glVertex2f(nilaix[4], 55);
        glVertex2f(nilaix[5], 55);
        glVertex2f(nilaix[6], 59);
        glVertex2f(nilaix[7], 59);
        glVertex2f(nilaix[8], 50);
        glVertex2f(nilaix[9], 50);
        glVertex2f(nilaix[10], 16);
        glVertex2f(nilaix[11], 16);
        glEnd();

        for (int j = 0; j < 12; ++j) {
            nilaix[j] += 35;
        }
    }
}

void background(void) {
    glBegin(GL_POLYGON);
    glColor3ub(99, 37, 33);
    glVertex2f(0, 91);
    glVertex2f(171, 91);
    glColor3ub(255, 128, 0);
    glVertex2f(171, 0);
    glVertex2f(0, 0);
    glEnd();
}

void backgroundTransparent(void) {
    glPushMatrix();
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glBegin(GL_POLYGON);
    glColor4f(0.0f, 0.0f, 0.0f,0.5f);
    glVertex2f(0, 91);
    glVertex2f(171, 91);
    glVertex2f(171, 0);
    glVertex2f(0, 0);
    glEnd();
    glPopMatrix();
}

void fullBackground(){
    background();
    perkotaan();
    tumbuhan();
    backgroundJalan();
}

void boxMenu(){
    glPushMatrix();
    glTranslated(24,0,0);
    glScaled(40,30,0);
    glBegin(GL_QUADS);
    glColor3ub(250, 210, 100);
    glVertex2f(1,1);
    glVertex2f(1,2);
    glVertex2f(2,2);
    glVertex2f(2,1);
    glEnd();
    glPopMatrix();
}

void output(int x, int y, float r, float g, float b, char *string, void *font) {
    glColor3f(r, g, b);
    glRasterPos2f(x, y);
    int len, i;
    len = (int) strlen(string);
    for (i = 0; i < len; i++) {
        glutBitmapCharacter(font, string[i]);
    }
}

void cetakTimer() {
    char timer[100];
    if (waktuTimer == 60) {
        menit++;
        waktuTimer = 0;
    }
    if (menit == 60) {
        jam++;
        menit = 0;
    }
    sprintf(timer, "%d:%d:%d", jam, menit, waktuTimer);
    output(1, 1, 0, 0, 0, timer, GLUT_BITMAP_HELVETICA_18);
}

void cetakMenu(){
    char menu[100];
    sprintf(menu,"Mulai Game");
    output(76, 44, 0, 0, 0, menu, GLUT_BITMAP_HELVETICA_18);
}

void relativeMenu(){
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(74,41);
    glVertex2f(93,41);
    glVertex2f(93,48);
    glVertex2f(74,48);
    glEnd();
}


void scaneSatu(){
    fullBackground();
    backgroundTransparent();
    boxMenu();
    relativeMenu();
    cetakMenu();

}

void scaneDua(){
    fullBackground();
    tomoColision();
    glPushMatrix();
    glTranslated(tomoMove,0,0);
    tomo();
    glPopMatrix();
    pesawat[0].bom[0].movebom();
    pesawat[0].movePesawat();
    if(waktuUmum > 30){
        pesawat[1].bom[0].movebom();
        pesawat[1].bom[1].movebom();
        pesawat[1].movePesawat();
    }
    if(waktuUmum > 91){
        pesawat[2].bom[0].movebom();
        pesawat[2].bom[1].movebom();
        pesawat[2].bom[2].movebom();
        pesawat[2].movePesawat();
    }
    if(waktuUmum > 154){
        pesawat[3].bom[0].movebom();
        pesawat[3].bom[1].movebom();
        pesawat[3].bom[2].movebom();
        pesawat[3].bom[3].movebom();
        pesawat[3].movePesawat();
    }
    cetakTimer();
    displayNyawa();
}

void cetakHasilAkhir(){
    char timer[100];
    output(75,55,0,0,0,"GAME OVER",GLUT_BITMAP_TIMES_ROMAN_24);
    output(69,52,0,0,0,"Waktu Bertahan Anda adalah:",GLUT_BITMAP_HELVETICA_18);
    sprintf(timer, "%d:%d:%d", jam, menit, waktuTimer);
    output(80,47,0,0,0,timer,GLUT_BITMAP_TIMES_ROMAN_24);
}

void scaneTiga(){
    char menu[100];
    sprintf(menu,"Mulai Lagi");
    fullBackground();
    backgroundTransparent();
    boxMenu();
    cetakHasilAkhir();
    glPushMatrix();
    glTranslated(0,-6,0);
    relativeMenu();
    output(79, 44, 0, 0, 0, menu, GLUT_BITMAP_HELVETICA_18);
    glPopMatrix();
}

//Movement

void keyboardListener(int key, int x, int y) {
    if (key == GLUT_KEY_LEFT) {
        if (tomoMove != -44) {
            tomoMove -= 2;
            h = nilaiX[26];
            tomoColisionPoint[0][0] -= 2;
            tomoColisionPoint[1][0] -= 2;
            glutPostRedisplay();
        }
    } else if (key == GLUT_KEY_RIGHT) {
        if (tomoMove != 110) {
            tomoMove += 2;
            h = nilaiX[26];
            tomoColisionPoint[0][0] += 2;
            tomoColisionPoint[1][0] += 2;
            glutPostRedisplay();
        }
    }
}

void mouseListenner(int button, int state, int x, int y){
    int posX,posY;
    posX = x/8;
    posY = 91-(y/8);
    char debug[100];
    if(button == GLUT_LEFT_BUTTON && state == GLUT_ENTERED){
        if(posX>74 && posX<93 && posY>41 && posY< 48){
            resetAll();
            mouseColision = true;
        }
        if(posX>74 && posX<93 && posY>35 && posY< 42){
            resetAll();
        }
    }
    glutPostRedisplay();
}

void resetAll() {
    nyawa = 5;
    waktuBom=0;
    waktuTimer=0;
    waktuUmum=0;
    scane3 = false;
    jam = 0;
    menit = 0;
    for (int i = 0; i < 4; ++i) {
        pesawat[i].moveX=0;
    }
    mouseColision= true;
}

void bomGravitation(int a) {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < i + 1; ++j) {
            pesawat[i].bom[j].moveBomY --;
        }
    }
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < i + 1; ++j) {
            if (pesawat[i].bom[j].moveBomY < -90 && pesawat[i].moveX == -20) {
                pesawat[i].bom[j].moveBomY += 90;
            }
        }
    }
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < i+1; ++j) {
            if (pesawat[i].bom[j].glCollision(tomoColisionPoint)){
                nyawa--;
                pesawat[i].bom[j].moveBomY=200;
                pesawat[i].bom[j].moveBomX=200;
            }
        }
    }
    glutPostRedisplay();
    glutTimerFunc(10, bomGravitation, 1);
}

void generalTimer(int b) {
    if(mouseColision){
        waktuUmum++;
        waktuTimer++;
    }
    glutTimerFunc(1000, generalTimer, 1);
}

void generalMovement(int a) {
    if(mouseColision) {
        pesawat[0].moveX++;
        if (pesawat[0].moveX > 200) {
            pesawat[0].moveX -= 220;
        }
        if (waktuBom < 7) {
            pesawat[0].bom[0].moveBomX = pesawat[0].moveX;
            pesawat[0].bom[0].moveBomY = 0;
        }
        //pesawat[1]
        if (waktuUmum > 30) {
            pesawat[1].moveX++;
            if (pesawat[1].moveX > 200) {
                pesawat[1].moveX -= 220;
            }
            if (waktuBom < 10) {
                pesawat[1].bom[0].moveBomX = pesawat[1].moveX;
                pesawat[1].bom[0].moveBomY = 0;
            }
            if (waktuBom < 40) {
                pesawat[1].bom[1].moveBomX = pesawat[1].moveX;
                pesawat[1].bom[1].moveBomY = 0;
            }
        }
        //pesawat[2]
        if (waktuUmum > 91) {
            pesawat[2].moveX++;
            if (pesawat[2].moveX > 200) {
                pesawat[2].moveX -= 220;
            }
            if (waktuBom < 10) {
                pesawat[2].bom[0].moveBomX = pesawat[2].moveX;
                pesawat[2].bom[0].moveBomY = 0;
            }
            if (waktuBom < 40) {
                pesawat[2].bom[1].moveBomX = pesawat[2].moveX;
                pesawat[2].bom[1].moveBomY = 0;
            }
            if (waktuBom < 70) {
                pesawat[2].bom[2].moveBomX = pesawat[2].moveX;
                pesawat[2].bom[2].moveBomY = 0;
            }
        }
        if (waktuUmum > 154) {
            pesawat[3].moveX++;
            if (pesawat[3].moveX > 200) {
                pesawat[3].moveX -= 220;
            }
            if (waktuBom < 10) {
                pesawat[3].bom[0].moveBomX = pesawat[3].moveX;
                pesawat[3].bom[0].moveBomY = 0;
            }
            if (waktuBom < 30) {
                pesawat[3].bom[1].moveBomX = pesawat[3].moveX;
                pesawat[3].bom[1].moveBomY = 0;
            }
            if (waktuBom < 50) {
                pesawat[3].bom[2].moveBomX = pesawat[3].moveX;
                pesawat[3].bom[2].moveBomY = 0;
            }
            if (waktuBom < 60) {
                pesawat[3].bom[3].moveBomX = pesawat[3].moveX;
                pesawat[3].bom[3].moveBomY = 0;
            }
        }
    }
    glutPostRedisplay();
    glutTimerFunc(10, generalMovement, 1);
}

void timerBom(int a) {
    if (mouseColision){
        waktuBom++;
    }
    if (waktuBom == 150) {
        waktuBom = 0;
    }
    glutPostRedisplay();
    glutTimerFunc(10, timerBom, 1);
}

void displayMe(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    scaneTiga();
    scaneSatu();
    if(mouseColision){
        scaneDua();
        if(nyawa == 0){
            mouseColision = false;
            scane3 = true;
        }
    }
    if(scane3){
        scaneTiga();
    }
    glutSwapBuffers();
}



int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(1368, 728);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Sepuluh November");
    glutDisplayFunc(displayMe);
    glutSpecialFunc(keyboardListener);
    glutMouseFunc(mouseListenner);
    glutTimerFunc(10,generalMovement,1);
    glutTimerFunc(10,bomGravitation,1);
    glutTimerFunc(1000,generalTimer,1);
    glutTimerFunc(10,timerBom,1);
    gluOrtho2D(0, 171, 0, 91);
    glutMainLoop();
    return 0;
}