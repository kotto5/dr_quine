#include <stdio.h>
#define B(x) x
B(int main(){ // Hoge
  char *s = "#include <stdio.h>%c#define B(x) x%cB(int main(){ // Hoge%c  char *s = %c%s%c;%c  printf(s, 10, 10, 10, 34, s, 34, 10, 10, 10);%c})%c";
  printf(s, 10, 10, 10, 34, s, 34, 10, 10, 10);
})
