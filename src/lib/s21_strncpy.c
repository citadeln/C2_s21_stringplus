#include "../s21_string.h"

/* Копирует до n символов из строки, на которую указывает src, в dest, пока не
 * встретится символ конца строки (нулевой символ) или количество скопированных
 * символов не достигнет величины указанной в аргументе n. При этом символ конца
 * строки не копируется. */
char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  s21_size_t src_len = s21_strlen(src);
  n = n < src_len ? n : src_len;

  for (s21_size_t i = 0; i < n; i++) {
    dest[i] = src[i];
  }

  if (n == src_len)
    dest[n] = '\0';  //если убрать if, то failed (n=1, src=fr-ar-ar, dest=Hello,
                     // world!): strncpy(s1, s3, n) == "fello, world!",
                     // s21_strncpy(s2, s3, n) == "f"

  return dest;
}
