#ifndef S21_POSTFIX_H
#define S21_POSTFIX_H

#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef __cplusplus
extern "C" {
#endif
#include "s21_calc_stack.h"
#include "s21_calculator.h"
#include "s21_check_string.h"
#include "s21_lexemme.h"
#include "s21_wise.h"

void s21_to_postfix(node_calc *src, node_calc **res);
void s21_calculate(node_calc *src, node_calc **dst, _Bool is_x, double x_value,
                   double *result, int *error);
void s21_prepare_opr(node_calc **dst, int *calc_flag, _Bool *opr_flag);
double s21_prepare_mopr(node_calc **dst, int *calc_flag, _Bool *opr_flag,
                        double value1, double value2);
double s21_cal_opr(double value1, double value2, int type);
double s21_cal_mopr(double value1, int type);
double s21_chech_num(node_calc **src, node_calc **dst, double *value1,
                     double *value2, int *calc_flag, _Bool *opr_flag,
                     int *x_flag, _Bool is_x, double x_value);
double s21_chech_opr(node_calc **src, node_calc **dst, double *value1,
                     double *value2);
double s21_chech_mopr(node_calc **src, node_calc **dst, double math_value);
_Bool s21_check_zero_delim(node_calc **src, node_calc **dst, double value1,
                           double value2);
void s21_write_remainder(node_calc **src, node_calc **dst);
int check_x(node_calc **src);

#ifdef __cplusplus
}
#endif
#endif  // S21_POSTFIX_H
