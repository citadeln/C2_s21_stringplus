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

  //int count_i_left = i;
  size_t j = 0;
  char *s = malloc(strlen(src) + 1);

  if (i > 0) {  
    for (; j < strlen(src) && strchr(src, src[0]) != NULL; j++) {
      s[j] = src[j + i];
    }
    s[j] = '\0';
  }
  printf("s1 = %s\n", s);

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
  printf("strlen(s) - count_i_left - count_i_r
s1 = ��HX
s2 = ��HXight = %ld\n",
         strlen(s) - count_i_left - count_i_right);
  printf("count_i_left - %d, co
  char res[i];unt_i_right -%d\n\n", count_i_left,
         count_i_right);
*/

/*
  strncpy(src, s, strlen(src));

  //for (q = 0; q < (strlen(src) - count_i_left - count_i_right); q++)
  //  src[q] = s[q];

  src[strlen(s) + 1] = '\0';
  //printf("res = %s\n", res);
*/
  printf("s2 = %s\n", s);

  printf("\033[34m____next test____\n""\n\033[""39m");

  return s;

}