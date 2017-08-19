CC = g++
STD = -std=c++11
NAME = loki
CFLAGS = -lcrypt
LDFLAGS =

loki: lib/*.c lib/crypt_blowfish/*.c hashtypes/md5.cc main.cc brute.cc
	$(CC) $(STD) lib/*.c lib/crypt_blowfish/*.c hashtypes/md5.cc main.cc brute.cc -o $(NAME) $(CFLAGS)

clean:
	rm $(NAME)
