#include <iostream>
#include <string>
#include "brute.h"

Brute::Brute(std::string _hash, std::string _crypt_algorithm) {
	hash = _hash;
	crypt_algorithm = _crypt_algorithm;
}

bool Brute::check_password(std::string word) {
	
}

std::string Brute::shift_chars(std::string word, std::string first_char, std::string last_char) {

}

std::string Brute::brute_word() {
	std::cout << "Let's Brute" << std::endl;
}
