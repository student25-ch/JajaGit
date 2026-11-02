#ifndef TLS_H
#define TLS_H
#include "jajagit.h"
#include <openssl/ssl.h>
typedef struct tls_stream { SSL *ssl; int fd; } tls_stream_t;
int tls_connect(tls_stream_t *t, const char *host);
void tls_close(tls_stream_t *t);
int tls_read(tls_stream_t *t, uint8_t *buf, size_t sz);
int tls_write(tls_stream_t *t, const uint8_t *buf, size_t sz);
#endif
