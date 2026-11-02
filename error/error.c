#include "error.h"
static const char *errtable[] = {
    "ok",
    "io error",
    "not a jajagit repository",
    "invalid sha1",
    "packfile parse error",
    "delta apply error",
    "network error",
    "tls error",
    "git protocol error",
    "out of memory"
};
const char *j_errstr(j_err_t e)
{
    if(e < 0 || e >= sizeof(errtable)/sizeof(errtable[0])) return "unknown error";
    return errtable[e];
}
