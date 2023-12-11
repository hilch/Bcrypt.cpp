#ifndef ARC4RANDOM_H_INCLUDED
#define ARC4RANDOM_H_INCLUDED

#include <cstdlib>     /* srand, rand */
#include <cstddef>
#include <cstring>
#include <ctime>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

inline
void arc4random_buf(void *buf, size_t nbytes)
{
    for( size_t n = 0; n < nbytes; ++ n)
        ((char*)(buf))[n] = rand() %256;
}

inline
void arc4random_init(void)
{
  struct timeval tv;
  gettimeofday(&tv, 0);
  // this is not very good, but we lack a portable non-blocking API
  srand( ((unsigned int) tv.tv_usec) ^ (unsigned int)getpid());
}


#endif // ARC4RANDOM_H_INCLUDED
