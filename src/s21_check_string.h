#ifndef S21_CHECK_STRING_H_
#define S21_CHECK_STRING_H_

#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef __cplusplus
extern "C" {
#endif

typedef enum { OK = 0, ERROR = 1 } operation_result;

int s21_check_string(char* string);
int s21_check_num_x(char* string, int i);
int s21_check_num_dot(char* string, int i);
int s21_check_oper(char* string, int i);
int s21_check_stray_scob_close(char* string, int i, int* scob);
int s21_check_stray_scob_open(char* string, int i, int* scob);
int s21_check_math_opr(char* string, int i);
int s21_simple_check(char* string);
#ifdef __cplusplus
}
#endif
#endif  // S21_CHECK_STRING_H_
