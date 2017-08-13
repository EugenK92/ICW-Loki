#include <iostream>
#include <string>
#include "brute.h"

std::string find_algorithm(std::string hashstring) {
	//TODO Hier Algorithmus aus Hash herausfinden
	return "bcrypt";
}

int main (int argc, char* argv[]) {
	if (argc < 2) {
		std::cout << "usage:" << std::endl << "\t ./loki <hash> <crypt_algorithm>" << std::endl;
	}
	else {
		std::string algo = "";
		std::string hashstring = argv[1];
		if (argc > 2) {
			algo = argv[2];
		}
		else {
			algo = find_algorithm(hashstring);
		}
		std::cout << std::endl << "Used algorithm: " << algo << std::endl;
		Brute brute(hashstring, algo);
		std::string password = brute.brute_word();
		std::cout << std::endl << "\033[1;32mPassword found: \033[1;31m" << password << "\033[0m" << std::endl << std::endl;
	}
	return 0;
}
