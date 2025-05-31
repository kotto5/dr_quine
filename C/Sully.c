#include <strings.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#define TOSTRING(X) #X
#define FT(SRC) SRC dprintf(fd, str, 10, 10, 10, TOSTRING(SRC), 10, 10, 10);}

#define LAST_CHAR(str)  ((str)[strlen(str) - 3])
#define FILE_PREFIX 5
#define GET_PREFIX(ch) (ch == 'y' ? '5' : ch >= '0' && ch <= '5' ? ch - 1 : '\0') 

int main() {
  char prefix = GET_PREFIX(LAST_CHAR(__FILE__));
  if (prefix == '\0') return 0;
  char filename[8] = "Sully_";
  filename[6] = prefix;
  filename[7] = '\0';

  char c_file[10] = {0};
  strcat(c_file, filename);
  strcat(c_file, ".c");

  int fd = open(c_file, 0100 | 02, 0777);
  char *s = "source_code";

  char command[100] = {0};
  dprintf(fd, s);
  system(strcat(strcat(strcat(strcat(command, "gcc "), c_file), " -o "), filename));
  bzero(command, 100);
  execlp(strcat(strcat(command, "./"), filename), NULL);
}
