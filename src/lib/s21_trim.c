// Возвращает новую строку, в которой удаляются все начальные и конечные вхождения набора заданных символов (trim_chars) из данной строки (src). В случае какой-либо ошибки следует вернуть значение NULL 

#include <string.h>
#include "../s21_string.h"

void *trim(const char *src, const char *trim_chars) {
  printf("src = %s \t trim_chars = %s\n", src, trim_chars); 
  if (src == S21_NULL) return S21_NULL;
    else {
    

    // считаем лишние символы и удаляем trim_chars с начала строки:
    size_t i = 1, q = 0;
    for (; q < strlen(trim_chars); q++)
      while ((src[i] == trim_chars[q])) {
        i++;
      }

    //int count_i_left = i;
    char *s = calloc(strlen(src) + 1, sizeof(char));
    //s = "";
    printf("strlen(trim_chars) = %ld\tstrlen(src) = %ld\t i = %ld\t s = %s\n", strlen(trim_chars), strlen(src), i, s);

    size_t j = 0;

    for (int k = 0; j + i < strlen(src); j++, k++) {
        printf("s = %s\n", s);
        s[k] = src[j + i];
        printf("s = %s\n", s);
    }
    
    s[j] = '\0';
    printf("s1 = %s\n", s);

    // считаем лишние символы и удаляем trim_chars с конца строки:
    // printf("strlen(trim_chars) = %ld\n i = %ld\n", strlen(trim_chars), i);
    for (int count_i_right = j - 1, q=0; count_i_right >=0; count_i_right--)
      while (s[j] == trim_chars[q]) {
        j--;
        q++;        
      }
    s[j] = '\0';

    printf("s2 = %s\n", s);

    printf("\033[34m____next test____\n""\n\033[""39m");

    return s;
    }
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