#ifndef SRC_TESTS_ME_H
#define SRC_TESTS_ME_H
#define _POSIX_C_SOURCE 200809L

#include <check.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

#include "../s21_string.h"

Suite *s21_test_memchr(void);
Suite *s21_test_memcmp(void);
Suite *s21_test_memcpy(void);
Suite *s21_test_memmove(void);
Suite *s21_test_memset(void);
Suite *s21_test_strcat(void);
Suite *s21_test_strncat(void);
Suite *s21_test_strchr(void);
Suite *s21_test_strcmp(void);
Suite *s21_test_strncmp(void);
Suite *s21_test_strcpy(void);
Suite *s21_test_strncpy(void);
Suite *s21_test_strcspn(void);
Suite *s21_test_strerror(void);
Suite *s21_test_strlen(void);
Suite *s21_test_strpbrk(void);
Suite *s21_test_strrchr(void);
Suite *s21_test_strstr(void);
Suite *s21_test_strtok(void);
Suite *s21_test_sprintf(void);
Suite *s21_test_to_upper(void);
Suite *s21_test_to_lower(void);
Suite *s21_test_insert(void);
Suite *s21_test_trim(void);
Suite *s21_test_sscanf_c(void);
Suite *s21_test_sscanf_d(void);
Suite *s21_test_sscanf_empty(void);
Suite *s21_test_sscanf_i(void);
Suite *s21_test_sscanf_n(void);
Suite *s21_test_sscanf_o(void);
Suite *s21_test_sscanf_p(void);
Suite *s21_test_sscanf_real(void);
Suite *s21_test_sscanf_x(void);

#endif  // S21_TESTS_H
