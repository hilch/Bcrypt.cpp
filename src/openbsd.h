#ifndef ARC4RANDOM_H_INCLUDED
#define ARC4RANDOM_H_INCLUDED

#include <cstdlib>     /* srand, rand */
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


#endif // ARC4RANDOM_H_INCLUDED
