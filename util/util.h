#ifndef UTIL_H
#define UTIL_H
#include "jajagit.h"
buf_t *buf_new(void);
void buf_free(buf_t *b);
int buf_append(buf_t *b, const void *p, size_t sz);
void sha1_to_hex(const sha1_t s, char *out);
int hex_to_sha1(const char *hex, sha1_t s);
char *path_join(const char *a, const char *b);
#endif
