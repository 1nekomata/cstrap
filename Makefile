.PHONY build:
build:
	@gcc -o cstrap main.c -Wall -O2

.PHONY install:
install:
	@cp cstrap /usr/local/bin/

.PHONY clean:
clean:
	rm -rf cstrap
