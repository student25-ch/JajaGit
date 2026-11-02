#include "zlib_wrap.h"
#include <zlib.h>
int zlib_decompress(const uint8_t *in, size_t inlen, buf_t *out)
{
    z_stream zs = {0};
    inflateInit(&zs);
    zs.next_in = (uint8_t*)in;
    zs.avail_in = inlen;
    uint8_t tmp[4096];
    int r;
    do{
        zs.next_out = tmp;
        zs.avail_out = sizeof(tmp);
        r = inflate(&zs, Z_NO_FLUSH);
        buf_append(out, tmp, sizeof(tmp)-zs.avail_out);
    }while(r == Z_OK);
    inflateEnd(&zs);
    return (r == Z_STREAM_END) ? E_OK : E_PACK;
}

int zlib_compress(const uint8_t *in, size_t inlen, buf_t *out)
{
    z_stream zs = {0};
    deflateInit(&zs, Z_BEST_SPEED);
    zs.next_in = (uint8_t*)in;
    zs.avail_in = inlen;
    uint8_t tmp[4096];
    int r;
    do{
        zs.next_out = tmp;
        zs.avail_out = sizeof(tmp);
        r = deflate(&zs, Z_FINISH);
        buf_append(out, tmp, sizeof(tmp)-zs.avail_out);
    }while(r == Z_OK);
    deflateEnd(&zs);
    return (r == Z_STREAM_END) ? E_OK : E_PACK;
}
