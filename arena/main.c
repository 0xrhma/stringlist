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

int main(int argc, char* const argv[]){
    struct stringlist mlist;
    stringlist_init_wsize(&mlist, 0);
    for (int i = 1; i < argc; i++) {
        stringlist_append(&mlist, argv[i]);
    }
    stringlist_compact(&mlist);
    printf("%ld\n", mlist.size);
    stringlist_print(&mlist, disp_str);
    stringlist_free(&mlist);
    return 0;
}