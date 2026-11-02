#include "fsutil.h"
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int fs_mkdir_recursive(const char *path)
{
    char tmp[PATH_MAX_BUF];
    char *p;
    strncpy(tmp, path, PATH_MAX_BUF-1);
    tmp[PATH_MAX_BUF-1] = 0;
    for(p = tmp + 1; *p; p++)
    {
        if(*p == '/')
        {
            *p = 0;
            mkdir(tmp, 0755);
            *p = '/';
        }
    }
    mkdir(tmp, 0755);
    return E_OK;
}

int fs_write_file(const char *path, const uint8_t *data, size_t len)
{
    FILE *f = fopen(path, "wb");
    if(!f) return E_IO;
    fwrite(data, 1, len, f);
    fclose(f);
    return E_OK;
}

int fs_read_file(const char *path, buf_t *out)
{
    FILE *f = fopen(path, "rb");
    if(!f) return E_IO;
    fseek(f,0,SEEK_END);
    long sz = ftell(f);
    fseek(f,0,SEEK_SET);
    buf_append(out, NULL, sz);
    fread(out->data, 1, sz, f);
    out->len = sz;
    fclose(f);
    return E_OK;
}

int fs_exists(const char *path)
{
    struct stat st;
    return stat(path, &st) == 0;
}

int fs_isdir(const char *path)
{
    struct stat st;
    if(stat(path, &st) !=0) return 0;
    return S_ISDIR(st.st_mode);
}
