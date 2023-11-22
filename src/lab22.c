#include <stdio.h>

#define ROWS 10
#define COLS 10

void print_matrix(double matrix[ROWS][COLS]) {
	for (int row = 0; row < ROWS; row++) {
		for (int col = 0; col < COLS; col++) {
			printf("%.2lf ", matrix[row][col]);
		}
		printf("\n");
	}
}

int lab22() {
	// Random
/*
	double matrix[ROWS][COLS] = {
			{6, 5, 7, 4, 5, 3, 1, 9, 2, 2},
			{0, 4, 3, 0, 5, 5, 0, 7, 4, 7},
			{2, 1, 8, 7, 9, 5, 1, 6, 7, 6},
			{9, 7, 7, 4, 4, 7, 7, 3, 4, 1},
			{3, 7, 5, 5, 8, 3, 6, 3, 9, 9},
			{7, 8, 0, 2, 8, 0, 2, 7, 3, 6},
			{9, 0, 4, 3, 5, 7, 8, 4, 3, 9},
			{5, 4, 1, 7, 8, 9, 6, 4, 0, 4},
			{1, 9, 6, 1, 1, 6, 3, 3, 2, 7},
			{7, 4, 2, 1, 3, 2, 9, 7, 4, 2},
	};
*/

	// Sorted
/*
	double matrix[ROWS][COLS] = {
			{9, 9, 8, 7, 9, 9, 9, 9, 9, 9},
			{9, 8, 7, 7, 8, 7, 8, 7, 7, 9},
			{7, 7, 7, 5, 8, 7, 7, 7, 4, 7},
			{7, 7, 6, 4, 8, 6, 6, 7, 4, 7},
			{6, 5, 5, 4, 5, 5, 6, 6, 4, 6},
			{5, 4, 4, 3, 5, 5, 3, 4, 3, 6},
			{3, 4, 3, 2, 5, 3, 2, 4, 3, 4},
			{2, 4, 2, 1, 4, 3, 1, 3, 2, 2},
			{1, 1, 1, 1, 3, 2, 1, 3, 2, 2},
			{0, 0, 0, 0, 1, 0, 0, 3, 0, 1},
	};
*/

	// Reverse Sorted
	double matrix[ROWS][COLS] = {
			{0, 0, 0, 0, 1, 0, 0, 3, 0, 1},
			{1, 1, 1, 1, 3, 2, 1, 3, 2, 2},
			{2, 4, 2, 1, 4, 3, 1, 3, 2, 2},
			{3, 4, 3, 2, 5, 3, 2, 4, 3, 4},
			{5, 4, 4, 3, 5, 5, 3, 4, 3, 6},
			{6, 5, 5, 4, 5, 5, 6, 6, 4, 6},
			{7, 7, 6, 4, 8, 6, 6, 7, 4, 7},
			{7, 7, 7, 5, 8, 7, 7, 7, 4, 7},
			{9, 8, 7, 7, 8, 7, 8, 7, 7, 9},
			{9, 9, 8, 7, 9, 9, 9, 9, 9, 9},
	};

	for (int col = 0; col < COLS; col++) {
		for (int row = 1; row < ROWS; row++) {
			double el = matrix[row][col];
			int row1 = row;
			while (row1 > 0 && matrix[row1 - 1][col] < el) {
				matrix[row1][col] = matrix[row1 - 1][col];
				row1--;
			}
			matrix[row1][col] = el;
		}
	}

	print_matrix(matrix);

	return 0;
}
