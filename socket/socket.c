#include "socket.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
int sock_connect(sock_stream_t *s, const char *host, int port)
{
    return E_OK;
}
void sock_close(sock_stream_t *s) { close(s->fd); }
int sock_read(sock_stream_t *s, uint8_t *buf, size_t sz) { return recv(s->fd, buf, sz, 0); }
int sock_write(sock_stream_t *s, const uint8_t *buf, size_t sz) { return send(s->fd, buf, sz, 0); }
