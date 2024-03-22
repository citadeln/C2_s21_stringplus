#include "../s21_string.h"

// Дополнительные функции

/* Копирует n байтов из SRC в DEST, гарантируя правильное поведение для
перекрывающихся строк.*/
void *s21_memmove(void *dest, const void *src, s21_size_t n) {
  const unsigned char *src_temp = (const unsigned char *)src;
  unsigned char *dest_temp = (unsigned char *)dest;
  for (s21_size_t i = 0; i < n; i++) {
    if (dest_temp[i] != '\0') {
      dest_temp[i] = src_temp[i];
    } else {
      break;
    }
  }
  return dest;
}

/*Kопирует строку, на которую указывает src (включая завершающий символ `\0'), в
массив, на который указывает dest. Строки не могут перекрываться, и в
результирующей строке dest должно быть достаточно места для копии.*/
char *s21_strcpy(char *dest, const char *src) {
  int i = 0;
  while (src[i] != '\0') {
    dest[i] = src[i];
    i++;
  }
  dest[i] = '\0';
  return dest;
}

/*Добавляет строку str к строке dest, перезаписывая символ `\0' в конце dest и
добавляя к строке символ окончания `\0'.  Строки не могут перекрываться, а в
строке dest должно хватать свободного места для размещения объединенных строк.*/
char *s21_strcat(char *dest, const char *src) {
  char *tmp = dest;
  s21_size_t i = 0;

  while (*tmp != '\0') tmp++;  // Move the pointer to the end of dest
  while (src[i] != '\0') {
    *tmp++ = src[i];
    i++;
  }
  *tmp = '\0';  // Null terminate dest

  return dest;
}

// Преобразует строку в нижний регистр.
void *s21_to_lower(const char *str) {
  int i = 0;
  if (str == S21_NULL) return S21_NULL;
  s21_size_t length = s21_strlen(str);
  char *copy = malloc(length + 1);
  while (str[i] != '\0') {
    if (str[i] >= 'A' && str[i] <= 'Z')
      copy[i] = str[i] + ('a' - 'A');
    else
      copy[i] = str[i];
    i++;
  }
  copy[length] = '\0';
  return copy;
}

// Преобразует строку в верхний регистр.
void *s21_to_upper(const char *str) {
  int i = 0;
  if (str == S21_NULL) return S21_NULL;
  s21_size_t length = s21_strlen(str);
  char *copy = malloc(length + 1);
  while (str[i] != '\0') {
    if (str[i] >= 'a' && str[i] <= 'z')
      copy[i] = str[i] + ('A' - 'a');
    else
      copy[i] = str[i];
    i++;
  }
  copy[length] = '\0';
  return copy;
}

/* Сравнивает две строки: s1 и s2. Она возвращает целое число, которое меньше,
больше нуля или равно ему, если s1 соответственно меньше, больше или равно
s2.*/
int s21_strcmp(const char *str1, const char *str2) {
  int f = 0;
  int len = s21_strlen(str1);
  int len2 = s21_strlen(str2);
  if (len2 > len) len = len2;
  for (int i = 0; i < len; ++i) {
    if (*(str1 + i) > *(str2 + i)) {
      f = *(str1 + i) - *(str2 + i);
      break;
    } else if (*(str1 + i) < *(str2 + i)) {
      // f = -1;
      f = *(str1 + i) - *(str2 + i);
      break;
    }
  }
  return f;
}

//Вставляет строку str в строку src, начиная с индекса start_index
void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  if (src == S21_NULL || str == S21_NULL) {
    return S21_NULL;
  }

  if (start_index > s21_strlen(src)) {
    return S21_NULL;
  }

  char *result = malloc(s21_strlen(src) + s21_strlen(str) + 1);

  if (!result) {
    return S21_NULL;
  }

  s21_strncpy(result, src, start_index);  // "Hello"
  result[start_index] = '\0';
  s21_strcat(result, str);  // "Hello Biba"
  s21_strcat(result, src + start_index);

  return (void *)result;
}
