#include "index.h"
void index_init(index_t *idx)
{
    idx->head = NULL; idx->count = 0;
}
void index_free(index_t *idx)
{
    index_entry_t *p = idx->head, *n;
    while(p) { n=p->next; free(p); p=n; }
    idx->head = NULL; idx->count=0;
}
int index_add(index_t *idx, const char *path, sha1_t h)
{
    index_entry_t *e = malloc(sizeof(index_entry_t));
    strncpy(e->path, path, 255);
    memcpy(e->hash, h, SHA1_LEN);
    e->next = idx->head;
    idx->head = e; idx->count++;
    return E_OK;
}
int index_load(const char *repo, index_t *idx)
{
    return E_OK;
}
int index_save(const char *repo, index_t *idx)
{
    return E_OK;
}
