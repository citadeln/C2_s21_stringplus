#include <check.h>

#include "./../s21_string.h"
#include "s21_tests.h"

START_TEST(test_trim_1) {
  // arrange
  char s1[30] = "-?hello, world!";
  char s2[] = "!?-";
  char need_result[] = "hello, world";
  
  // act
  char *result = trim(s1, s2);
  
  // assert
  ck_assert_pstr_eq(need_result, result);
  if (result) free(result);
}
END_TEST

START_TEST(test_trim_2) {
  // arrange
  char s1[30] = "";
  char s2[] = "";
  char *need_result = "";
  
  // act
  char *result = trim(s1, s2);
  
  // assert
  ck_assert_pstr_eq(need_result, result);
  if (result) free(result);
}
END_TEST

START_TEST(test_trim_3) {
  // arrange
  char *s1 = S21_NULL;
  char s2[] = "";
  char *need_result = S21_NULL;
  
  // act
  char *result = trim(s1, s2);
  
  // assert
  ck_assert_pstr_eq(need_result, result);
  if (result) free(result);
}
END_TEST

START_TEST(test_trim_4) {
  // arrange
  char s1[30] = "!!!abcdefghij!?!";
  char s2[] = "!?";
  char need_result[] = "abcdefghij";
  
  // act
  char *result = trim(s1, s2);
  
  // assert
  ck_assert_pstr_eq(need_result, result);
  if (result) free(result);
}
END_TEST

START_TEST(test_trim_5) {
  // arrange
  char s1[30] = "abc";
  char s2[] = "333";
  char *need_result = "abc";
  
  // act
  char *result = trim(s1, s2);
  
  // assert
  ck_assert_pstr_eq(need_result, result);
  if (result) free(result);
}
END_TEST

START_TEST(test_trim_6) {
  // arrange
  char s1[30] = "hello, world!";
  char s2[] = "?!";
  char *need_result = "hello, world";
  
  // act
  char *result = trim(s1, s2);
  
  // assert
  ck_assert_pstr_eq(need_result, result);
  if (result) free(result);
}
END_TEST

START_TEST(test_trim_7) {
  // arrange
  char *s1 = S21_NULL;
  char *s2 = S21_NULL;
  char *need_result = S21_NULL;
  
  // act
  char *result = trim(s1, s2);
  
  // assert
  ck_assert_pstr_eq(need_result, result);
  if (result) free(result);
}
END_TEST

START_TEST(test_trim_8) {
  // arrange
  char s1[30] = "";
  char s2[] = "";
  char need_result[] = "";
  
  // act
  char *result = trim(s1, s2);
  
  // assert
  ck_assert_pstr_eq(need_result, result);
  if (result) free(result);
}
END_TEST

START_TEST(test_trim_9) {
  // arrange
  char s1[] = " fufu ";
  char *s2 = S21_NULL;
  char *need_result = " fufu ";
  
  // act
  char *result = trim(s1, s2);
  
  // assert
  ck_assert_pstr_eq(need_result, result);
  if (result) free(result);
}
END_TEST

START_TEST(test_trim_10) {
  // arrange
  char s1[] = " fufu ";
  char *s2 = "";
  char *need_result = " fufu ";
  
  // act
  char *result = trim(s1, s2);
  
  // assert
  ck_assert_pstr_eq(need_result, result);  
  if (result) free(result);
}
END_TEST

Suite *trim_sc(void) {
  Suite *suite = suite_create("s21_trim");
  TCase *tc = tcase_create("s21_trim tests");

  tcase_add_test(tc, test_trim_1);
  tcase_add_test(tc, test_trim_2);
  tcase_add_test(tc, test_trim_3);
  tcase_add_test(tc, test_trim_4);
  tcase_add_test(tc, test_trim_5);
  tcase_add_test(tc, test_trim_6);
  tcase_add_test(tc, test_trim_7);
  tcase_add_test(tc, test_trim_8);
  tcase_add_test(tc, test_trim_9);
  tcase_add_test(tc, test_trim_10);

  suite_add_tcase(suite, tc);

  return suite;
}

MAKE_TEST(trim)
