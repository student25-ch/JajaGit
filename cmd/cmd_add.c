#include "jajagit.h"
int cmd_add(int argc, char **argv)
{
    if(argc < 2) { fprintf(stderr, "usage: add <file>\n"); return 1; }
    printf("add: %s\n", argv[1]);
    return 0;
}
