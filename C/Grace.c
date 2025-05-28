#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define EXPAND(x) C(TOSTRING(C))
#define C(x) int main(int argc, char** argv){   int fd = open("Grace_kid.c", O_CREAT | O_RDWR);   if (fd == -1) return 0;   char *s = "#include <stdio.h>%c#include <fcntl.h>%c#include <unistd.h>%c%c#define A %s %cint main(int argc, char** argv){%c  int fd = open(%cGrace_kid.c%c, O_CREAT | O_RDWR);%c  if (fd == -1) return 0;  %cchar *s = %c%s%c;%c    dprintf(fd, s, 10,10,10,10,10,10,34, 34,10,10, s, 34, 10, 10);%c}%c";   dprintf(fd, s, 10,10, 10, 10,#x,10,10,34,34,10,10,34, s, 34, 10, 10, 10); };
#define TOSTRING(x) #x

C(TOSTRING(C))
