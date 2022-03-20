.PHONY build:
build:
	@gcc -o cstrap main.c -Wall -O2

.PHONY install:
install:
	@cp cstrap /usr/local/bin/
	
.PHONY install-usr-bin:
install-usr-bin:
	@cp cstrap /usr/bin/
	
.PHONY install-bin:
install-bin:
	@cp cstrap /bin/

.PHONY clean:
clean:
	rm -rf cstrap
