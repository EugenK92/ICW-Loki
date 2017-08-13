#include <iostream>
#include <string>
#include "brute.h"

int main (int argc, char* argv[]) {
	if (argc < 3) {
		std::cout << "usage:" << std::endl << "\t ./loki <hash> <crypt_algorithm>" << std::endl;
	}
	else {
		Brute brute(argv[1], argv[2]);
		std::string password = brute.brute_word();
		std::cout << "Password: " << password << std::endl;
	}
	return 0;
}
