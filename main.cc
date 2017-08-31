#include <iostream>
#include <string>
#include "brute.h"
#include <crypt.h>

std::string find_algorithm(std::string hashstring) {
	//TODO Hier Algorithmus aus Hash herausfinden
	return "bcrypt";
}

int main (int argc, char * argv[]) {

	if (argc < 2) {
		std::cout << "usage:" << std::endl << "\t ./loki <hash> [<crypt_algorithm>] [<start_word>] [<end_word>]" << std::endl;
	}
	else {
		std::string algo = "";
		std::string start_word = "!";
		std::string end_word = "~~~~~~~~~~";
		std::string hashstring = "";

		for (int i = 0; i < argc; i++) {
			std::string value = argv[i];
			if (value == "-h" || value == "--hash") {
				hashstring = argv[i + 1];
			}
			else if (value == "-a" || value == "--algo") {
				algo = argv[i + 1];
			}
			else if (value == "-s" || value == "--start") {
				start_word = argv[i + 1];
			}
			else if (value == "-e" || value == "--end") {
				end_word = argv[i + 1];
			}
		}

		std::cout << std::endl << "Used algorithm: " << algo << std::endl;
		std::cout << "Hash: " << hashstring << std::endl;
		std::cout << "Start from: " << start_word << std::endl;
		std::cout << "End at: " << end_word << std::endl << std::endl;

		Brute brute(hashstring, algo);
		std::string password = brute.brute_word(start_word, end_word);
		std::cout << std::endl << "\033[1;32mPassword found: \033[1;31m" << password << "\033[0m" << std::endl << std::endl;
	}
	return 0;
}
