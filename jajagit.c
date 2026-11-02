#include "jajagit.h"

int main(int argc, char **argv)
{
    if(argc < 2)
    {
        cmd_help(0, NULL);
        return 1;
    }
    char *cmd = argv[1];
    if(strcmp(cmd, "init") == 0) return cmd_init(argc-1, argv+1);
    if(strcmp(cmd, "add") == 0) return cmd_add(argc-1, argv+1);
    if(strcmp(cmd, "commit") == 0) return cmd_commit(argc-1, argv+1);
    if(strcmp(cmd, "log") == 0) return cmd_log(argc-1, argv+1);
    if(strcmp(cmd, "ls") == 0) return cmd_ls(argc-1, argv+1);
    if(strcmp(cmd, "checkout") == 0) return cmd_checkout(argc-1, argv+1);
    if(strcmp(cmd, "clone") == 0) return cmd_clone(argc-1, argv+1);
    if(strcmp(cmd, "pull") == 0) return cmd_pull(argc-1, argv+1);
    if(strcmp(cmd, "help") == 0) return cmd_help(argc-1, argv+1);
    fprintf(stderr, "jajagit: unknown command: %s\n", cmd);
    cmd_help(0,NULL);
    return 1;
}
