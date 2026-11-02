#ifndef PACK_H
#define PACK_H
#include "jajagit.h"
int pack_parse(const uint8_t *data, size_t len, pack_t *p);
int pack_apply_delta(buf_t *base, buf_t *delta, buf_t *out);
#endif
