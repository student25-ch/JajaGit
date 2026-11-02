#ifndef REFS_H
#define REFS_H
#include "jajagit.h"
int ref_get(const char *repo, const char *name, sha1_t out);
int ref_set(const char *repo, const char *name, sha1_t h);
#endif
