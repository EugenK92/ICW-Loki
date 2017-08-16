CC = g++
STD = -std=c++11
NAME = loki
CFLAGS =
LDFLAGS =

loki: lib/*.c lib/crypt_blowfish/*.c main.cc brute.cc
	$(CC) $(STD) lib/*.c lib/crypt_blowfish/*.c main.cc brute.cc -o $(NAME)

clean:
	rm $(NAME)
