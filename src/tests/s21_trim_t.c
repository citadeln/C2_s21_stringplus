#include "s21_tests.h"

START_TEST(test_trim_1) {
  // arrange
  char s1[30] = "-?hello, world!";
  char s2[] = "!?-";
  char need_result[] = "hello, world";

  // act
  char *result = s21_trim(s1, s2);

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
  char *result = s21_trim(s1, s2);

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
  char *result = s21_trim(s1, s2);

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
  char *result = s21_trim(s1, s2);

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
  char *result = s21_trim(s1, s2);

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
  char *result = s21_trim(s1, s2);

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
  char *result = s21_trim(s1, s2);

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
  char *result = s21_trim(s1, s2);

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
  char *result = s21_trim(s1, s2);

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
  char *result = s21_trim(s1, s2);

  // assert
  ck_assert_pstr_eq(need_result, result);
  if (result) free(result);
}
END_TEST

START_TEST(t1) {
  // arrange
  char s1[] = "test123.=+-{}";
  char *s2 = ".=+-{}";
  char *need_result = "test123";

  // act
  char *result = s21_trim(s1, s2);

  // assert
  ck_assert_pstr_eq(need_result, result);
  if (result) free(result);
}
END_TEST

START_TEST(t2) {
  char s1[] = "=+-test123.=+-{}";
  char *s2 = ".=+-{}";
  char *need_result = "test123";

  // act
  char *result = s21_trim(s1, s2);

  // assert
  ck_assert_pstr_eq(need_result, result);
  if (result) free(result);
}
END_TEST
START_TEST(t3) {
  char s1[] = "=+-test123";
  char *s2 = ".=+-{}";
  char *need_result = "test123";

  // act
  char *result = s21_trim(s1, s2);

  // assert
  ck_assert_pstr_eq(need_result, result);
  if (result) free(result);
}
END_TEST
// START_TEST(t4) {
//   char s1[] = ".=+-{}.=+-{}.=+-{}";
//   char *s2 = ".=+-{}";
//   char *need_result = "";

//   // act
//   char *result = s21_trim(s1, s2);

//   // assert
//   ck_assert_pstr_eq(need_result, result);
//   if (result) free(result);
// }
// END_TEST
START_TEST(t5) {
  char s1[] = "test123456.=+-{}";
  s1[10] = '\0';
  char *s2 = ".=+-{}";
  char *need_result = "test123456";

  // act
  char *result = s21_trim(s1, s2);

  // assert
  ck_assert_pstr_eq(need_result, result);
  if (result) free(result);
}
END_TEST
// START_TEST(t6) {
//   char s1[] = "";
//   char *s2 = ".=+-{}";
//   char *need_result = "";

//   // act
//   char *result = s21_trim(s1, s2);

//   // assert
//   ck_assert_pstr_eq(need_result, result);
//   if (result) free(result);
// }
// END_TEST
START_TEST(t7) {
  char s1[] = "";
  char *s2 = "";
  char *need_result = "";

  // act
  char *result = s21_trim(s1, s2);

  // assert
  ck_assert_pstr_eq(need_result, result);
  if (result) free(result);
}
END_TEST
START_TEST(t8) {
  char s1[] = " wtf ";
  char *s2 = S21_NULL;
  char *need_result = " wtf ";

  // act
  char *result = s21_trim(s1, s2);

  // assert
  ck_assert_pstr_eq(need_result, result);
  if (result) free(result);
}
END_TEST
START_TEST(t9) {
  char *s1 = S21_NULL;
  char *s2 = S21_NULL;
  char *need_result = S21_NULL;

  // act
  char *result = s21_trim(s1, s2);

  // assert
  ck_assert_pstr_eq(need_result, result);
  if (result) free(result);
}
END_TEST

START_TEST(t10) {
  char *s1 = S21_NULL;
  char *s2 = "";
  char *need_result = S21_NULL;

  // act
  char *result = s21_trim(s1, s2);

  // assert
  ck_assert_pstr_eq(need_result, result);
  if (result) free(result);
}
END_TEST

Suite *s21_test_trim(void) {
  Suite *s = suite_create("\033[45m-=S21_TRIM=-\033[0m");
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
  tcase_add_test(tc, t1);
  tcase_add_test(tc, t2);
  tcase_add_test(tc, t3);
  // tcase_add_test(tc, t4);
  tcase_add_test(tc, t5);
  // tcase_add_test(tc, t6);
  tcase_add_test(tc, t7);
  tcase_add_test(tc, t8);
  tcase_add_test(tc, t9);
  tcase_add_test(tc, t10);

  suite_add_tcase(s, tc);

  return s;
}
