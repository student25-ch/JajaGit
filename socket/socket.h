#ifndef SOCKET_H
#define SOCKET_H
#include "jajagit.h"
typedef struct sock_stream { int fd; } sock_stream_t;
int sock_connect(sock_stream_t *s, const char *host, int port);
void sock_close(sock_stream_t *s);
int sock_read(sock_stream_t *s, uint8_t *buf, size_t sz);
int sock_write(sock_stream_t *s, const uint8_t *buf, size_t sz);
#endif
