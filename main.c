#include <stdio.h>
#include "lib/bcrypt.h"
#include "hashtypes/test_bcrypt.h"

int main(int argc, char* argv[]) {

	if (argc < 2) {
		printf("usage:\n\t./odin <passwordhash> <[hashtype]>\n");
		return 0;
	}
	
	char* hash = argv[1];
	char* test_password = "test";

// $2a$12$uIaLVPwQKk7uTIGZ/CSIAuj.ySh6ripW2gX8Tbu.P7EOW4LI2s2li
	printf("PW:%s\nHash:%s\n", test_password, hash);
	printf("%d\n", test_bcrypt_password(test_password, hash));
	return 1;
}

