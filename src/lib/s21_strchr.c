#include "../s21_string.h"

/* Ищет первое вхождение символа c (unsigned char) в строке, на которую
указывает аргумент str.
  На экран выводится его порядковый номер в строке (отчет с единицы). */
char *s21_strchr(const char *str, int c) {
  unsigned char value = (unsigned char)c;
  s21_size_t size = s21_strlen(str) + 1;

  char *result = S21_NULL;
  for (s21_size_t i = 0; i < size; ++i) {
    if (str[i] == value) {
      result = (char *)&str[i];
      break;
    }
  }
  return result;
}
