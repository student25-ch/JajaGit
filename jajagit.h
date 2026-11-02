#ifndef JAJAGIT_H
#define JAJAGIT_H

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

#define JAJAGIT_VER_MAJOR 0
#define JAJAGIT_VER_MINOR 1
#define JAJAGIT_DIR ".jajagit"
#define SHA1_LEN 20
#define SHA1_HEX_LEN 40
#define PATH_MAX_BUF 512

typedef uint8_t sha1_t[SHA1_LEN];

typedef enum {
    E_OK = 0,
    E_IO,
    E_NOT_REPO,
    E_BAD_SHA1,
    E_PACK,
    E_DELTA,
    E_NET,
    E_TLS,
    E_PROTO,
    E_NOMEM
} j_err_t;

typedef struct {
    uint8_t *data;
    size_t len;
    size_t cap;
} buf_t;

typedef enum { OBJ_COMMIT, OBJ_TREE, OBJ_BLOB } objtype_t;
typedef struct {
    objtype_t type;
    buf_t payload;
} obj_t;

typedef struct index_entry {
    char path[256];
    sha1_t hash;
    struct index_entry *next;
} index_entry_t;

typedef struct {
    index_entry_t *head;
    size_t count;
} index_t;

typedef struct pack_s pack_t;
typedef struct sock_stream sock_stream_t;
typedef struct tls_stream tls_stream_t;
typedef struct remote remote_t;

#include "error/error.h"
#include "util/util.h"
#include "fsutil/fsutil.h"
#include "obj/obj.h"
#include "sha1/sha1.h"
#include "zlib_wrap/zlib_wrap.h"
#include "treeblob/treeblob.h"
#include "index/index.h"
#include "refs/refs.h"
#include "pack/pack.h"
#include "socket/socket.h"
#include "tls/tls.h"
#include "httpgit/httpgit.h"

int cmd_init(int argc, char **argv);
int cmd_add(int argc, char **argv);
int cmd_commit(int argc, char **argv);
int cmd_log(int argc, char **argv);
int cmd_ls(int argc, char **argv);
int cmd_checkout(int argc, char **argv);
int cmd_clone(int argc, char **argv);
int cmd_pull(int argc, char **argv);
int cmd_help(int argc, char **argv);

#endif
