#include "s21_calc_test.h"

START_TEST(test_smart_calc_1) {
  char *string =
      "15.0/(7.0-(1.0+1.0))*3.0-(2.0+(1.0+1.0))*15.0/"
      "(7.0-(200.0+1.0))*3.0-(2.0+(1.0+1.0))\0";
  double result = 15.0 / (7.0 - (1.0 + 1.0)) * 3.0 -
                  (2.0 + (1.0 + 1.0)) * 15.0 / (7.0 - (200.0 + 1.0)) * 3.0 -
                  (2.0 + (1.0 + 1.0));
  node_calc *dst = NULL;
  node_calc *src = NULL;
  node_calc *res = NULL;
  int error = 0;
  int check = 0;
  check = s21_check_string(string);
  if (check == 0) {
  }
  s21_stack_maker(string, &dst);

  double resultMY = s21_calc(&dst, &res, src, 0, 0, &error);
  freeList(&dst);
  freeList(&src);
  freeList(&res);
  ck_assert_double_eq(resultMY, result);
}
END_TEST

START_TEST(addition_1) {
  char string[256] = {"(1+(1*(4*(5*4+(3*2*1.1/(3*sin(2*cos(1235.3)*2)))))))"};

  double result =
      (1 +
       (1 * (4 * (5 * 4 + (3 * 2 * 1.1 / (3 * sin(2 * cos(1235.3) * 2)))))));
  node_calc *dst = NULL;
  node_calc *src = NULL;
  node_calc *res = NULL;
  int error = 0;
  int check = 0;
  check = s21_check_string(string);
  if (check == 0) {
    s21_stack_maker(string, &dst);
  }

  double resultMY = s21_calc(&dst, &res, src, 0, 0, &error);
  freeList(&dst);
  freeList(&src);
  freeList(&res);
  ck_assert_double_eq(resultMY, result);
}
END_TEST

START_TEST(addition_2) {
  char string[256] = {"21*cos(123)-100"};
  double result = 21 * cos(123) - 100;
  node_calc *dst = NULL;
  node_calc *src = NULL;
  node_calc *res = NULL;
  int error = 0;
  int check = 0;
  check = s21_check_string(string);
  if (check == 0) {
    s21_stack_maker(string, &dst);
  }

  double resultMY = s21_calc(&dst, &res, src, 0, 0, &error);
  freeList(&dst);
  freeList(&src);
  freeList(&res);
  ck_assert_double_eq(resultMY, result);
}
END_TEST

START_TEST(subtraction_4) {
  char string[256] = {"999-99-500-25-75-200-93-7-499"};
  double result = 999 - 99 - 500 - 25 - 75 - 200 - 93 - 7 - 499;
  node_calc *dst = NULL;
  node_calc *src = NULL;
  node_calc *res = NULL;
  int error = 0;
  int check = 0;
  check = s21_check_string(string);
  if (check == 0) {
    s21_stack_maker(string, &dst);
  }

  double resultMY = s21_calc(&dst, &res, src, 0, 0, &error);
  freeList(&dst);
  freeList(&src);
  freeList(&res);
  ck_assert_double_eq(resultMY, result);
}
END_TEST

START_TEST(subtraction_5) {
  char string[256] = {"999-99-500+25-75-200+93-7-499"};
  double result = 999 - 99 - 500 + 25 - 75 - 200 + 93 - 7 - 499;
  node_calc *dst = NULL;
  node_calc *src = NULL;
  node_calc *res = NULL;
  int error = 0;
  int check = 0;
  check = s21_check_string(string);
  if (check == 0) {
    s21_stack_maker(string, &dst);
  }

  double resultMY = s21_calc(&dst, &res, src, 0, 0, &error);
  freeList(&dst);
  freeList(&src);
  freeList(&res);
  ck_assert_double_eq(resultMY, result);
}
END_TEST

START_TEST(multiplication_4) {
  char string[256] = {"2*2*2*8"};
  double result = 2 * 2 * 2 * 8;
  node_calc *dst = NULL;
  node_calc *src = NULL;
  node_calc *res = NULL;
  int error = 0;
  int check = 0;
  check = s21_check_string(string);
  if (check == 0) {
    s21_stack_maker(string, &dst);
  }

  double resultMY = s21_calc(&dst, &res, src, 0, 0, &error);
  freeList(&dst);
  freeList(&src);
  freeList(&res);
  ck_assert_double_eq(resultMY, result);
}
END_TEST

START_TEST(multiplication_5) {
  char string[256] = {"-7*6"};
  double result = -7 * 6;
  node_calc *dst = NULL;
  node_calc *src = NULL;
  node_calc *res = NULL;
  int error = 0;
  int check = 0;
  check = s21_check_string(string);
  if (check == 0) {
    s21_stack_maker(string, &dst);
  }

  double resultMY = s21_calc(&dst, &res, src, 0, 0, &error);
  freeList(&dst);
  freeList(&src);
  freeList(&res);
  ck_assert_double_eq(resultMY, result);
}
END_TEST

START_TEST(division_4) {
  char string[256] = {"100/2/2/5/5"};
  double result = 100 / 2 / 2 / 5 / 5;
  node_calc *dst = NULL;
  node_calc *src = NULL;
  node_calc *res = NULL;
  int error = 0;
  int check = 0;
  check = s21_check_string(string);
  if (check == 0) {
    s21_stack_maker(string, &dst);
  }

  double resultMY = s21_calc(&dst, &res, src, 0, 0, &error);
  freeList(&dst);
  freeList(&src);
  freeList(&res);
  ck_assert_double_eq(resultMY, result);
}
END_TEST

START_TEST(division_5) {
  char string[256] = {"-999/9"};
  double result = -999 / 9;
  node_calc *dst = NULL;
  node_calc *src = NULL;
  node_calc *res = NULL;
  int error = 0;
  int check = 0;
  check = s21_check_string(string);
  if (check == 0) {
    s21_stack_maker(string, &dst);
  }

  double resultMY = s21_calc(&dst, &res, src, 0, 0, &error);
  freeList(&dst);
  freeList(&src);
  freeList(&res);
  ck_assert_double_eq(resultMY, result);
}
END_TEST

START_TEST(power_1) {
  char string[256] = {"10^2"};
  double result = powl(10, 2);
  node_calc *dst = NULL;
  node_calc *src = NULL;
  node_calc *res = NULL;
  int error = 0;
  int check = 0;
  check = s21_check_string(string);
  if (check == 0) {
    s21_stack_maker(string, &dst);
  }

  double resultMY = s21_calc(&dst, &res, src, 0, 0, &error);
  freeList(&dst);
  freeList(&src);
  freeList(&res);
  ck_assert_double_eq(resultMY, result);
}
END_TEST

START_TEST(power_2) {
  char string[256] = {"1^43"};
  double result = powl(1, 43);
  node_calc *dst = NULL;
  node_calc *src = NULL;
  node_calc *res = NULL;
  int error = 0;
  int check = 0;
  check = s21_check_string(string);
  if (check == 0) {
    s21_stack_maker(string, &dst);
  }

  double resultMY = s21_calc(&dst, &res, src, 0, 0, &error);
  freeList(&dst);
  freeList(&src);
  freeList(&res);
  ck_assert_double_eq(resultMY, result);
}
END_TEST

START_TEST(power_3) {
  char string[256] = {"3^2"};
  double result = powl(3, 2);
  node_calc *dst = NULL;
  node_calc *src = NULL;
  node_calc *res = NULL;
  int error = 0;
  int check = 0;
  check = s21_check_string(string);
  if (check == 0) {
    s21_stack_maker(string, &dst);
  }

  double resultMY = s21_calc(&dst, &res, src, 0, 0, &error);
  freeList(&dst);
  freeList(&src);
  freeList(&res);
  ck_assert_double_eq(resultMY, result);
}
END_TEST

START_TEST(power_4) {
  char string[256] = {"0^0"};
  double result = powl(0, 0);
  node_calc *dst = NULL;
  node_calc *src = NULL;
  node_calc *res = NULL;
  int error = 0;
  int check = 0;
  check = s21_check_string(string);
  if (check == 0) {
    s21_stack_maker(string, &dst);
  }

  double resultMY = s21_calc(&dst, &res, src, 0, 0, &error);
  freeList(&dst);
  freeList(&src);
  freeList(&res);
  ck_assert_double_eq(resultMY, result);
}
END_TEST

START_TEST(power_5) {
  char string[256] = {"-1^3"};
  double result = powl(-1, 3);
  node_calc *dst = NULL;
  node_calc *src = NULL;
  node_calc *res = NULL;
  int error = 0;
  int check = 0;
  check = s21_check_string(string);
  if (check == 0) {
    s21_stack_maker(string, &dst);
  }

  double resultMY = s21_calc(&dst, &res, src, 0, 0, &error);
  freeList(&dst);
  freeList(&src);
  freeList(&res);
  ck_assert_double_eq(resultMY, result);
}
END_TEST

START_TEST(mix_1) {
  char string[256] = {"(1+2)*3+5*4"};

  double result = (1 + 2) * 3 + 5 * 4;
  node_calc *dst = NULL;
  node_calc *src = NULL;
  node_calc *res = NULL;
  int error = 0;
  int check = 0;
  check = s21_check_string(string);
  if (check == 0) {
    s21_stack_maker(string, &dst);
  }

  double resultMY = s21_calc(&dst, &res, src, 0, 0, &error);
  freeList(&dst);
  freeList(&src);
  freeList(&res);
  ck_assert_double_eq(resultMY, result);
}
END_TEST

START_TEST(cosin_1) {
  char string[256] = {"sin(1+3)"};

  double result = sin(1 + 3);
  node_calc *dst = NULL;
  node_calc *src = NULL;
  node_calc *res = NULL;
  int error = 0;
  int check = 0;
  check = s21_check_string(string);
  if (check == 0) {
    s21_stack_maker(string, &dst);
  }

  double resultMY = s21_calc(&dst, &res, src, 0, 0, &error);
  freeList(&dst);
  freeList(&src);
  freeList(&res);
  ck_assert_double_eq(resultMY, result);
}
END_TEST

START_TEST(cosin_2) {
  char string[256] = {"cos(1+3)"};

  double result = cos(1 + 3);
  node_calc *dst = NULL;
  node_calc *src = NULL;
  node_calc *res = NULL;
  int error = 0;
  int check = 0;
  check = s21_check_string(string);
  if (check == 0) {
    s21_stack_maker(string, &dst);
  }

  double resultMY = s21_calc(&dst, &res, src, 0, 0, &error);
  freeList(&dst);
  freeList(&src);
  freeList(&res);
  ck_assert_double_eq(resultMY, result);
}
END_TEST

START_TEST(cosin_3) {
  char string[256] = {"tan(1+3)"};

  double result = tan(1 + 3);
  node_calc *dst = NULL;
  node_calc *src = NULL;
  node_calc *res = NULL;
  int error = 0;
  int check = 0;
  check = s21_check_string(string);
  if (check == 0) {
    s21_stack_maker(string, &dst);
  }

  double resultMY = s21_calc(&dst, &res, src, 0, 0, &error);
  freeList(&dst);
  freeList(&src);
  freeList(&res);
  ck_assert_double_eq(resultMY, result);
}
END_TEST

START_TEST(cosin_4) {
  char string[256] = {"asin(0.5)"};

  double result = asin(0.5);
  node_calc *dst = NULL;
  node_calc *src = NULL;
  node_calc *res = NULL;
  int error = 0;
  int check = 0;
  check = s21_check_string(string);
  if (check == 0) {
    s21_stack_maker(string, &dst);
  }

  double resultMY = s21_calc(&dst, &res, src, 0, 0, &error);
  freeList(&dst);
  freeList(&src);
  freeList(&res);
  ck_assert_double_eq(resultMY, result);
}
END_TEST

START_TEST(cosin_5) {
  char string[256] = {"acos(0.5)"};

  double result = acos(0.5);
  node_calc *dst = NULL;
  node_calc *src = NULL;
  node_calc *res = NULL;
  int error = 0;
  int check = 0;
  check = s21_check_string(string);
  if (check == 0) {
    s21_stack_maker(string, &dst);
  }

  double resultMY = s21_calc(&dst, &res, src, 0, 0, &error);
  freeList(&dst);
  freeList(&src);
  freeList(&res);
  ck_assert_double_eq(resultMY, result);
}
END_TEST

START_TEST(cosin_6) {
  char string[256] = {"atan(1+3)"};

  double result = atan(1 + 3);
  node_calc *dst = NULL;
  node_calc *src = NULL;
  node_calc *res = NULL;
  int error = 0;
  int check = 0;
  check = s21_check_string(string);
  if (check == 0) {
    s21_stack_maker(string, &dst);
  }

  double resultMY = s21_calc(&dst, &res, src, 0, 0, &error);
  freeList(&dst);
  freeList(&src);
  freeList(&res);
  ck_assert_double_eq(resultMY, result);
}
END_TEST

START_TEST(cosin_7) {
  char string[256] = {"ln(1+3)"};

  double result = log(1 + 3);
  node_calc *dst = NULL;
  node_calc *src = NULL;
  node_calc *res = NULL;
  int error = 0;
  int check = 0;
  check = s21_check_string(string);
  if (check == 0) {
    s21_stack_maker(string, &dst);
  }

  double resultMY = s21_calc(&dst, &res, src, 0, 0, &error);
  freeList(&dst);
  freeList(&src);
  freeList(&res);
  ck_assert_double_eq(resultMY, result);
}
END_TEST

START_TEST(cosin_8) {
  char string[256] = {"log(1+3)"};

  double result = log10(1 + 3);
  node_calc *dst = NULL;
  node_calc *src = NULL;
  node_calc *res = NULL;
  int error = 0;
  int check = 0;
  check = s21_check_string(string);
  if (check == 0) {
    s21_stack_maker(string, &dst);
  }

  double resultMY = s21_calc(&dst, &res, src, 0, 0, &error);
  freeList(&dst);
  freeList(&src);
  freeList(&res);
  ck_assert_double_eq(resultMY, result);
}
END_TEST

START_TEST(cosin_9) {
  char string[256] = {"1^3"};

  double result = pow(1, 3);
  node_calc *dst = NULL;
  node_calc *src = NULL;
  node_calc *res = NULL;
  int error = 0;
  int check = 0;
  check = s21_check_string(string);
  if (check == 0) {
    s21_stack_maker(string, &dst);
  }

  double resultMY = s21_calc(&dst, &res, src, 0, 0, &error);
  freeList(&dst);
  freeList(&src);
  freeList(&res);
  ck_assert_double_eq(resultMY, result);
}
END_TEST

START_TEST(cosin_10) {
  char string[256] = {"4mod2"};

  double result = fmod(4, 2);
  node_calc *dst = NULL;
  node_calc *src = NULL;
  node_calc *res = NULL;
  int error = 0;
  int check = 0;
  check = s21_check_string(string);
  if (check == 0) {
    s21_stack_maker(string, &dst);
  }

  double resultMY = s21_calc(&dst, &res, src, 0, 0, &error);
  freeList(&dst);
  freeList(&src);
  freeList(&res);
  ck_assert_double_eq(resultMY, result);
}
END_TEST

START_TEST(cosin_11) {
  char string[256] = {"sqrt(4)"};

  double result = sqrt(4);
  node_calc *dst = NULL;
  node_calc *src = NULL;
  node_calc *res = NULL;
  int error = 0;
  int check = 0;
  check = s21_check_string(string);
  if (check == 0) {
    s21_stack_maker(string, &dst);
  }

  double resultMY = s21_calc(&dst, &res, src, 0, 0, &error);
  freeList(&dst);
  freeList(&src);
  freeList(&res);
  ck_assert_double_eq(resultMY, result);
}
END_TEST

START_TEST(x_1) {
  char string[256] = {"x+2"};

  node_calc *dst = NULL;
  node_calc *src = NULL;
  node_calc *res = NULL;
  int check = 0;
  int error = 0;
  check = s21_check_string(string);
  if (check == 0) {
    check = s21_stack_maker(string, &dst);
    s21_calc(&dst, &res, src, 0, 0, &error);
  }

  ck_assert_double_eq(check, 1);
}
END_TEST

START_TEST(x_2) {
  char string[256] = {"sin(x+2)"};

  node_calc *dst = NULL;
  node_calc *src = NULL;
  node_calc *res = NULL;
  int check = 0;
  int error = 0;
  check = s21_check_string(string);
  if (check == 0) {
    check = s21_stack_maker(string, &dst);
    s21_calc(&dst, &res, src, 0, 0, &error);
  }

  ck_assert_double_eq(check, 1);
}
END_TEST

START_TEST(mix_2) {
  char string[256] = {"(((1+2)))*3"};

  double result = (((1 + 2))) * 3;
  node_calc *dst = NULL;
  node_calc *src = NULL;
  node_calc *res = NULL;
  int error = 0;
  int check = 0;
  check = s21_check_string(string);
  if (check == 0) {
    s21_stack_maker(string, &dst);
  }

  double resultMY = s21_calc(&dst, &res, src, 0, 0, &error);
  freeList(&dst);
  freeList(&src);
  freeList(&res);
  ck_assert_double_eq(resultMY, result);
}
END_TEST

START_TEST(mix_3) {
  char string[256] = {"(((1+2)))*3"};

  double result = (((1 + 2))) * 3;
  node_calc *dst = NULL;
  node_calc *src = NULL;
  node_calc *res = NULL;
  int error = 0;
  int check = 0;
  check = s21_check_string(string);
  if (check == 0) {
    s21_stack_maker(string, &dst);
  }

  double resultMY = s21_calc(&dst, &res, src, 0, 0, &error);
  freeList(&dst);
  freeList(&src);
  freeList(&res);
  ck_assert_double_eq(resultMY, result);
}
END_TEST

START_TEST(mix_4) {
  char string[256] = {"(4/((1*2)))-3"};

  double result = (4 / ((1 * 2))) - 3;
  node_calc *dst = NULL;
  node_calc *src = NULL;
  node_calc *res = NULL;
  int error = 0;
  int check = 0;
  check = s21_check_string(string);
  if (check == 0) {
    s21_stack_maker(string, &dst);
  }

  double resultMY = s21_calc(&dst, &res, src, 0, 0, &error);
  freeList(&dst);
  freeList(&src);
  freeList(&res);
  ck_assert_double_eq(resultMY, result);
}
END_TEST

START_TEST(mix_5) {
  char string[256] = {"1+2+3*(0-1)+(-1)"};

  double result = 1 + 2 + 3 * (0 - 1) + (-1);
  node_calc *dst = NULL;
  node_calc *src = NULL;
  node_calc *res = NULL;
  int error = 0;
  int check = 0;
  check = s21_check_string(string);
  if (check == 0) {
    s21_stack_maker(string, &dst);
  }

  double resultMY = s21_calc(&dst, &res, src, 0, 0, &error);
  freeList(&dst);
  freeList(&src);
  freeList(&res);
  ck_assert_double_eq(resultMY, result);
}
END_TEST

START_TEST(mix_6) {
  char string[256] = {"3+4*2/(1-5)*2"};

  double result = 3 + 4 * 2 / (1 - 5) * 2;
  node_calc *dst = NULL;
  node_calc *src = NULL;
  node_calc *res = NULL;
  int error = 0;
  int check = 0;
  check = s21_check_string(string);
  if (check == 0) {
    s21_stack_maker(string, &dst);
  }

  double resultMY = s21_calc(&dst, &res, src, 0, 0, &error);
  freeList(&dst);
  freeList(&src);
  freeList(&res);
  ck_assert_double_eq(resultMY, result);
}
END_TEST

START_TEST(mix_7) {
  char string[256] = {"2+3*(2*1+1)"};

  double result = 2 + 3 * (2 * 1 + 1);
  node_calc *dst = NULL;
  node_calc *src = NULL;
  node_calc *res = NULL;
  int error = 0;
  int check = 0;
  check = s21_check_string(string);
  if (check == 0) {
    s21_stack_maker(string, &dst);
  }

  double resultMY = s21_calc(&dst, &res, src, 0, 0, &error);
  freeList(&dst);
  freeList(&src);
  freeList(&res);
  ck_assert_double_eq(resultMY, result);
}
END_TEST

START_TEST(mix_8) {
  char string[256] = {"3+5*2/(6-4)*2"};
  double result = 3 + 5 * 2 / (6 - 4) * 2;
  node_calc *dst = NULL;
  node_calc *src = NULL;
  node_calc *res = NULL;
  int error = 0;
  int check = 0;
  check = s21_check_string(string);
  if (check == 0) {
    s21_stack_maker(string, &dst);
  }

  double resultMY = s21_calc(&dst, &res, src, 0, 0, &error);
  freeList(&dst);
  freeList(&src);
  freeList(&res);
  ck_assert_double_eq(resultMY, result);
}
END_TEST

START_TEST(mix_10) {
  char string[256] = {"11+(7*2)"};

  double result = 11 + (7 * 2);
  node_calc *dst = NULL;
  node_calc *src = NULL;
  node_calc *res = NULL;
  int error = 0;
  int check = 0;
  check = s21_check_string(string);
  if (check == 0) {
    s21_stack_maker(string, &dst);
  }

  double resultMY = s21_calc(&dst, &res, src, 0, 0, &error);
  freeList(&dst);
  freeList(&src);
  freeList(&res);
  ck_assert_double_eq(resultMY, result);
}
END_TEST

START_TEST(mix_11) {
  char string[256] = {"11+7*2"};

  double result = 11 + 7 * 2;
  node_calc *dst = NULL;
  node_calc *src = NULL;
  node_calc *res = NULL;
  int error = 0;
  int check = 0;
  check = s21_check_string(string);
  if (check == 0) {
    s21_stack_maker(string, &dst);
  }

  double resultMY = s21_calc(&dst, &res, src, 0, 0, &error);
  freeList(&dst);
  freeList(&src);
  freeList(&res);
  ck_assert_double_eq(resultMY, result);
}
END_TEST

START_TEST(mix_12) {
  char string[256] = {"(0.432*54.2/4*2-(-8*4))*0.02"};

  double result = (0.432 * 54.2 / 4 * 2 - (-8 * 4)) * 0.02;
  node_calc *dst = NULL;
  node_calc *src = NULL;
  node_calc *res = NULL;
  int error = 0;
  int check = 0;
  check = s21_check_string(string);
  if (check == 0) {
    s21_stack_maker(string, &dst);
  }

  double resultMY = s21_calc(&dst, &res, src, 0, 0, &error);
  freeList(&dst);
  freeList(&src);
  freeList(&res);
  ck_assert_double_eq(resultMY, result);
}
END_TEST

// -----------------------------------------------
START_TEST(mix_13) {
  char string[256] = {"11-(123124.0001+(42-32.327)-32)*423/432"};

  double result = 11 - (123124.0001 + (42 - 32.327) - 32) * 423 / 432;
  node_calc *dst = NULL;
  node_calc *src = NULL;
  node_calc *res = NULL;
  int error = 0;
  int check = 0;
  check = s21_check_string(string);
  if (check == 0) {
    s21_stack_maker(string, &dst);
  }

  double resultMY = s21_calc(&dst, &res, src, 0, 0, &error);
  freeList(&dst);
  freeList(&src);
  freeList(&res);
  ck_assert_double_eq(resultMY, result);
}
END_TEST
START_TEST(mix_14) {
  char string[256] = {"32mod(32-30)"};

  double result = fmod(32, (32 - 30));
  node_calc *dst = NULL;
  node_calc *src = NULL;
  node_calc *res = NULL;
  int error = 0;
  int check = 0;
  check = s21_check_string(string);
  if (check == 0) {
    s21_stack_maker(string, &dst);
  }

  double resultMY = s21_calc(&dst, &res, src, 0, 0, &error);
  freeList(&dst);
  freeList(&src);
  freeList(&res);
  ck_assert_double_eq(resultMY, result);
}
END_TEST
START_TEST(mix_15) {
  char string[256] = {"12-32*(2143-312*(4-5)-1.32/(83.2/3))"};

  double result = 12 - 32 * (2143 - 312 * (4 - 5) - 1.32 / (83.2 / 3));
  node_calc *dst = NULL;
  node_calc *src = NULL;
  node_calc *res = NULL;
  int error = 0;
  int check = 0;
  check = s21_check_string(string);
  if (check == 0) {
    s21_stack_maker(string, &dst);
  }

  double resultMY = s21_calc(&dst, &res, src, 0, 0, &error);
  freeList(&dst);
  freeList(&src);
  freeList(&res);
  ck_assert_double_eq(resultMY, result);
}
END_TEST

START_TEST(mix_16) {
  char string[256] = {"2*3*2-100"};

  double result = 2 * 3 * 2 - 100;
  node_calc *dst = NULL;
  node_calc *src = NULL;
  node_calc *res = NULL;
  int error = 0;
  int check = 0;
  check = s21_check_string(string);
  if (check == 0) {
    s21_stack_maker(string, &dst);
  }

  double resultMY = s21_calc(&dst, &res, src, 0, 0, &error);
  freeList(&dst);
  freeList(&src);
  freeList(&res);
  ck_assert_double_eq(resultMY, result);
}
END_TEST

START_TEST(mix_17) {
  char string[256] = {"2*(3)*2+10"};

  double result = 2 * (3) * 2 + 10;
  node_calc *dst = NULL;
  node_calc *src = NULL;
  node_calc *res = NULL;
  int error = 0;
  int check = 0;
  check = s21_check_string(string);
  if (check == 0) {
    s21_stack_maker(string, &dst);
  }

  double resultMY = s21_calc(&dst, &res, src, 0, 0, &error);
  freeList(&dst);
  freeList(&src);
  freeList(&res);
  ck_assert_double_eq(resultMY, result);
}
END_TEST

START_TEST(mix_18) {
  char string[256] = {"2+3*(2*1+1)"};

  double result = 2 + 3 * (2 * 1 + 1);
  node_calc *dst = NULL;
  node_calc *src = NULL;
  node_calc *res = NULL;
  int error = 0;
  int check = 0;
  check = s21_check_string(string);
  if (check == 0) {
    s21_stack_maker(string, &dst);
  }

  double resultMY = s21_calc(&dst, &res, src, 0, 0, &error);
  freeList(&dst);
  freeList(&src);
  freeList(&res);
  ck_assert_double_eq(resultMY, result);
}
END_TEST

START_TEST(mix_19) {
  char string[256] = {"512/(2)*(3*2)*100+3"};
  double result = 512 / (2) * (3 * 2) * 100 + 3;
  node_calc *dst = NULL;
  node_calc *src = NULL;
  node_calc *res = NULL;
  int error = 0;
  int check = 0;
  check = s21_check_string(string);
  if (check == 0) {
    s21_stack_maker(string, &dst);
  }

  double resultMY = s21_calc(&dst, &res, src, 0, 0, &error);
  freeList(&dst);
  freeList(&src);
  freeList(&res);
  ck_assert_double_eq(resultMY, result);
}
END_TEST
Suite *suite_calc_test(void) {
  Suite *s = suite_create("suite_calc_test");
  TCase *tc = tcase_create("suite_calc_test");

  // tcase_add_loop_test(tc, create_1, 0, 100);
  tcase_add_test(tc, test_smart_calc_1);
  tcase_add_test(tc, addition_1);
  tcase_add_test(tc, addition_2);
  tcase_add_test(tc, subtraction_4);
  tcase_add_test(tc, subtraction_5);
  tcase_add_test(tc, multiplication_4);
  tcase_add_test(tc, multiplication_5);
  tcase_add_test(tc, division_4);
  tcase_add_test(tc, division_5);
  tcase_add_test(tc, power_1);
  tcase_add_test(tc, power_2);
  tcase_add_test(tc, power_3);
  tcase_add_test(tc, power_4);
  tcase_add_test(tc, power_5);
  tcase_add_test(tc, mix_1);
  tcase_add_test(tc, mix_2);
  tcase_add_test(tc, mix_3);
  tcase_add_test(tc, mix_4);
  tcase_add_test(tc, mix_5);
  tcase_add_test(tc, mix_6);
  tcase_add_test(tc, mix_7);
  tcase_add_test(tc, mix_8);
  // tcase_add_test(tc, mix_9);
  tcase_add_test(tc, mix_10);
  tcase_add_test(tc, mix_11);
  tcase_add_test(tc, mix_12);
  tcase_add_test(tc, mix_13);
  tcase_add_test(tc, mix_14);
  tcase_add_test(tc, mix_15);
  tcase_add_test(tc, mix_16);
  tcase_add_test(tc, mix_17);
  tcase_add_test(tc, mix_18);
  tcase_add_test(tc, mix_19);
  tcase_add_test(tc, cosin_1);
  tcase_add_test(tc, cosin_2);
  tcase_add_test(tc, cosin_3);
  tcase_add_test(tc, cosin_4);
  tcase_add_test(tc, cosin_5);
  tcase_add_test(tc, cosin_6);
  tcase_add_test(tc, cosin_7);
  tcase_add_test(tc, cosin_8);
  tcase_add_test(tc, cosin_9);
  tcase_add_test(tc, cosin_10);
  tcase_add_test(tc, cosin_11);
  tcase_add_test(tc, x_1);
  tcase_add_test(tc, x_2);
  suite_add_tcase(s, tc);
  return s;
}
int main() {
  int failed = 0;
  int passed = 0;
  Suite *matrix_tests[] = {suite_calc_test(), NULL};

  for (int i = 0; matrix_tests[i] != NULL; i++) {
    SRunner *sr = srunner_create(matrix_tests[i]);

    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);

    failed += srunner_ntests_failed(sr);
    passed += srunner_ntests_run(sr) - srunner_ntests_failed(sr);
    srunner_free(sr);
  }

  printf("========= PASSED: %d =========\n", passed);
  printf("========= FAILED: %d =========\n", failed);

  return failed == 0 ? 0 : 1;
}
