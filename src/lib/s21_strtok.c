#include "../s21_string.h"

/* Разбивает строку str на серию токенов, разделенных разделителем. */
char *s21_strtok(char *str, const char *delim) {
  static char
      *last;  // Используется для хранения позиции последнего найденного токена.
  char *token;  // Указатель на текущий токен.
  char *ref;    // Указатель для обхода строки.
  int is_initialized = 1;  // Флаг инициализации.

  // Если входная строка пуста и нет последнего найденного токена,
  // функция считается неинициализированной.
  if ((ref = str) == S21_NULL && (ref = last) == S21_NULL) {
    is_initialized = 0;
  }
  // Пропускаем начальные разделители.
  for (int i = 0; is_initialized && *ref && delim[i]; i++) {
    if (*ref == delim[i]) {
      ref++;
      i = -1;
    }
  }

  // Если достигнут конец строки, то все токены обработаны.
  if (is_initialized && *ref == '\0') {
    ref = S21_NULL;
    last = S21_NULL;
    is_initialized = 0;
  }
  token = ref;

  // Ищем следующий разделитель в строке.
  while (is_initialized && *ref) {
    for (size_t i = 0; delim[i]; i++) {
      if (*ref == delim[i]) {
        is_initialized = 0;
        // Заменяем разделитель на символ конца строки.
        *ref = '\0';
        ref++;

        if (*ref == '\0') {
          ref = S21_NULL;
        }
        last = ref;
        break;
      }
    }

    if (is_initialized) {
      ref++;

      if (*ref == '\0') {
        last = S21_NULL;
      }
    }
  }

  // Возвращаем найденный токен.
  return token;
}
