#ifndef _SHA1_H
#define _SHA1_H

#if 0
#define uint8  unsigned char
#define uint32 unsigned long int
#define uint64 unsigned long long int
#else
#include <stdint.h>
#define uint8  uint8_t
#define uint32 uint32_t
#define uint64 uint64_t
#endif

struct sha1_context
{
    uint64 total;
    uint32 state[5];
    uint8 buffer[64];
};

void sha1_starts( struct sha1_context *ctx );
void sha1_update( struct sha1_context *ctx, uint8 *input, uint32 length );
void sha1_finish( struct sha1_context *ctx, uint8 digest[20] );

#endif /* sha1.h */

