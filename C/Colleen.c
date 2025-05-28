#include <stdio.h> // Hey
int get10() { return 10;}
int main() {
  char *s = "#include <stdio.h> // Hey%cint get10() { return 10;}%cint main() {%c  char *s = %c%s%c;%c  printf(s, get10(), 10, 10, 34, s, 34, 10, 10, 10); // Foy%c}%c";
  printf(s, get10(), 10, 10, 34, s, 34, 10, 10, 10); // Foy
}
