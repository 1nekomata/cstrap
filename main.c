/* cstrap, a program to create a skeleton .c file
    Copyright (C) 2022  1nekomata

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

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
