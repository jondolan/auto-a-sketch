// example call ./a.out file.txt
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
#include <pigpio.h>
using namespace std;

FILE * process;

double XLOC = 0;
double YLOC = 0;
double pi = 3.14159;
double scale = 0;
double xshift = 0;
double yshift = 0;
int count = 0;
fstream outfilex;
fstream outfiley;

#define STP_X (10)
#define DIR_X (9)
#define EN_X  (11)
#define STP_Y (17)
#define DIR_Y (27)
#define EN_Y  (22)
int x = 0, y = 0;



void move_cursor(double, double);
double angleG(double, double, double, double);
void G_CODE_00(double, double);
void G_CODE_02(double, double, double, double);
void G_CODE_03(double, double, double, double);

int main (int argc, char* argv[])
{

   if (gpioInitialise() < 0)
   {
      fprintf(stderr, "pigpio initialisation failed\n");
      return 1;
   }


   gpioSetMode(STP_X, PI_OUTPUT);
   gpioSetMode(DIR_X, PI_OUTPUT);
   gpioSetMode(EN_X, PI_OUTPUT);
   gpioSetMode(DIR_Y, PI_OUTPUT);
   gpioSetMode(STP_Y, PI_OUTPUT);
   gpioSetMode(EN_X, PI_OUTPUT);

  char * pch;
  char * value;
  double G, X, Y, I, J;
  int i = 0;
  double xmax = -9999;
  double ymax = -9999;
  double xmin = 9999;
  double ymin = 9999;
  double number;
  char line[256];
  int len;
  /*outfilex.open("outx2.txt", fstream::out);
  outfiley.open("outy2.txt", fstream::out);*/

  process = popen("./turtle_draw.py", "w");

  ifstream file(argv[1]);
  if(!file){
    printf("invalid file name");
    return 1;
  }
  
  
  while(file.getline(line, 255)){
    pch = strtok (line," ,.-");
    G = -1;
    X = -1.73987425;
    Y = -1.73987425;
    I = 0;
    J = 0;
    while (pch != NULL)
    { 
      len = strlen(pch);
      if(pch[0] == 88){//X = 88
        value = pch + 1;
        number = atof(value);
        if(number>xmax)
          xmax = number;
        else if(number<xmin)
          xmin = number;
      }
      else if(pch[0] == 89){//Y = 89
        value = pch + 1;
        number = atof(value);
        if(number>ymax)
          ymax = number;
        else if(number<ymin)
          ymin = number;
      }
      i++;
      pch = strtok (NULL, " ");
    }
    i = 0;
  }

  file.close();

  scale = 1500/(xmax-xmin);
  if(1000/(ymax-ymin)<scale)
    scale = 1000/(ymax-ymin);
  xshift = 0-xmin;
  yshift = 0-ymin;


  ifstream in(argv[1]);
  if(!in){
    printf("invalid file name");
    return 1;
  }
  while(in.getline(line, 255)){
    pch = strtok (line," ,.-");
    G = -1;
    X = -1.73987425;
    Y = -1.73987425;
    I = 0;
    J = 0;
    while (pch != NULL)
    { 
      len = strlen(pch);
      if(pch[0] == 71){//G = 71
        value = pch + 1;
        G = atof(value);
      }
      else if(pch[0] == 88){//X = 88
        value = pch + 1;
        X = atof(value);
      }
      else if(pch[0] == 89){//Y = 89
        value = pch + 1;
        Y = atof(value);
      }
      else if(pch[0] == 73){//I = 73
        value = pch + 1;
        I = atof(value);
      }
      else if(pch[0] == 74){//J = 74
        value = pch + 1;
        J = atof(value);
      }
      i++;
      pch = strtok (NULL, " ");
    }
    i = 0;
    if((G == 0 or G == 1)){
      if(X != -1.73987425 and Y != -1.73987425)
        G_CODE_00(X,Y);
    }
    else if(G == 2){
      if(X != -1.73987425 and Y != -1.73987425)
        G_CODE_02(X,Y,I,J);
      //cout<<"waiting2"<<"\n";
    }
    else if(G == 3){
      if(X != -1.73987425 and Y != -1.73987425)
        G_CODE_03(X,Y,I,J);
      //cout<<"waiting3"<<"\n";
    }
  }
  in.close();
  /*outfilex.close();
  outfiley.close();*/


  cout<<"xmin: " << xmin << "\n";
  cout<<"xmax: " << xmax << "\n";
  cout<<"ymin: " << ymin << "\n";
  cout<<"ymax: " << ymax << "\n";

gpioTerminate();

  return 0;


}

/*void move_cursor(double x,double y){
  x = (x+xshift)*scale-500;
  y = (y+yshift)*scale-500;
  if (count % 50 == 49) {
		fprintf(process, "%f,%f\n", x, y);
		count = 0;
	} else count++;
}*/

void step(int motor, int enable, int num)
{
  gpioWrite(enable, 0);
  usleep(1000);
  whi