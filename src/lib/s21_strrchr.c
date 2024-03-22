#include "../s21_string.h"

/* Ищет последнее вхождение символа c (беззнаковый char) в строке, на которую
указывает аргумент str. */
char *s21_strrchr(const char *str, int c) {
  const char *result = S21_NULL;
  int lenght = s21_strlen(str);
  for (int i = lenght; i >= 0; i--) {
    if (str[i] == c) {
      result = (str + i);
      break;
    }
  }
  return (char *)result;
}
