#include "parser.h"

int main(int argc, char* argv[]) {

	parse_file(argv[1], 0);

}

void step(int motor, int enable, int num) {
  gpioWrite(enable, 0);
  usleep(1000);
  while(num>0){
    gpioWrite(motor, 1);
    usleep(1000); //time_sleep(0.5);
    gpioWrite(motor, 0);
    usleep(30000);
    num--;
  }
  gpioWrite(enable, 1);
  usleep(1000);
}

void gotoXY(int new_x, int new_y) {
  if(new_x-x>0)
    gpioWrite(DIR_X, 1);
  else
    gpioWrite(DIR_X, 0);

  if(new_y-y>0)
    gpioWrite(DIR_Y, 1);
  else
    gpioWrite(DIR_Y, 0);


  step(STP_X,EN_X,abs(new_x-x));
  step(STP_Y,EN_Y,abs(new_y-y));

  x=new_x;
  y=new_y;

}