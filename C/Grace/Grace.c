#include <stdio.h>
#include <fcntl.h>
/* open's option value is different each OS... */
#define TOSTRING(X) #X
#define SOURCE int main() {int fd = open("./Grace_kid.c", 01 | 100, 0777);char *str; str = "#include <stdio.h>%1$c#include <fcntl.h>%1$c/* open's option value is different each OS... */%1$c#define TOSTRING(X) #X%1$c#define SOURCE %2$s%1$c#define FT(SRC) SRC dprintf(fd, str, 10, TOSTRING(SRC));}%1$cFT(SOURCE)%1$c";
#define FT(SRC) SRC dprintf(fd, str, 10, TOSTRING(SRC));}
FT(SOURCE)
