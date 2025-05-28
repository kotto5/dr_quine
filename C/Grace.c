#include <stdio.h>
#include <fcntl.h>
#define B(x) x
B(int main(){ // Hoge
int fd = open("./Grace_kid.c", O_CREAT | O_RDWR);char *s = "#include <stdio.h>%c#include <fcntl.h>%c#define B(x) x%cB(int main(){ // Hoge%cint fd = open(%c./Grace_kid.c%c, O_CREAT | O_RDWR);char *s = %c%s%c;%cdprintf(fd, s, 10, 10, 10, 10, 34, 34, 34, s, 34, 10, 10, 10);%c})%c";
dprintf(fd, s, 10, 10, 10, 10, 34, 34, 34, s, 34, 10, 10, 10);
})
