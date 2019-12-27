#ifndef ARC4RANDOM_H_INCLUDED
#define ARC4RANDOM_H_INCLUDED

#include <cstddef>


void     arc4random_buf(void *buf, size_t nbytes);
void    explicit_bzero(void *b, size_t len);
void arc4random_init(void);

#endif // ARC4RANDOM_H_INCLUDED
