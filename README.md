# Bcrypt.cpp
A c++ wrapper around bcrypt (origin: Open BSD) password hashing

## How to use

Here an example how to use this wrapper class

```cpp
#include "bcrypt.h"
#include <iostream>

int main(){
	std::string password = "test";
	std::string hash = BCrypt::generateHash(password);

	std::cout << BCrypt::validatePassword(password,hash) << std::endl;
	std::cout << BCrypt::validatePassword("test1",hash) << std::endl;

	return 0;
}
```
