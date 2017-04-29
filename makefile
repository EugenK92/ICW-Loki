CC = gcc
NAME = odin
CFLAGS =
LDFLAGS =

odin: lib/*.c lib/crypt_blowfish/*.c hashtypes/*.c main.c 
	$(CC) lib/*.c lib/crypt_blowfish/*.c hashtypes/*.c main.c -o $(NAME)

clean:
	rm $(NAME)
