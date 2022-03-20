# cstrap

cstrap creates a file that contains 
```
#include <stdio.h>

int main(int argc, char *argv[]){


    return 0;
}
```

## Building

Run `make build && sudo make install` to build and install cstrap to the /usr/local/bin directory.

Alternatively you can change the installation directory with install-usr-bin or install-bin to
/usr/bin and /bin directories

## Usage

`cstrap [filename] <header> <header> ...`
