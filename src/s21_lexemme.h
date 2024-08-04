#ifndef S21_LEXEMME_H
#define S21_LEXEMME_H

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
#include "s21_postfix.h"
#include "s21_wise.h"

typedef enum {
  DIG = 1,
  X = 2,
  MINUS = 3,
  PLUS = 4,
  DIV = 5,
  MUL = 6,
  POW = 7,
  MOD = 8,
  UNARM = 9,
  UNARP = 10,
  COS = 11,
  SIN = 12,
  TAN = 13,
  ACOS = 14,
  ASIN = 15,
  ATAN = 16,
  SQRT = 17,
  LN = 18,
  LOG = 19,
  LEFTScobe = 20,
  RIGHTScobe = 21
} type_calc;

typedef enum {
  DIG_p = 0,
  X_p = 0,
  MINUS_p = 1,
  PLUS_p = 1,
  DIV_p = 2,
  MUL_p = 2,
  POW_p = 3,
  MOD_p = 3,
  UNARM_p = 4,
  UNARP_p = 4,
  COS_p = 5,
  SIN_p = 5,
  TAN_p = 5,
  ACOS_p = 5,
  ASIN_p = 5,
  ATAN_p = 5,
  SQRT_p = 5,
  LN_p = 5,
  LOG_p = 5,
  LEFTScobe_p = -1,
  RIGHTScobe_p = -1
} type_priority;

int s21_stack_maker(char* string, node_calc** head);
char* s21_get_scobe(char* string, int* result, int* priority);
char* s21_get_opr(char* string, int* result, int* priority);
char* s21_get_m_opr(char* string, int* result, int* priority);
char* s21_get_unarm(char* string, int* result, int* priority);
char* its_num_func(char* str, double* num);
#ifdef __cplusplus
}
#endif
#endif  // S21_LEXEMME_H
