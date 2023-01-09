#include <stdio.h>

#define PURPLE "\033[38;5;177m"
#define PINK "\033[38;5;219m"
#define BACKGROUND "\033[48;5;105m"
#define CLEAR "\033[0m"

int main (int argc, char const *argv[]) {

  printf(PURPLE "This text is COLOURED!\n" CLEAR);
  printf(PINK "So is this!\n" CLEAR);
  printf(BACKGROUND "This has a background!\n" CLEAR);
  return 0;
}
