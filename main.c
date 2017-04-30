#include <stdio.h>
#include <string.h>
#include "lib/bcrypt.h"
#include "hashtypes/test_bcrypt.h"

void brute_force();

int main(int argc, char* argv[]) {

	brute_force();
	
	return 1;
}

void brute_force() {
	char str[128] = "aaa";
	int index = 0;	
	int len = strlen(str);

	while (index < len) {
		printf("%ld\n", strlen(str));
		for (int i = 0; i < 95; i++) {
			printf("%s\n", str);
			str[0] = (str[0] + 1) % 128;
			if ((int)str[0] == 127) {
				str[0] = 32;
			}
		}
		if ((int)str[index + 1] == 97) {
			index++;
		}
	}	
		
	//str[strlen(str)] = 'a';
	//printf("\n%s\n", str);
}

