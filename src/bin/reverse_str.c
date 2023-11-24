#include <malloc.h>
#include <string.h>
#include <stdio.h>

char *reverse(char *str) {
    unsigned long len = strlen(str);
    char *reversed = malloc(len + 1);
    reversed[len] = 0;

    for (int i = 0; i < len; i++) {
        reversed[len - i - 1] = str[i];
    }

    return reversed;
}

int main() {
    char *str = "Hello world";
    char *reversed = reverse(str);

    printf("%s\n", str);
    printf("%s\n", reversed);
}
