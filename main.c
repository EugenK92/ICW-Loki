#include <stdio.h>
#include "lib/bcrypt.h"

int test_bcrypt_password(char*, char*);

int main(int agrc, char* argv[]) {

/*	
	char salt[BCRYPT_HASHSIZE];
	char hash[BCRYPT_HASHSIZE];

	bcrypt_gensalt(12, salt);
	printf("Generated salt: %s\n", salt);	

	char* pw = "test";
	bcrypt_hashpw(pw, salt, hash);
	printf("Password: %s\nHash:%s\n", pw, hash);	
*/
	
// $2a$12$uIaLVPwQKk7uTIGZ/CSIAuj.ySh6ripW2gX8Tbu.P7EOW4LI2s2li
	printf("PW:%s\nHash:%s\n", argv[1], argv[2]);
	printf("%d\n", test_bcrypt_password(argv[1], argv[2]));
	return 1;
}

int test_bcrypt_password(char* pw, char* hash) {	
	return bcrypt_checkpw(pw, hash);
}
