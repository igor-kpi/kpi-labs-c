#include <math.h>
#include <stdio.h>

#define N 4

int test1() {
	double X[N];
	double Y[N];

	X[0] = 0.2; // initial X
	Y[0] = 1;
	for (int i = 0; i < N - 1; i++) {
		double sum = 0;
		for (int k = 0; k <= N - 2; k++) {
			sum += pow(1 - X[i], k);
		}
		printf("sum=%lf Y=%lf prod=%lf \n", sum, Y[i], sum * Y[i]);
		Y[i + 1] = Y[i] * sum;
		X[i + 1] = X[i] * sum;
	}

	for (int i = 0; i < N; i++) {
		printf("Y[%d]=%lf\n", i, Y[i]);
		printf("X[%d]=%lf\n", i, X[i]);
	}

	return 0;
}
