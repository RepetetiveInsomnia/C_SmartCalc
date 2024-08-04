
#include "s21_calculator.h"

double s21_calc(node_calc** dst, node_calc** res, node_calc* src, int is_x,
                double x_value, int* error) {
  double result = 0.0;
  if (is_x == 0) {
    node_calc* inverse = NULL;
    inverse = s21_inverse(dst);

    s21_to_postfix(inverse, res);

    src = s21_inverse(res);
    freeList(res);
    res = NULL;

    s21_calculate(src, dst, 0, 0, &result, error);

  } else {
    s21_calculate(src, dst, 1, x_value, &result, error);
  }
  freeList(dst);
  dst = NULL;

  return result;
}
