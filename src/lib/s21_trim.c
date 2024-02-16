// Возвращает новую строку, в которой удаляются все начальные и конечные
// вхождения набора заданных символов (trim_chars) из данной строки (src). В
// случае какой-либо ошибки следует вернуть значение NULL

#include <string.h>

#include "../s21_string.h"

int check_entrance(const char *src, const char *trim_chars, size_t i) {
  for (size_t q = 0; q < strlen(trim_chars); q++)
    if (src[i] == trim_chars[q]) {
      i++;
      i = check_entrance(src, trim_chars, i);
    }
  return i;
}

int check_end(const char *s, const char *trim_chars, size_t j) {
  printf("(count_i_right (j) = %ld\n", j);
  for (size_t q = 0; q < strlen(trim_chars); q++) {
    printf("(count_i_right (j) = %ld\n", j);
    if (s[j] == trim_chars[q]) {
      j--;
      j = check_end(s, trim_chars, j);
    }
  }
  return j;
}

void *trim(const char *src, const char *trim_chars) {
  printf("src = %s \t trim_chars = %s\n", src, trim_chars);
  if (src == S21_NULL)
    return S21_NULL;
  else {
    char *s = calloc(strlen(src) + 1, sizeof(char));

    if (trim_chars == S21_NULL)
      strncpy(s, src, strlen(src));

    else {
      size_t i = check_entrance(
          src, trim_chars,
          0);  // считаем лишние символы и удаляем trim_chars с начала строки:
      printf("strlen(trim_chars) = %ld\tstrlen(src) = %ld\t i = %ld\t s = %s\n",
             strlen(trim_chars), strlen(src), i, s);

      size_t j = 0;
      for (int k = 0; j + i < strlen(src); j++, k++) {
        // printf("s = %s\n", s);
        s[k] = src[j + i];
        // printf("s = %s\n", s);
      }

      printf("i = %ld\t j = %ld\ts = %s\n", i, j, s);

      size_t count_i_right =
          check_end(s, trim_chars, j - 1);  // указывает на последний символ
                                            // (его порядковый номер в строке)

      printf("i = %ld\t count_i_right = %ld\ts = %s\n", i, count_i_right, s);

      s[count_i_right + 1] = '\0';

      printf("s = %s\n", s);

      printf(
          "\033[34m____next test____\n"
          "\n\033["
          "39m");
    }

    return s;
  }
}
