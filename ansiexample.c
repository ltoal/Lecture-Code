#include <stdio.h>

#define PURPLE "\033[38;5;177m"
#define PINK "\033[38;5;219m"

int main (int argc, char const *argv[]) {

  printf(PURPLE "This text is COLOURED!\n");
  printf(PINK "So is this!\n");
  return 0;
}
