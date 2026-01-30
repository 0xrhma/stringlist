#include "stringlist.h"

void disp_str(const char* str, ulong cindx, struct stringlist* list) {
    if (list->count == 0)
        fprintf(stderr, "[]\n");
    else if (list->count == 1)
        fprintf(stderr, "[%s]\n", str);
    else if (cindx == 0)
        fprintf(stderr, "[%s, ", str);
    else if (cindx == (list->count -1))
        fprintf(stderr, "%s]\n", str);
    else
        fprintf(stderr, "%s, ", str);
}

int main(int argc, char* const argv[]) {
    struct stringlist mylist;
    stringlist_init(&mylist);
    for (int i = 1; i < argc; i++) {
        stringlist_append(&mylist, argv[i]);
    }
    stringlist_print(&mylist, disp_str);
    stringlist_free(&mylist);
    return 0;
}