#include <iostream>
#include <string>
#include "brute.h"
#include "lib/bcrypt.h"

Brute::Brute(std::string _hash, std::string _crypt_algorithm) {
	hash = _hash;
	crypt_algorithm = _crypt_algorithm;
}

bool Brute::check_password(std::string word) {
	const char * w = word.c_str();
	const char * h = hash.c_str();
	// const char * h = "$2a$04$tov05GAdc4IKzLmOdz7l6O7rraKt8C5oIX.w6ofnGomsBsiKagAOC";
	// std::cout << bcrypt_checkpw(w, h) << std::endl;
	return bcrypt_checkpw(w, h) == 0;
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

std::string Brute::brute_word() {
	std::cout << "Let's Brute..." << std::endl;
	char first_char = (char) 33;
	char last_char = (char) 126;
	bool isPw = false;
	std::string password = "!";

	while (!isPw) {
		if (check_password(password)) {
			isPw = true;
		}
		else {
			std::cout << password << std::endl;
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
	}
	return password;
}
