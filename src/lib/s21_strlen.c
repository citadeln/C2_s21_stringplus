#include "../s21_string.h"

/* Вычисляет длину строки str до завершающего нулевого символа, но не включая
его. */
s21_size_t s21_strlen(const char *str) {
  s21_size_t result = 0;

  while (str[result] != '\0') {
    result++;
  }
  return result;
}
