#include <stdio.h>
#include <math.h>

#define N 10

int factorial(int num) {
	int product = 1;
	for (int i = 1; i <= num; i++) {
		product *= i;
	}
	return product;
}

int test() {
	double x = 2;
	double arr[N];
	double sum = 0;
	for (int i = 0; i < N; i++) {
		sum += pow(-1, i) * (pow(x, 2 * i + 1) / factorial(2 * i + 1));
		arr[i] = sum;
	}

	printf("sum=%lf\n", sum);
	for (int i = 0; i < N; i++) {
		printf("X[%d]=%lf\n", i, arr[i]);
	}

	return 0;
}
