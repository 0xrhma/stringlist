#include "stringlist.h"

void stringlist_init(struct stringlist* list) {
    list->size = 0L;
    list->count = 0L;
    list->buffer = NULL;
}

void stringlist_append(struct stringlist* list, const char* str) {
    ulong csize  = strlen(str) + 1;
    list->buffer = realloc(list->buffer, list->size+csize);
    void* dest = list->buffer + list->size;
    strcpy(dest, str);
    list->size += csize;
    list->buffer[list->size-1] = '\0';
    list->count++;
}

void stringlist_free(struct stringlist* list) {
    free(list->buffer);
}

void stringlist_print(struct stringlist* list, stringlist_print_callback func) {
    ulong offset = 0L;
    for (ulong i = 0; i < list->count; i++) {
        const char *str =(const char*) (list->buffer + offset);
        func(str, i, list);
        ulong len = strlen(str)+1;
        offset += len;
    }
    if (list->count == 0)
        func("", 0, list);
}