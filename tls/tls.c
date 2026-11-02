#include "tls.h"
int tls_connect(tls_stream_t *t, const char *host)
{
    return E_OK;
}
void tls_close(tls_stream_t *t)
{
    SSL_shutdown(t->ssl);
    SSL_free(t->ssl);
    close(t->fd);
}
int tls_read(tls_stream_t *t, uint8_t *buf, size_t sz) { return SSL_read(t->ssl, buf, sz); }
int tls_write(tls_stream_t *t, const uint8_t *buf, size_t sz) { return SSL_write(t->ssl, buf, sz); }
