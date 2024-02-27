#include <string.h>
#include "../s21_string.h"

int s21_sscanf(const char *str, const char *format, ...) {

//определить тип по форматной строке
/*
%
флаг +-пробел#0
ширина цифра
точность (перед ней точка)
длинна (hlL)
спецификатор (s )
*/

while (f) {
    if (f == '%')
    //создать структуру Token
    else f++;
}

// обработка str
/*
пример №1
"Hello w123"
"%6s%c%d"
*/
char *s = (char)str; //указатель на строку, которую берем в обработку

/*
пример №2
char *a;
char b;
int c;
sscanf("Hello w 123", "%*s%c%*d", 6, a, &b, 2, &c);
va_arg(переменная, int);
*/

s = IntVar(Token, s, va_list);

char* InitVar (Token T, char* s, va_list Arg) { // инициализирует переменную и смещает курсор 
    switch(T.spec)
        case "b": B //вызов функции, которая будет работать с этой переменной
        case "i": B //тоже самое что и b
        ...12 шт...
}

va_list Ar, // переменные, которые стоят после format в sscanf

char* B(char *s, Token T, va_list Ar) {
    char mass[256]; 
    \0
/*
пример №3
"1234.56a"
"%6s%c%d"
флаг = -1
ширина = 2  (читаем до постороннего символа кроме 0-9 из аски)
точность = -1
длинна = 2
spec = 'b'
*/

mass = *s;

//сдвигаем указатель
s++

ato; //возвращает int
atol //возвращает long 
atoll //возвращает long long

atos short
stod // перевод строки в доубл
stof //.. флоат
stold //.. лонг доубл

Итого по примеру №3 получилось mass = "12\0" (так как ширина 2)

}

}