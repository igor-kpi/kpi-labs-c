#include "./utils.h"
#include <stdio.h>
#include <stdarg.h>

int prompt(const char *prefix, const char *format, ...) {
	va_list args;
	va_start(args, format);

	printf("%s", prefix);
	int res = vscanf(format, args);
	va_end(args);

	return res;
}
