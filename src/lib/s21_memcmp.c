#include "../s21_string.h"

/* Сравнивает первые n байтов строк str1 и str2. */
int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  int result = 0;
  unsigned char *str1_temp = (unsigned char *)str1;
  unsigned char *str2_temp = (unsigned char *)str2;

  while (n > 0) {
    if (str1_temp[0] == str2_temp[0]) {
      result = 0;
      str1_temp++;
      str2_temp++;
    } else if (str1_temp[0] <
               str2_temp[0]) {  // условие покрывает все варианты, т.к. '/0'
                                // имеет минимально значение в ASCII = 0
      result = -1;
      break;
    } else {
      result = 1;
      break;
    }
    n--;
  }
  return result;
}
