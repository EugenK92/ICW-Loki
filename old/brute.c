#include <stdio.h>

#include <string.h>
#include "lib/bcrypt.h"
#include "hashtypes/test_bcrypt.h"
#include "brute.h"

void brute_force() {
	char str[128] = "a";
	int index = 0;
	int len = strlen(str);

	while (len < 3) {
    len = strlen(str);
		for (int i = 0; i < 95; i++) {
			printf("%s\n", str);
      inc_char(str, 0);
		}
    if ((int)str[index] == 97) {
      str[strlen(str)] = 'a';
    }
    if ((int)str[0] == 97) {
      inc_char(str, index);
    }
    index++;
	}


	//str[strlen(str)] = 'a';
	//printf("\n%s\n", str);
}

void inc_char(char* str, int index) {
  str[index] = (str[index] + 1) % 128;
  if ((int)str[index] == 127) {
    str[index] = 32;
  }
}
