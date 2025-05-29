#include <stdio.h>
#include <fcntl.h>
#define TOSTRING(X) #X
#define SOURCE int main() {int fd = open("./Grace_kid.c", 0100 | 02);char *str; str = "#include <stdio.h>%c#include <fcntl.h>%c#define TOSTRING(X) #X%c#define SOURCE %s%c#define FT(SRC) SRC dprintf(fd, str, 10, 10, 10, TOSTRING(SRC), 10, 10, 10);}%cFT(SOURCE)%c";
#define FT(SRC) SRC dprintf(fd, str, 10, 10, 10, TOSTRING(SRC), 10, 10, 10);}
FT(SOURCE)
