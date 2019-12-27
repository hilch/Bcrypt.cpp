#include "bcrypt.h"
#include <iostream>
#include <string>

using namespace bcrypt;

int main()
{

    std::string password = "top_secret";

    std::string hash = BCrypt::generateHash(password);

    std::cout << "Hash: " << hash << std::endl;

    std::cout << "\"" << password << "\" : " << BCrypt::validatePassword(password,hash) << std::endl;
    std::cout << "\"wrong\" : " << BCrypt::validatePassword("wrong",hash) << std::endl;

    return 0;
}
