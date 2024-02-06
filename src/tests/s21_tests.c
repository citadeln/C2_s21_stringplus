#include "s21_tests.h"

#include <stdio.h>

static void print_head(void);

int main(void) {
  print_head();

  RUN_TEST(trim);
  
  printf("\n");
  return 0;
}

static void print_head(void) {
  printf(
      "\033[34m****************************************************************"
      "*******"
      "\n\033["
      "39m");
  printf(
      "\033[34m***\033[39m Тесты s21_string.h \033[34m***\033[39m "
      "\033[32m monroebu / moryamel / tilmapat / typewria \033[39m "
      "\033[34m***\033[39m\n");
  printf(
      "\033[34m****************************************************************"
      "*******"
      "\n\n\033["
      "39m");
}
