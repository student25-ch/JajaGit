#include "obj.h"
obj_t *obj_new(objtype_t t)
{
    obj_t *o = malloc(sizeof(obj_t));
    o->type = t;
    o->payload = *buf_new();
    return o;
}
void obj_free(obj_t *o)
{
    if(o){ buf_free(&o->payload); free(o); }
}
int obj_write(const char *repo, obj_t *o, sha1_t hash)
{
    return E_OK;
}
int obj_read(const char *repo, const sha1_t hash, obj_t *o)
{
    return E_OK;
}
int obj_parse_header(const uint8_t *data, size_t len, objtype_t *ty, size_t *bodyoff)
{
    return E_OK;
}
