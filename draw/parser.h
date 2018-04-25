#include <stdio.h>
#include <string>
#include <string.h>
#include <cstdlib>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <fstream>
#include <cstdint>

#define pi  (3.14159)

void parse_file(char *, int to_draw, int to_simulate);

void move_cursor(double, double);
double angleG(double, double, double, double);
void G_CODE_00(double, double);
void G_CODE_02(double, double, double, double);
void G_CODE_03(double, double, double, double);