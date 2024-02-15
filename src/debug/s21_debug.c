#define MAIN_CNT 0

#if MAIN_CNT == 0

#include <string.h>

#include "../s21_string.h"

int main(void) {
  char s1[30] = "-?hello, world!";
  char s2[] = "!?-";
  char need_result[] = "hello, world";

  // act
  char *result = s21_trim(s1, s2);

  return 0;
}

#endif
