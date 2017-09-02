#include <iostream>
#include <string>
#include <crypt.h>
#include "brute.h"
#include "hashtypes/md5.h"
#include "lib/bcrypt.h"

Brute::Brute(std::string _hash, std::string _crypt_algorithm) {
	hash = _hash;
	crypt_algorithm = _crypt_algorithm;
}

int Brute::mapAlgorithmToNum() {
	if (crypt_algorithm == "bcrypt") return 1;
	if (crypt_algorithm == "md5") return 2;
	if (crypt_algorithm == "crypt") return 3;
}

bool Brute::check_password(std::string word) {
	const char * w = word.c_str();
	const char * h = hash.c_str();
	switch (mapAlgorithmToNum()) {
		case 1: return bcrypt_checkpw(w, h) == 0; break;
		case 2: return md5(w) == h; break;
		case 3: return crypt(w, h) == hash; break;
	}
}

std::string Brute::shift_chars(std::string word, char first_char, char last_char) {
	int len = word.length();
	int i = 1;
	bool done = false;
	int full = 0;
	for (int i = 0; i < word.length(); i++) {
		if (word[i] == last_char) {
			full++;
		}
	}
	if (full == word.length()) {
		word += first_char - 1;
	}
	while (!done) {
		if (word[i] == last_char) {
			word[i] = first_char;
			i++;
		}
		else {
			word[i]++;
			done = true;
		}
	}
	return word;
}

std::string Brute::brute_word(std::string start_word, std::string end_word) {
	std::cout << "Let's Brute..." << std::endl;
	char first_char = (char) 33;
	char last_char = (char) 126;
	bool isPw = false;
	std::string password = start_word;
	unsigned int counter = 0;

	while (!isPw && password != end_word) {
		// std::cout << password << "  [ " << counter << " ] " <<  (int)password[0] << std::endl;
		if (counter % 10000 == 0) {
			// std::cout.width(6); std::cout << "[# " << counter << "]\tWorking... current: " << password << std::right << std::endl;
		}
		if (check_password(password)) {
			isPw = true;
			std::cout.width(6); std::cout << "[# " << counter << "]\tMatch! " << std::right << std::endl;
		}
		else {
			if (password[0] == last_char) {
				password = shift_chars(password, first_char, last_char);
				password[0] = first_char;
			}
			else {
				if ((int)password[0] < 33) {
					password[0] = password[0] + 32;
				}
				password[0] = (password[0] + 1) % 127;
			}
		}
		counter++;
	}
	if (!isPw) {
		return " End reached without result!";
	}
	return password;
}
