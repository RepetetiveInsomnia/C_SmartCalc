#include "s21_wise.h"

int s21_isnumber(char c) {
  answer result = NO;
  if ((c >= '0' && c <= '9') || c == ',') {
    result = YES;
  }
  return result;
}

int s21_is_scobe(char c) {
  answer result = NO;
  if (c == '(' || c == ')') {
    result = YES;
  }
  return result;
}

int s21_opr(char c) {
  answer result = NO;
  if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
    result = YES;
  }
  return result;
}

int s21_is_unarm(char c, node_calc **head) {
  answer result = NO;
  if (*head != NULL) {
    if ((s21_type(head) >= 3 && s21_type(head) <= 7) ||
        s21_type(head) == LEFTScobe) {
      if (c == '+' || c == '-') {
        result = YES;
      }
    }
  } else {
    if (c == '+' || c == '-') {
      result = YES;
    }
  }
  return result;
}

int s21_is_x(char c) {
  answer result = NO;
  if (c == 'x') {
    result = YES;
  }
  return result;
}

int s21_is_m_opr(char c) {
  answer result = NO;
  if (c == 'a' || c == 's' || c == 'c' || c == 't' || c == 'l' || c == 'm') {
    result = YES;
  }
  return result;
}
