#ifndef S21_CALCULATOR_H_
#define S21_CALCULATOR_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif
#include "s21_calc_stack.h"
#include "s21_check_string.h"
#include "s21_lexemme.h"
#include "s21_postfix.h"
#include "s21_wise.h"

double s21_calc(node_calc** dst, node_calc** res, node_calc* src, int is_x,
                double x_value, int* error);
#ifdef __cplusplus
}
#endif
#endif  // S21_CALCULATOR_H_
