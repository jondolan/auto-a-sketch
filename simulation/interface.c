#include <stdio.h>
#include <stdint.h>

// file pipe for the process
FILE * process;

// prototype for move_cursor function
void move_cursor(uint16_t x, uint16_t y);

int main () {
	
	// open the simulation window
	process = popen("./turtle_test.py", "w");

	
	// feed the function commands to move the simulated cursor
	int i;
	for (i = 0; i < 640; i++) {
		move_cursor(i, i);
		usleep(5000);
	}
	fclose(process);
	
	
}


void move_cursor(uint16_t x, uint16_t y) {

	fprintf(process, "%d,%d\n", x, y);

}
