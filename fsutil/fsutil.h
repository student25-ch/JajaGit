#ifndef FSUTIL_H
#define FSUTIL_H
#include "jajagit.h"
int fs_mkdir_recursive(const char *path);
int fs_write_file(const char *path, const uint8_t *data, size_t len);
int fs_read_file(const char *path, buf_t *out);
int fs_exists(const char *path);
int fs_isdir(const char *path);
#endif
