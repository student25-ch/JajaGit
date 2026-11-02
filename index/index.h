#ifndef INDEX_H
#define INDEX_H
#include "jajagit.h"
void index_init(index_t *idx);
void index_free(index_t *idx);
int index_add(index_t *idx, const char *path, sha1_t h);
int index_load(const char *repo, index_t *idx);
int index_save(const char *repo, index_t *idx);
#endif
