#include "sha1.h"
#include <openssl/sha.h>
void sha1_hash(const uint8_t *in, size_t len, sha1_t out)
{
    SHA1(in, len, out);
}
