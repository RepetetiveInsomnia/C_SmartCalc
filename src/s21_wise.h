#ifndef S21_WISE_H_
#define S21_WISE_H_

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
#include "s21_postfix.h"

typedef enum { YES = 0, NO = 1 } answer;

int s21_isnumber(char c);
int s21_is_scobe(char c);
int s21_opr(char c);
int s21_is_x(char c);
int s21_is_m_opr(char c);
int s21_is_unarm(char c, node_calc **head);

#ifdef __cplusplus
}
#endif
#endif  // S21_WISE_H_
