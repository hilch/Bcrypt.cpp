#include "bcrypt.h"
#include <iostream>
#include <string>


int main()
{

    std::string password = "top_secret";

    std::string hash = bcrypt::generateHash(password);

    std::cout << "Hash: " << hash << std::endl;

    std::cout << "\"" << password << "\" : " << bcrypt::validatePassword(password,hash) << std::endl;
    std::cout << "\"wrong\" : " << bcrypt::validatePassword("wrong",hash) << std::endl;

    return 0;
}
