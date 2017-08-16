#include <iostream>
#include <string>
#include "brute.h"
#include "lib/bcrypt.h"

Brute::Brute(std::string _hash, std::string _crypt_algorithm) {
	hash = _hash;
	crypt_algorithm = _crypt_algorithm;
}

int Brute::mapAlgorithmToNum() {
	if (crypt_algorithm == "bcrypt") return 1;
}

bool Brute::check_password(std::string word) {
	const char * w = word.c_str();
	const char * h = hash.c_str();
	switch (mapAlgorithmToNum()) {
		case 1: return bcrypt_checkpw(w, h) == 0; break;
	}
}

std::string Brute::shift_chars(std::string word, char first_char, char last_char) {
	int len = word.length();
	if (word[len - 1] == last_char) {
		word += first_char - 1;
	}
	int i = 1;
	bool done = false;
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
	int counter = 0;

	while (!isPw && password != end_word) {
		// std::cout << password << std::endl;
		if (counter % 1000 == 0) {
			std::cout.width(6); std::cout << "[# " << counter << "]\tWorking... current: " << password << std::right << std::endl;
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
