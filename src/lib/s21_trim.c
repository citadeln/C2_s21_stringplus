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

void *trim(const char *src, const char *trim_chars) {
  printf("src = %s \t trim_chars = %s\n", src, trim_chars);
  if (src == S21_NULL)
    return S21_NULL;
  else {
    // считаем лишние символы и удаляем trim_chars с начала строки:
    size_t i = check_entrance(src, trim_chars, 0);
    char *s = calloc(strlen(src) + 1, sizeof(char));
    // s = "";
    printf("strlen(trim_chars) = %ld\tstrlen(src) = %ld\t i = %ld\t s = %s\n",
           strlen(trim_chars), strlen(src), i, s);

    size_t j = 0;
    for (int k = 0; j + i < strlen(src); j++, k++) {
      // printf("s = %s\n", s);
      s[k] = src[j + i];
      // printf("s = %s\n", s);
    }

    s[j] = '\0';
    printf("i = %ld\t j = %ld\ts = %s\n", i, j, s);
    // считаем лишние символы и удаляем trim_chars с конца строки:
    int count_i_right = j - 1;
    for (int q=0; count_i_right >=0; count_i_right--)
      while (s[count_i_right] == trim_chars[q]) {
        count_i_right--;
        for (size_t q = 0; q < strlen(trim_chars); q++)
          if (s[count_i_right] == trim_chars[q])
            count_i_right--;
      }
    
    printf("i = %ld\t j = %ld\ts = %s\n", i, j, s);

    s[count_i_right - i] = '\0';

    printf("s2 = %s\n", s);

    printf(
        "\033[34m____next test____\n"
        "\n\033["
        "39m");

    return s;
  }
}
