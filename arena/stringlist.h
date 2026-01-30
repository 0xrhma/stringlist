#ifndef  stringlist_h
#define stringlist_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef size_t ulong;
struct stringlist {
    char* buffer;
    ulong size;
    ulong count;
    ulong cpos;
};
typedef void (* stringlist_print_callback)(const char* str, ulong cindx, struct stringlist* list);
void stringlist_init(struct stringlist* list);
void stringlist_init_wsize(struct stringlist *list, ulong size);
void stringlist_append(struct stringlist* list, const char* str);
void stringlist_append_unsafe(struct stringlist* list, const char* str);
void stringlist_free(struct stringlist* list);
void stringlist_print(struct stringlist* list, stringlist_print_callback func);
void stringlist_compact(struct stringlist*list);
#endif