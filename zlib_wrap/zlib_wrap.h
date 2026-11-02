#ifndef ZLIB_WRAP_H
#define ZLIB_WRAP_H
#include "jajagit.h"
int zlib_decompress(const uint8_t *in, size_t inlen, buf_t *out);
int zlib_compress(const uint8_t *in, size_t inlen, buf_t *out);
#endif
