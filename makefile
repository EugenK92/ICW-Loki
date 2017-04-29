CC = gcc
NAME = odin
CFLAGS =
LDFLAGS =

odin: lib/*.c lib/crypt_blowfish/*.c main.c
	$(CC) lib/*.c lib/crypt_blowfish/*.c main.c -o $(NAME)

clean:
	rm $(NAME)
