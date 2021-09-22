/* Written by Wolfgangdayo (2021-09-21) for 200-Level, Circuits
 * This program generates problems to solve with Cramers Rule
 */

// For documentation purposes, the following are the design of systems
/*   Two Equations
* 
*   < a  b > < x1 >   < c >			|| a = 0, b = 1, c = 2
*   < d  e > < x2 > = < f >			|| d = 3, e = 4, f = 5
*/
/*   Three Equations
* 
*   < a  b  c > < x1 >   < d >		|| a = 0, b = 1, c = 2,  d = 3
*   < e  f  g > < x2 > = < h >		|| e = 4, f = 5, g = 6,  h = 7
*   < i  j  k > < x3 >   < l >		|| i = 8, j = 9, k = 10, l = 11
*/
// The index numbers, on the right, are for their spot in a single array.

#include <stdio.h>
#include <stdlib.h>

void clear_screen(void);

int main(void)
{
	// Declare variables
	time_t seedtime;
	int THREEEQUATIONS = 0;
	
	int i = 0;
	int a[12];
	
	char readytosolve = 'n';

	int delta = 0, delta1 = 0, delta2 = 0, delta3 = 0;
	int temp1 = 0, temp2 = 0;
	float x1 = 0, x2 = 0, x3 = 0;

	char quit_prompt = 'c';

	// Initialize random number generator
	srand((unsigned)time(&seedtime));

	// =================== START =================== 
	// =================== LOOP  ===================
	do
	{
		// Clear screen
		clear_screen();

		// Randomly select two or three equations for system
		THREEEQUATIONS = rand() % 2;
		//THREEEQUATIONS = 0;  // Debug feature

		// Display number of equations in system
		if (THREEEQUATIONS) {
			printf("\n\nThis example will use three equations in a system.\n\n");

			// Fill array with random
			for (i = 0; i < 12; i++) {
				//printf("%i: ", i); // Debug feature

				a[i] = (rand() % 31) - 15;
				//printf("%i\n", a[i]);  // Debug feature
			}

			printf("< %3i  %3i  %3i > < x1 >   < %3i >\n", a[0], a[1], a[2], a[3]);
			printf("< %3i  %3i  %3i > < x2 > = < %3i >\n", a[4], a[5], a[6], a[7]);
			printf("< %3i  %3i  %3i > < x3 >   < %3i >\n", a[8], a[9], a[10], a[11]);
		}
		else {
			printf("This example will use two equations in a system.\n\n");

			// Fill array with random
			for (i = 0; i < 6; i++) {
				//printf("%i: ", i); // Debug feature

				a[i] = (rand() % 31) - 15;
				//printf("%i\n", a[i]); // Debug feature
			}

			printf("< %3i  %3i > < x1 >   < %3i >\n", a[0], a[1], a[2]);
			printf("< %3i  %3i > < x2 > = < %3i >\n", a[3], a[4], a[5]);
		}

		printf("\nWhen ready to reveal solutions, type one character and then hit enter.\n");
		scanf_s(" %c", &readytosolve);
		//scanf_s("%[^\n]");

		if (THREEEQUATIONS) {
			// This computes delta without modification. Use this as template for delta 1, 2, 3
			temp1 = (a[0] * a[5] * a[10]) + (a[1] * a[6] * a[8]) + (a[2] * a[4] * a[9]);
			temp2 = (a[0] * a[6] * a[9]) + (a[1] * a[4] * a[10]) + (a[2] * a[5] * a[8]);
			delta = temp1 - temp2;

			// This computes delta 1. a0 goes to d3, e4 goes to h7, i8 goes to l11
			temp1 = (a[3] * a[5] * a[10]) + (a[1] * a[6] * a[11]) + (a[2] * a[7] * a[9]);
			temp2 = (a[3] * a[6] * a[9]) + (a[1] * a[7] * a[10]) + (a[2] * a[5] * a[11]);
			delta1 = temp1 - temp2;

			// This computes delta 2. b1 goes to d3, f5 goes to h7, j9 goes to l11
			temp1 = (a[0] * a[7] * a[10]) + (a[3] * a[6] * a[8]) + (a[2] * a[4] * a[11]);
			temp2 = (a[0] * a[6] * a[11]) + (a[3] * a[4] * a[10]) + (a[2] * a[7] * a[8]);
			delta2 = temp1 - temp2;

			// This computes delta 1. c2 goes to d3, g6 goes to h7, k10 goes to l11
			temp1 = (a[0] * a[5] * a[11]) + (a[1] * a[7] * a[8]) + (a[3] * a[4] * a[9]);
			temp2 = (a[0] * a[7] * a[9]) + (a[1] * a[4] * a[11]) + (a[3] * a[5] * a[8]);
			delta3 = temp1 - temp2;

			printf("\n\ndelta %i || delta1 %i ; delta2 %i ; delta3 %i \n", delta, delta1, delta2, delta3);

			x1 = (float)delta1 / delta;
			x2 = (float)delta2 / delta;
			x3 = (float)delta3 / delta;

			printf("\nx1 is %f ; x2 is %f ; x3 is %f \n", x1, x2, x3);
		}
		else {
			// This computes delta without modification. Use this as template for delta 1, 2, 3
			temp1 = a[0] * a[4];
			temp2 = a[1] * a[3];
			delta = temp1 - temp2;

			// This computes delta 1. a0 goes to c2, d3 goes to f5
			temp1 = a[2] * a[4];
			temp2 = a[1] * a[5];
			delta1 = temp1 - temp2;

			// This computes delta 2. b1 goes to c2, e4 goes to f5
			temp1 = a[0] * a[5];
			temp2 = a[2] * a[3];
			delta2 = temp1 - temp2;

			printf("\n\ndelta %i || delta1 %i ; delta2 %i \n", delta, delta1, delta2);

			x1 = (float)delta1 / delta;
			x2 = (float)delta2 / delta;

			printf("\nx1 is %f ; x2 is %f \n", x1, x2);
		}

		printf("\nEnter 'c' to continue: \n");
		scanf_s(" %c", &quit_prompt);

		if (quit_prompt == 'c')
			printf("\nContinue!\n\n");
		else
			printf("\nQuit!\n\n");

	}
	while (quit_prompt == 'c');

	// =================== END  ==================== 
	// =================== LOOP ====================

	// Exit program
	return 0;
}

void clear_screen(void) {
	int j = 0;

	for (j = 0; j < 50; j++) {
		printf("\n");
	}
}
