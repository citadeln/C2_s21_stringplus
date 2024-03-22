//#define _POSIX_C_SOURCE 200809L
#include <float.h>
#include <math.h>
#include <stdarg.h>  // предоставляющий средства для перебора аргументов
// функции, количество и типы которых заранее не известны
#include <ctype.h>   // для sscanf
#include <stdarg.h>  // для sscanf
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
//#include <limits.h> // для sscanf (LONG_MAX 9223372036854775807)

typedef struct {
  bool minus;
  bool plus;
  bool space;
  bool zero;
  bool hash;
  int accuracy;
  int is_accuracy_set;
  int width;
  char length;
  char specifier;
} flags;

typedef struct {
  int star;
  int weight;
  char lenght;
  char d_lenght;
  char spec;
  int n;
  char *str;
  short int over;
  short int finish;
  int n_count;
  int some_read;
} specifier;  //для сканеф

#define S21_ISNAN(x) ((x) != (x))
#define S21_INF_POS (DBL_MAX + DBL_MAX)
#define S21_INF_NEG (-S21_INF_POS)
#define S21_IS_INFINITY(x) ((x) == S21_INF_POS || (x) == S21_INF_NEG)

#define SIZE (512)

// для sscanf
#define S21_NAN (-(0.0 / 0.0))
#define SPEC_LIST "gGeExXopcdfsui%%n"
#define LEN_LIST "hlL"
#define S21_LONG_MAX 9223372036854775807
//#define INT_MIN -9223372036854775808

#ifndef S21_STRING_H
#define S21_STRING_H

#define S21_NULL ((void *)0)

typedef unsigned long s21_size_t;

//Вспомогательные функции для sprintf()

// Helpers
int s21_isdigit(char c);
int s21_atoi(const char *str);

// Convert
void num_to_string(int64_t value, char *ret, int base);
void unsigned_num_to_string(uint64_t value, char *ret, int base);
bool is_integer_specifier(char c);
bool is_all_zeroes(char *buff);
void prepend_ox_specs(char *buff, flags f);
void double_to_string(long double value, char *ret, flags f);
void prepend_exp_symbols(char *str, int pow, char sign);
void remove_trail_zeroes(char *buff);

// Set some flags
const char *set_flags(const char *format, flags *f);
const char *set_width(const char *format, flags *f, va_list va);
const char *set_accuracy(const char *format, flags *f, va_list va);
const char *set_length(const char *format, flags *f);

// Parse some specifieres
void parse_specs(flags f, char *buff, va_list va);
void parse_integer(flags, char *buff, va_list va);
void parse_unsigned(flags f, char *buff, va_list va);
void parse_octal(flags f, char *buff, va_list va);
void parse_hexadecimal(flags f, char *buff, va_list va);
void parse_character(flags f, char *buff, va_list va);
void parse_string(flags f, char *buff, va_list va);
void parse_pointer(flags f, char *buff, va_list va);
void parse_float(flags f, char *buff, va_list va);
void parse_exp_spec(flags f, char *buff, va_list va);
void parse_general_float(flags f, char *buff, va_list va);

// Format witch flags (space, plus, zero)
void format_accuracy(char *buff, flags f);
void format_flags(char *buff, flags f);
void format_general_accuracy(char *buff, int accuracy);
void format_wchar(flags f, char *buff, wchar_t w_c);
void format_char(flags f, char *buff, char c);
void format_string(flags f, char *buff, char *str);
void format_wide_string(flags f, char *buff, wchar_t *wstr);

void to_upper(char *str);

// основные функции
void *s21_memchr(const void *str, int c, s21_size_t n);
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
void *s21_memset(void *str, int c, s21_size_t n);
char *s21_strncat(char *dest, const char *src, s21_size_t n);
char *s21_strchr(const char *str, int c);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
s21_size_t s21_strcspn(const char *str1, const char *str2);
char *s21_strerror(int errnum);
s21_size_t s21_strlen(const char *str);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strrchr(const char *str, int c);
char *s21_strstr(const char *haystack, const char *needle);
char *s21_strtok(char *str, const char *delim);
int s21_sprintf(char *str, const char *format, ...);

// Дополнительные функции

void *s21_memmove(void *dest, const void *src, s21_size_t n);
char *s21_strcpy(char *dest, const char *src);
char *s21_strcat(char *dest, const char *src);
int s21_strcmp(const char *str1, const char *str2);
void *s21_to_upper(const char *str);
void *s21_to_lower(const char *str);
void *s21_insert(const char *src, const char *str, s21_size_t start_index);
void *s21_trim(const char *src, const char *trim_chars);

// Для sscanf
int s21_sscanf(const char *str, const char *format, ...);
const char *parsing(const char *format, specifier *spec);
int write_var(specifier *spec, const char *str, va_list ap, const char *start);
int setS(specifier *spec, const char *str, va_list ap);
int setC(specifier *spec, const char *str, va_list ap);
int setD(specifier *spec, const char *str, va_list ap, int minus);
int setI(specifier *spec, const char *str, va_list ap);
int setE(specifier *spec, const char *str, va_list ap);
int setO(specifier *spec, const char *str, va_list ap, int minus);
int setX(specifier *spec, const char *str, va_list ap, int minus);
int setN(specifier *spec, const char *str, va_list ap);
void spec_zero(specifier *spec);

#endif  // S21_STRING_H
