#ifndef ARC4RANDOM_H_INCLUDED
#define ARC4RANDOM_H_INCLUDED

#include <cstddef>
#include <cstring>
#include <ctime>

inline
void arc4random_buf(void *buf, size_t nbytes)
{
    for( size_t n = 0; n < nbytes; ++ n)
        ((char*)(buf))[n] = rand() %256;
}

inline
void arc4random_init(void)
{
    srand( (unsigned int) time(NULL));
}

inline
void    explicit_bzero(void *b, size_t len)
{
    volatile void * dont_optimize = memset( b, 0, len );
    dont_optimize = dont_optimize;
}



#endif // ARC4RANDOM_H_INCLUDED
