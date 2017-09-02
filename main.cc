#include <iostream>
#include <string>
#include "brute.h"
#include <crypt.h>
#include <mpi.h>
#include <vector>

std::string get_start_word(int world_rank, int world_size) {
	int diff = (94 * world_rank/ world_size) + 33;
	std::string word = "";

	if (world_rank <= 4) {
		word = (char)diff;
	}
	else if (world_rank > 3 && world_rank <= 6) {
		word = (char)diff;
		word += (char)diff;
	}
	else if (world_rank > 6 && world_rank <= 10) {
		word = (char)diff;
		word += (char)diff;
		word += (char)diff;
	}
	else if (world_rank > 10 && world_rank <= 14) {
		word = (char)diff;
		word += (char)diff;
		word += (char)diff;
		word += (char)diff;
	}
	else if (world_rank > 14) {
		word = (char)diff;
		word += (char)diff;
		word += (char)diff;
		word += (char)diff;
		word += (char)diff;
	}
	return word;
}

int main (int argc, char * argv[]) {

	if (argc < 2) {
		std::cout << "usage:" << std::endl << "\t ./loki <hash> [<crypt_algorithm>]" << std::endl;
	}
	else {
		std::string algo = "";
		std::string hashstring = "";

		for (int i = 0; i < argc; i++) {
			std::string value = argv[i];
			if (value == "-h" || value == "--hash") {
				hashstring = argv[i + 1];
			}
			else if (value == "-a" || value == "--algo") {
				algo = argv[i + 1];
			}
		}

		// std::cout << std::endl << "Used algorithm: " << algo << std::endl;
		// std::cout << "Hash: " << hashstring << std::endl;

		// Initialize the MPI environment
    MPI_Init(NULL, NULL);
    // Get the number of processes
    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);
    // Get the rank of the process
    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    // Get the name of the processor
    char processor_name[MPI_MAX_PROCESSOR_NAME];
    int name_len;
    MPI_Get_processor_name(processor_name, &name_len);

		std::cout << "processor " << processor_name << " rank " << world_rank << " / " << world_size << std::endl;

		Brute brute(hashstring, algo);

		std::string start_word = get_start_word(world_rank, world_size);
		std::string end_word = "~~~~~~~~~~";

		std::cout << start_word << std::endl;

		std::string password = brute.brute_word(start_word, end_word);
		std::cout << std::endl << "\033[1;32mPassword found: \033[1;31m" << password << "\033[0m" << std::endl << std::endl;
		MPI_Abort(MPI_COMM_WORLD, 0);
		MPI_Finalize();
	}
	return 0;
}
