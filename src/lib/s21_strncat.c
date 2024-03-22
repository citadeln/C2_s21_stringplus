#include "../s21_string.h"

/* Добавляет строку, на которую указывает src, к концу строки, на которую
указывает dest, длиной до n символов. */
char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  char *tmp = dest;

  while (*tmp != '\0') tmp++;  // Move the pointer to the end of dest
  for (s21_size_t i = 0; i < n && src[i] != '\0';
       i++) {  // Append n characters from src
    *tmp++ = src[i];
  }
  *tmp = '\0';  // Null terminate dest

  return dest;
}
