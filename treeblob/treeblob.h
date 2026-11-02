#ifndef TREEBLOB_H
#define TREEBLOB_H
#include "jajagit.h"
int tree_parse(buf_t *in, index_t *out);
int tree_build(index_t *idx, buf_t *out);
#endif
