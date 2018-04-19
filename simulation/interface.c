#include <stdio.h>
#include <stdint.h>

// file pipe for the process
FILE * process;

// prototype for move_cursor function
void move_cursor(double x, double y);

int main () {
	
	// open the simulation window
	process = popen("./turtle_test.py", "w");

	
	// feed the function commands to move the simulated cursor
	double i;
	for (i = -2.0; i < 2.0; i+=0.05) {
		move_cursor(i, i);

		usleep(5000);
	}
	fclose(process);
	
	
}


void move_cursor(double x, double y) {

	fprintf(process, "%f,%f\n", x, y);

}
