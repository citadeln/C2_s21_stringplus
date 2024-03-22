#include "../s21_string.h"

// Возвращает новую строку, в которой удаляются все начальные и конечные
// вхождения набора заданных символов (trim_chars) из данной строки (src). В
// случае какой-либо ошибки следует вернуть значение NULL
int check_entrance(const char *src, const char *trim_chars, size_t i) {
  for (size_t q = 0; q < s21_strlen(trim_chars); q++)
    if (src[i] == trim_chars[q]) {
      i++;
      i = check_entrance(src, trim_chars, i);
    }
  return i;
}

int check_end(const char *s, const char *trim_chars, size_t j) {
  for (size_t q = 0; q < s21_strlen(trim_chars); q++) {
    if (s[j] == trim_chars[q]) {
      j--;
      j = check_end(s, trim_chars, j);
    }
  }
  return j;
}

void *s21_trim(const char *src, const char *trim_chars) {
  if (src == S21_NULL)
    return S21_NULL;
  else {
    char *s = calloc(s21_strlen(src) + 1, sizeof(char));

    if (trim_chars == S21_NULL)
      s21_strncpy(s, src, s21_strlen(src));

    else {
      // считаем лишние символы и удаляем trim_chars с начала строки:
      size_t i = check_entrance(src, trim_chars, 0);

      size_t j = 0;
      for (int k = 0; j + i < s21_strlen(src); j++, k++) s[k] = src[j + i];

      // указывает на последний символ (его порядковый номер в строке)
      size_t count_i_right = check_end(s, trim_chars, j - 1);

      s[count_i_right + 1] = '\0';
    }
    return s;
  }
}
