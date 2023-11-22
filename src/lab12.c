#include <stdio.h>
#include "math.h"
#include "utils.h"

int lab12_1() {
	long n;
	try(prompt("n=", "%u", &n) == 1, "number expected");
	try(n >= 1, "n must be greater than 0");

	long ops = 0;

	double product = 1;
	for (long i = 1; i <= n; i++, ops++) {
		double sum = 0;
		for (long j = 1; j <= i; j++, ops++) {
			sum += j - cos(j);
			ops += 3;
		}
		product *= sum / (i + sin(i));
		ops += 4;
	}
	printf("P=%.7lf\n", product);
	printf("ops=%ld", ops);

	return 0;
}

int lab12_2() {
	long n;
	try(prompt("n=", "%u", &n) == 1, "number expected");
	try(n >= 1, "n must be greater than 0");

	long ops = 0;

	double product = 1;
	double sum = 0;
	for (long i = 1; i <= n; i++, ops++) {
		sum += i - cos(i);
		product *= sum / (i + sin(i));
		ops += 7;
	}
	printf("P=%.7lf\n", product);
	printf("ops=%ld", ops);

	return 0;
}
