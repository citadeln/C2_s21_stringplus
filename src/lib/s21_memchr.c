#include "../s21_string.h"

/* Ищет первое вхождение символа c (символ без знака) в первых n байтах
строки, на которую указывает аргумент str. */
void *s21_memchr(const void *str, int c, s21_size_t n) {
  // переменная для сохранения указателя на искомый символ
  unsigned char *result = S21_NULL;
  unsigned char *str_temp = (unsigned char *)str;

  while (n > 0) {
    if ((unsigned char)c == (unsigned char)str_temp[0]) {
      result = str_temp;
      break;
    } else {
      str_temp++;
    }
    n--;
  }
  return (void *)result;
}
