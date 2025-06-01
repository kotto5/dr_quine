#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#define LAST_CHAR(str)  ((str)[strlen(str) - 3])
#define GET_PREFIX(ch) (ch == 'y' ? '5' : ch >= '1' && ch <= '5' ? ch - 1 : '\0')

int main(){
    char prefix = GET_PREFIX(LAST_CHAR(__FILE__));
    if (prefix == '\0') return 0;
    char filename[16] = {0};
    sprintf(filename, "Sully_%c", prefix);
    char c_file[24] = {0};
    sprintf(c_file, "%s.c", filename);
    int fd = open(c_file, O_CREAT | O_WRONLY, 0777);
    if (fd == -1) {perror("error(open):");return 1;}
    char *s = "#include <string.h>%1$c#include <stdio.h>%1$c#include <fcntl.h>%1$c#include <stdlib.h>%1$c#include <unistd.h>%1$c#define LAST_CHAR(str)  ((str)[strlen(str) - 3])%1$c#define GET_PREFIX(ch) (ch == 'y' ? '5' : ch >= '1' && ch <= '5' ? ch - 1 : '%3$c0')%1$c%1$cint main(){%1$c    char prefix = GET_PREFIX(LAST_CHAR(__FILE__));%1$c    if (prefix == '%3$c0') return 0;%1$c    char filename[16] = {0};%1$c    sprintf(filename, %2$cSully_%%c%2$c, prefix);%1$c    char c_file[24] = {0};%1$c    sprintf(c_file, %2$c%%s.c%2$c, filename);%1$c    int fd = open(c_file, O_CREAT | O_WRONLY, 0777);%1$c    if (fd == -1) {perror(%2$cerror(open):%2$c);return 1;}%1$c    char *s = %2$c%4$s%2$c;%1$c    dprintf(fd, s, 10, 34, 92, s);%1$c    char command[100] = {0};%1$c    sprintf(command, %2$cgcc -Wall -Wextra -Werror %%s -o %%s%2$c, c_file, filename);%1$c    system(command);%1$c    bzero(command, 100);%1$c    sprintf(command, %2$c./%%s%2$c, filename);%1$c    char *args[] = {command, filename, NULL};%1$c    execvp(command, args);%1$c}%1$c";
    dprintf(fd, s, 10, 34, 92, s);
    char command[100] = {0};
    sprintf(command, "gcc -Wall -Wextra -Werror %s -o %s", c_file, filename);
    system(command);
    bzero(command, 100);
    sprintf(command, "./%s", filename);
    char *args[] = {command, filename, NULL};
    execvp(command, args);
}
