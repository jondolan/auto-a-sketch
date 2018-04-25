#include <stdio.h>
#include <string>
#include <string.h>
#include <cstdlib>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <fstream>
#include <cstdint>
#include <unistd.h>

#define STP_X (10)
#define DIR_X (9)
#define EN_X  (11)
#define STP_Y (17)
#define DIR_Y (27)
#define EN_Y  (22)

#define pi  (3.14159)

void parse_file(char *, int to_draw, int to_simulate);

void move_cursor(double, double);
double angleG(double, double, double, double);
void G_CODE_00(double, double);
void G_CODE_02(double, double, double, double);
void G_CODE_03(double, double, double, double);

void step(int motor, int enable, int num);
void gotoXY(int new_x, int new_y);