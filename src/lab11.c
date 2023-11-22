#include <stdio.h>
#include "utils.h"

int solve1(double x) {
	double y = -6 * x * 2 + 8;
	printf("y=%f\n", y);
	return 0;
}

int solve2(double x) {
	double y = -1 * x * 3 / 7 + 10;
	printf("y=%f\n", y);
	return 0;
}

int lab11_1() {
	double x;
	try(prompt("x=", "%lf", &x) == 1, "Number expected");

	if (x >= 0 && x < 7)
		solve1(x);
	else if (x > -10 && x < 11)
		printf("no solution\n");
	else
		solve2(x);

	return 0;
}

int lab11_2() {
	double x;
	try(prompt("x=", "%lf", &x) == 1, "Number expected");

	if (x >= 0) {
		if (x < 7)
			solve1(x);
		else if (x >= 11)
			solve2(x);
		else
			printf("no solution\n");
	} else if (x <= -10)
		solve2(x);
	else
		printf("no solution\n");

	return 0;
}
