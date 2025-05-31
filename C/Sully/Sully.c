#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#define LAST_CHAR(str)  ((str)[strlen(str) - 3])
#define FILE_PREFIX 5
#define GET_PREFIX(ch) (ch == 'y' ? '5' : ch >= '1' && ch <= '5' ? ch - 1 : '\0')

int main(){char prefix = GET_PREFIX(LAST_CHAR(__FILE__));if (prefix == '\0') return 0;
char filename[8] = "Sully_"; filename[6] = prefix;filename[7] = '\0';char c_file[10] = {0};strcat(c_file, filename);strcat(c_file, ".c");
int fd = open(c_file, 0100 | 02, 0777);char command[100] = {0};
char *s = "#include <string.h>%c#include <stdio.h>%c#include <fcntl.h>%c#include <stdlib.h>%c#include <unistd.h>%c#define LAST_CHAR(str)  ((str)[strlen(str) - 3])%c#define FILE_PREFIX 5%c#define GET_PREFIX(ch) (ch == 'y' ? '5' : ch >= '1' && ch <= '5' ? ch - 1 : '%c0')%c%cint main(){char prefix = GET_PREFIX(LAST_CHAR(__FILE__));if (prefix == '%c0') return 0;%cchar filename[8] = %cSully_%c;filename[6] = prefix;filename[7] = '%c0';char c_file[10] = {0};strcat(c_file, filename);strcat(c_file, %c.c%c);%cint fd = open(c_file, 0100 | 02, 0777);char command[100] = {0};%cchar *s = %c%s%c;%cdprintf(fd, s, 10,10,10,10,10,10,10,92,10,10, 92,10, 34,34,92,34,34,10, 10,34,s,34,10, 34,34,34,34,34,34,34,34,10);system(strcat(strcat(strcat(strcat(command, %cgcc %c), c_file), %c -o %c), filename));bzero(command, 100);execlp(strcat(strcat(command, %c./%c), filename), strcat(command, %c./%c), filename, NULL);}%c";
dprintf(fd, s, 10,10,10,10,10,10,10,92,10,10, 92,10, 34,34,92,34,34,10, 10,34,s,34,10, 34,34,34,34,34,34,34,34,10);system(strcat(strcat(strcat(strcat(command, "gcc "), c_file), " -o "), filename));bzero(command, 100);execlp(strcat(strcat(command, "./"), filename), strcat(command, "./"), filename, NULL);}
