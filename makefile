CC = g++
NAME = loki
CFLAGS =
LDFLAGS =

loki: lib/*.c lib/crypt_blowfish/*.c main.cc brute.cc
	$(CC) lib/*.c lib/crypt_blowfish/*.c main.cc brute.cc -o $(NAME)

clean:
	rm $(NAME)
