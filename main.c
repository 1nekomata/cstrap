#include <stdio.h>

#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

#include <string.h>

int main(int argc, char *argv[]){
    char buf[60];
    int i;
    char mainfunc[57] = "#include <stdio.h>\n\nint main(int argc, char *argv[]){\n\n}\n";
    int fd;
    
    creat(argv[1], 0700);

    fd = open(argv[1], O_WRONLY);

    write(fd, mainfunc, 57);
    
    close(fd);
    fd = open(argv[1], O_RDONLY);

    read(fd, buf, 57);
    for (i = 0; i < 57; i ++) {
        printf("%c", buf[i]);
    }
    printf("\n");

    close(fd);
}