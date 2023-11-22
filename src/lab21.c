#include <stdio.h>

#define SIZE 7

// https://onlinemathtools.com/generate-random-matrix

int lab21() {
	double matrix[SIZE][SIZE] = {
			{0, 3, 0, 7, 9, 1, 0},
			{1, 2, 4, 4, 8, 6, 8},
			{8, 7, 3, 5, 0, 1, 7},
			{2, 9, 5, 3, 5, 0, 9},
			{1, 7, 5, 4, 5, 7, 1},
			{4, 2, 0, 8, 4, 9, 7},
			{4, 3, 8, 0, 5, 7, 9},
	};

/*
	double matrix[SIZE][SIZE] = {
			{6, 3, 0, 7, 9, 1, 0},
			{1, 7, 4, 4, 8, 6, 8},
			{8, 7, 7, 5, 0, 1, 7},
			{2, 9, 5, 8, 5, 0, 9},
			{1, 7, 5, 4, 8, 7, 1},
			{4, 2, 0, 8, 4, 9, 7},
			{4, 3, 8, 0, 5, 7, 9},
	};
*/

	int left = 0, right = SIZE - 1, idx;
	for (; left != right;) {
		idx = (right + left) / 2;
		double el = matrix[idx][idx];
		if (el > 5) {
			right = idx - 1;
		} else if (el < 0) {
			left = idx + 1;
		} else {
			right = idx;
		}
	}
	idx = left;

	double el = matrix[idx][idx];
	if (el < 0 || el > 5) {
		printf("not found\n");
	} else {
		printf("found %.2lf at row %d col %d\n", el, idx + 1, idx + 1);
	}

	return 0;
}
