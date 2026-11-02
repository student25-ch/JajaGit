#include "jajagit.h"
int cmd_init(int argc, char **argv)
{
    fs_mkdir_recursive(JAJAGIT_DIR);
    printf("Initialized empty JajaGit repository\n");
    return 0;
}
