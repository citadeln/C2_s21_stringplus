#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char *trim_chars = malloc(100);
  scanf("%s", trim_chars);

  char *src = malloc(100);
  scanf("%s", src);

  char s[strlen(src)];
  // считаем лишние символы и удаляем trim_chars с начала строки:
  size_t i = 0, j, q = 0;
  for (; q < strlen(trim_chars); q++)
    while ((src[i] == trim_chars[q])) {
      i++;
    }

  int count_i_left = i;
  if (i > 0) {
    for (j = 0; j < strlen(src) && strchr(src, src[0]) != NULL; j++) {
      s[j] = src[j + i];
    }
    s[j] = '\0';
  }
  printf("s1 = %s\n\n", s);

  // считаем лишние символы и удаляем trim_chars с конца строки:
  i = strlen(src) - 1;
  q = 0;
  int count_i_right = 0;
  printf("strlen(trim_chars) = %ld\n i = %ld\n", strlen(trim_chars), i);
  for (; q < strlen(trim_chars); q++)
    while (src[i] == trim_chars[q]) {
      i--;
      count_i_right++;
    }

  printf("strlen(src) - count_i_left - count_i_right = %ld\n",
         strlen(src) - count_i_left - count_i_right);
  printf("strlen(s) - count_i_left - count_i_right = %ld\n",
         strlen(s) - count_i_left - count_i_right);
  printf("count_i_left - %d, count_i_right -%d\n\n", count_i_left,
         count_i_right);

  char res[i];

  for (q = 0; q < (strlen(src) - count_i_left - count_i_right); q++) {
    res[q] = s[q];
    printf("res [%ld] = %c\n", q, res[q]);
  }
  res[q] = '\0';
  printf("res = %s\n", res);

  free(trim_chars);
  free(src);
  return 0;
}