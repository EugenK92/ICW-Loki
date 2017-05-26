#include <stdio.h>

#include <string.h>
#include "lib/bcrypt.h"
#include "hashtypes/test_bcrypt.h"
#include "brute.h"

void brute_force() {
	char str[128] = "a";
	int index = 0;
	int len = strlen(str);

	while (index < len) {
		for (int i = 0; i < 95; i++) {
			printf("%s\n", str);
      inc_char(str);
		}
		index++;
	}

	//str[strlen(str)] = 'a';
	//printf("\n%s\n", str);
}

void inc_char(char* str) {
  str[0] = (str[0] + 1) % 128;
  if ((int)str[0] == 127) {
    str[0] = 32;
  }
}
