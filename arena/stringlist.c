#include "stringlist.h"
#include <assert.h>
#include <stdlib.h>
#include <string.h>

#define _stringlist_isize 512L

void stringlist_init(struct stringlist* list) {
    list->size = _stringlist_isize;
    if(!list->size)
        list->size = 1;
    list->count = 0L;
    list->buffer = malloc(list->size);
    list->cpos = 0L;
    assert(list->buffer);
}

void stringlist_init_wsize(struct stringlist* list, ulong size) {
    list->size = size;
    if(!list->size)
        list->size = 1;
    list->count = 0L;
    list->buffer = malloc(list->size);
    list->cpos = 0L;
    assert(list->buffer);
}

void stringlist_append(struct stringlist* list, const char* str) {
    ulong slen = strlen(str) + 1;
    ulong fpos = list->cpos + slen;
    if (list->size < fpos){
        ulong fac = fpos/list->size;
        if (fac* list->size < fpos)
            fac++;
        list->size *= fac;
        list->buffer = realloc(list->buffer, list->size);
        assert(list->buffer);
    }
    stringlist_append_unsafe(list, str);
}

void stringlist_append_unsafe(struct stringlist* list, const char* str) {
    ulong csize  = strlen(str) + 1;
    void* dest = list->buffer + list->cpos;
    strcpy(dest, str);
    list->cpos += csize;
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


void stringlist_compact(struct stringlist*list) {
    ulong nsize = list->cpos;
    if (!nsize)
        nsize = 1;
    list->buffer = realloc(list->buffer, nsize);
    list->size = nsize;
}
