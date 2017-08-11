#ifndef BRUTE_H
#define BRUTE_H

#include <string.h>

class Brute {

private:

	std::string hash;
	std::string crypt_algorithm;

public:

  Brute(std::string hash, std::string crypt_algorithm);
	bool check_password(std::string word);
	std::string shift_chars(std::string word, std::string first_char, std::string last_char);
	std::string brute_word();

};

#endif /* BRUTE_H */
