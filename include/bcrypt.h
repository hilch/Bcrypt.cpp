#ifndef BCRYPT_H
#define BCRYPT_H

#include <string>

namespace bcrypt
{

class BCrypt {
public:
    static std::string generateHash(const std::string & password , unsigned rounds = 10 );
    static bool validatePassword(const std::string & password, const std::string & hash);

};


int bcrypt_newhash(const char *pass, int log_rounds, char *hash, size_t hashlen);
int bcrypt_checkpass(const char *pass, const char *goodhash);

}

#endif // BCRYPT_H
