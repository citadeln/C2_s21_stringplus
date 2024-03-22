#include "s21_tests.h"

START_TEST(all_std_errors) {
  for (int i = 0; i < 134; i++) {
    char *got = s21_strerror(i);
    char *expected = strerror(i);
    ck_assert_str_eq(got, expected);
  }
}
END_TEST

START_TEST(negative_err_code) {
  const char *got = s21_strerror(135);
  char *expected = strerror(135);
  ck_assert_str_eq(got, expected);
  free(expected);
}
END_TEST

Suite *s21_test_strerror(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("\033[45m-=S21_STRERROR=-\033[0m");
  tc = tcase_create("strerror_tc");

  tcase_add_test(tc, all_std_errors);
  tcase_add_test(tc, negative_err_code);

  suite_add_tcase(s, tc);
  return s;
}
