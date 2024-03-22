#include "../s21_string.h"

/* Копирует n символов из src в dest. */
void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  const unsigned char *src_temp = (const unsigned char *)src;
  unsigned char *dest_temp = (unsigned char *)dest;

  for (s21_size_t i = 0; i < n; i++) {
    dest_temp[i] = src_temp[i];
  }
  return dest;
}
