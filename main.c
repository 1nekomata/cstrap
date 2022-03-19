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
#include <stdlib.h>

#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

#include <string.h>

int main(int argc, char *argv[]){
    if (argv[1] == NULL){
        printf("No filename specified!\n");
        exit(1);
    }

    char *temp = NULL;
    char *buf = NULL;
    int cnt = 0, len = 0, fd;
    char *headers = NULL;
    char *mainfuncpart1 = "#include <stdio.h>\n";
    char *mainfuncpart2 = "\nint main(int argc, char *argv[]){\n\n\n    return 0;\n}\n";
    char *mainfunc = NULL;

    if(argv[2] != NULL){
        for(int i = 2; i <= argc; i++){
        cnt++;
        }

        for(int i = 2; i <= cnt; i++){
            //printf("cnt = %d, i = %d\n", cnt, i);
            //printf("argv[%d] = %s\n", i, argv[i]);
            len += strlen(argv[i]) + strlen("#include <>\n") + 1;
            //printf("len = %d\n", len);
        }

        headers = realloc(headers, len + 15);

        for(int i = 2; i < argc; i++){
            temp = realloc(temp, strlen("#include <>\n") + strlen(argv[i]) + 1);
            sprintf(temp, "#include <%s>\n", argv[i]);
            strcat(headers, temp);
        }

        mainfunc = realloc(mainfunc, len + strlen(temp) + strlen(mainfuncpart1) + strlen(mainfuncpart2));

        strcat(mainfunc, mainfuncpart1);
        strcat(mainfunc, headers);
        strcat(mainfunc, mainfuncpart2);

    } else {
        mainfunc = realloc(mainfunc, strlen("#include <stdio.h>\n\nint main(int argc, char *argv[]){\n\n\n    return 0;\n}\n"));
        mainfunc = "#include <stdio.h>\n\nint main(int argc, char *argv[]){\n\n\n    return 0;\n}\n";
    }

    creat(argv[1], 0700);

    fd = open(argv[1], O_WRONLY);

    write(fd, mainfunc, strlen(mainfunc));

    close(fd);
    fd = open(argv[1], O_RDONLY);

    buf = realloc(buf, strlen(mainfunc));

    read(fd, buf, strlen(mainfunc));

    printf("%s", buf);

    free(buf);

    if(argv[2] != NULL){
        free(mainfunc);
    }

    if(argv[2] != NULL){
        free(temp);
    }

    close(fd);
}