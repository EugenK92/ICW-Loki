#include <iostream>
#include <string>
#include "brute.h"

int main (int argc, char* argv[]) {
	// std::cout << argv[1] << std::endl;
	Brute brute(argv[1], "2");
	std::string password = brute.brute_word();
	std::cout << "Password: " << password << std::endl;
}
