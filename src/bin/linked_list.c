#include <malloc.h>
#include <stdio.h>
#include <windows.h>

struct book {
    char *name;
    int price;
    int page_count;
    char *language;
    double weight;
    int release_year;

    struct book *next;
};

struct book *create_book(struct book *prev, char *name, int price, int page_count, char *language,
                         double weight, int release_year) {
    struct book *b = malloc(sizeof(struct book));
    b->name = name;
    b->price = price;
    b->page_count = page_count;
    b->language = language;
    b->weight = weight;
    b->release_year = release_year;
    b->next = NULL;

    if (prev != NULL)
        prev->next = b;

    return b;
}

int main() {
    SetConsoleOutputCP(65001);

    struct book *head;
    struct book *cur;

    cur = create_book(NULL, "Гаррі Поттер і філософський камінь", 320, 319, "українська", 0.34, 1997);
    head = cur;

    cur = create_book(cur, "Гаррі Поттер і таємна кімната", 320, 351, "українська", 0.38, 1998);
    cur = create_book(cur, "Гаррі Поттер і в'язень Азкабану", 320, 383, "українська", 0.4, 1999);
    cur = create_book(cur, "Гаррі Поттер і Келих вогню", 350, 670, "українська", 0.63, 2000);
    cur = create_book(cur, "Гаррі Поттер і Орден Фенікса", 400, 815, "українська", 0.75, 2003);
    cur = create_book(cur, "Гаррі Поттер і Напівкровний Принц", 350, 576, "українська", 0.55, 2005);
    create_book(cur, "Гаррі Поттер і Смертельні реліквії", 350, 640, "українська", 0.68, 2007);

    cur = head;
    for (int i = 0; cur != NULL; i++) {
        printf("%d: %s %d₴, %d сторінок, мова: %s, %.3fkg, видано в %d\n", i, cur->name, cur->price, cur->page_count,
               cur->language, cur->weight, cur->release_year);

        cur = cur->next;
    }
}
