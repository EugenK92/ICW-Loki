#include <iostream>
#include <string>
#include "brute.h"

int main (int argc, char* argv[]) {
	Brute brute("1", "2");
	std::string password = brute.brute_word();
	std::cout << password << std::endl;
}
