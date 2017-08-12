#include <iostream>
#include <string>
#include "brute.h"

Brute::Brute(std::string _hash, std::string _crypt_algorithm) {
	hash = _hash;
	crypt_algorithm = _crypt_algorithm;
}

bool Brute::check_password(std::string word) {
	return false;
}

std::string Brute::shift_chars(std::string word, char first_char, char last_char) {
	int len = word.length();
	if (word[len - 1] == last_char) {
		word += first_char;
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
	std::cout << "Let's Brute" << std::endl;
	char first_char = '0';
	char last_char = '~';
	bool isPw = false;
	std::string password = "A";
	while (!isPw && password != "Eugen") {
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
				password[0]++;
			}
		}
	}
	return password;


	// std::string s = "A";
	// for (int i = 0; i < 79; i++) {
	// 	std::cout << i << ": " << s[0] <<  std::endl;
	// 	if (s == "~") {
	// 		s = "0";
	// 	}
	// 	else {
	// 		s[0]++;
	// 	}
	// }
	// s += "A";
	// std::cout << s <<  std::endl;
	// std::string last_char = "~";
}
