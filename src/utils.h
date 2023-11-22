#define try(expr, err)      \
if (!(expr)) {              \
    printf("%s\n", err);    \
    return 1;               \
}

int prompt(const char *prefix, const char *format, ...);
