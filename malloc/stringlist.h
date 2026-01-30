#ifndef  stringlist_h
#define stringlist_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef size_t ulong;
struct stringlist {
    char* buffer;
    ulong size;
    ulong count;
};
typedef void (* stringlist_print_callback)(const char* str, ulong cindx, struct stringlist* list);
void stringlist_init(struct stringlist* list);
void stringlist_append(struct stringlist* list, const char* str);
void stringlist_free(struct stringlist* list);
void stringlist_print(struct stringlist* list, stringlist_print_callback func);

#endif