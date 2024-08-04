#ifndef TEST_S21_CALC_TEST_H_
#define TEST_S21_CALC_TEST_H_

#include <check.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include "../s21_calc_stack.h"
#include "../s21_calculator.h"
#include "../s21_check_string.h"
#include "../s21_lexemme.h"
#include "../s21_postfix.h"
#include "../s21_wise.h"

double get_rand(double min, double max);

Suite *suite_calc_test(void);

#endif  // TEST_S21_ CALC_TEST_H_
