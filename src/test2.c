#include <stdio.h>
#define N 4

double pow(double d, int pow) {
	if (pow == 0)
		return 1;

	double res = d;
	for (int i = 1; i < pow; i++) {
		res *= d;
	}
	return res;
}

long fact(long num) {
	if (num == 0) return 1;

	long res = 1;
	for (long i = 1; i <= num; i++) {
		res *= i;
	}
	return res;
}

int test2() {
	double X = 3;
	double arr[N];

	printf("%d\n", ~3 && 6);

	double sum = 0;
	for (int i = 0; i < N; i++) {
		sum += pow(X, 2 * i) / fact(2 * i) * pow(-1, i);
		arr[i] = sum;
		printf("arr[%d]=%lf\n", i, sum);
	}

	return 0;
}
