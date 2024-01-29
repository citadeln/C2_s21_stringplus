// Возвращает новую строку, в которой удаляются все начальные и конечные вхождения набора заданных символов (trim_chars) из данной строки (src). В случае какой-либо ошибки следует вернуть значение NULL 

#include <string.h>
#include "../s21_string.h"

void *trim(const char *src, const char *trim_chars) {
  // считаем лишние символы и удаляем trim_chars с начала строки:
  size_t i = 0, q = 0;
  for (; q < strlen(trim_chars); q++)
    while ((src[i] == trim_chars[q])) {
      i++;
    }

  size_t j = 0;
  //int count_i_left = i;
  if (i > 0) {
    char s[strlen(src)];
    for (; j < strlen(src) && strchr(src, src[0]) != NULL; j++) {
      s[j] = src[j + i];
    }
    s[j] = '\0';
  }
  // printf("s1 = %s\n\n", s);

  // считаем лишние символы и удаляем trim_chars с конца строки:
  i = strlen(src) - 1;
  q = 0;
  int count_i_right = 0;
  // printf("strlen(trim_chars) = %ld\n i = %ld\n", strlen(trim_chars), i);
  for (; q < strlen(trim_chars); q++)
    while (src[i] == trim_chars[q]) {
      i--;
      count_i_right++;
    }
/*
  printf("strlen(src) - count_i_left - count_i_right = %ld\n",
         strlen(src) - count_i_left - count_i_right);
  printf("strlen(s) - count_i_left - count_i_right = %ld\n",
         strlen(s) - count_i_left - count_i_right);
  printf("count_i_left - %d, count_i_right -%d\n\n", count_i_left,
         count_i_right);
*/

/*
  char res[i];

  for (q = 0; q < (strlen(src) - count_i_left - count_i_right); q++) {
    res[q] = s[q];
    printf("res [%ld] = %c\n", q, res[q]);
  }
  res[q] = '\0';
  printf("res = %s\n", res);
  */
  return 0;
}