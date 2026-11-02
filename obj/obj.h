#ifndef OBJ_H
#define OBJ_H
#include "jajagit.h"
obj_t *obj_new(objtype_t t);
void obj_free(obj_t *o);
int obj_write(const char *repo, obj_t *o, sha1_t hash);
int obj_read(const char *repo, const sha1_t hash, obj_t *o);
int obj_parse_header(const uint8_t *data, size_t len, objtype_t *ty, size_t *bodyoff);
#endif
