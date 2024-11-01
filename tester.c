#include <string.h>

int main() {
  char *p;
  
  p = strnstr("lorem ipsum dolor sit amet", "dolor", 15);
  printf("%s", p);
}