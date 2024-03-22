#include "../s21_string.h"

/* Находит первый символ в строке str1, который соответствует любому символу,
указанному в строке str2.
  Порядковый номер первого найденного символа (начиная с 1) выводится на
консоль*/
char *s21_strpbrk(const char *str1, const char *str2) {
  char *result = S21_NULL;

  for (; *str1 != '\0'; str1++) {
    if (s21_strchr(str2, *str1)) {
      result = (char *)str1;
      break;
    }
  }
  return result;
}
