#include "../lib/bcrypt.h"

int test_bcrypt_password(char* pw, char* hash) {	
	return bcrypt_checkpw(pw, hash);
}
