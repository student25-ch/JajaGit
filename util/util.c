#include "util.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

buf_t *buf_new(void)
{
    buf_t *b = malloc(sizeof(buf_t));
    b->data = NULL;
    b->len = 0;
    b->cap = 0;
    return b;
}

void buf_free(buf_t *b)
{
    if(b)
    {
        free(b->data);
        free(b);
    }
}

int buf_append(buf_t *b, const void *p, size_t sz)
{
    if (!b) return 0;
    if (b->len + sz > b->cap)
    {
        size_t nc = (b->cap < 128) ? 128 : b->cap * 2;
        while(nc < b->len + sz) nc *= 2;
        uint8_t *nd = realloc(b->data, nc);
        if (!nd) return 0;
        b->data = nd;
        b->cap = nc;
    }
    if(p != NULL)
    {
        memcpy(b->data + b->len, p, sz);
    }
    b->len += sz;
    return 1;
}

static const char hex_tab[] = "0123456789abcdef";
void sha1_to_hex(const sha1_t s, char *out)
{
    int i;
    for(i=0;i<20;i++)
    {
        out[i*2] = hex_tab[(s[i] >> 4) & 0x0f];
        out[i*2+1] = hex_tab[s[i] & 0x0f];
    }
    out[40] = '\0';
}

static int hex_val(char c)
{
    if(c >= '0' && c <= '9') return c - '0';
    if(c >= 'a' && c <= 'f') return c - 'a' + 10;
    if(c >= 'A' && c <= 'F') return c - 'A' + 10;
    return -1;
}

int hex_to_sha1(const char *hex, sha1_t s)
{
    int i;
    for(i=0;i<40;i+=2)
    {
        int h1 = hex_val(hex[i]);
        int h2 = hex_val(hex[i+1]);
        if(h1<0 || h2<0) return 0;
        s[i/2] = (h1 <<4) | h2;
    }
    return 1;
}

char *path_join(const char *a, const char *b)
{
    if(!a || !b) return NULL;
    size_t la = strlen(a);
    size_t lb = strlen(b);
    int add_slash = 0;
    if(la > 0 && a[la-1] != '/') add_slash = 1;
    char *res = malloc(la + lb + add_slash + 1);
    strcpy(res,a);
    if(add_slash) strcat(res,"/");
    strcat(res,b);
    return res;
}
