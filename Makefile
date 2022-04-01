PREFIX = /usr/local
BIN = bin

.PHONY build:
build:
	@gcc -o cstrap main.c -Wall -O2

.PHONY install:
install:
        @cp cstrap ${PREFIX}/${BIN}

.PHONY clean:
clean:
	rm -rf cstrap
