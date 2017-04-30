CC = gcc
NAME = loki
CFLAGS =
LDFLAGS =

loki: lib/*.c lib/crypt_blowfish/*.c hashtypes/*.c main.c 
	$(CC) lib/*.c lib/crypt_blowfish/*.c hashtypes/*.c main.c -o $(NAME)

clean:
	rm $(NAME)
