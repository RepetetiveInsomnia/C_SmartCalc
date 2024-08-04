#include "s21_postfix.h"

void s21_to_postfix(node_calc *src, node_calc **res) {
  node_calc *tmp = NULL;

  while (src) {
    if (s21_type(&src) == LEFTScobe) {
      s21_push(&tmp, src->value, src->type, src->priority);

    } else if (s21_type(&src) == RIGHTScobe) {
      while (s21_type(&tmp) != LEFTScobe && tmp->next != NULL) {
        s21_push(res, tmp->value, tmp->type, tmp->priority);

        s21_pop(&tmp);
      }
      if (tmp->type == LEFTScobe && tmp->next != NULL) {
        s21_pop(&tmp);

        if (tmp->priority == SIN_p) {
          s21_push(res, tmp->value, tmp->type, tmp->priority);

          s21_pop(&tmp);
        }
      }
    } else if (s21_type(&src) == DIG || s21_type(&src) == X) {
      s21_push(res, src->value, src->type, src->priority);

    } else {
      if (tmp == NULL) {
        s21_push(&tmp, src->value, src->type, src->priority);

      } else if (s21_priority(&src) > s21_priority(&tmp)) {
        s21_push(&tmp, src->value, src->type, src->priority);

      } else if (s21_priority(&src) <= s21_priority(&tmp)) {
        s21_push(res, tmp->value, tmp->type, tmp->priority);

        if (tmp->next != NULL) {
          s21_pop(&tmp);
        } else {
          freeList(&tmp);
        }

        if (tmp != NULL) {
          while (s21_priority(&tmp) >= s21_priority(&src) &&
                 tmp->next != NULL) {
            s21_push(res, tmp->value, tmp->type, tmp->priority);
            s21_pop(&tmp);
          }
          if (tmp != NULL && s21_priority(&tmp) >= s21_priority(&src)) {
            s21_push(res, tmp->value, tmp->type, tmp->priority);
            freeList(&tmp);
            // tmp = NULL;
          }
        }

        s21_push(&tmp, src->value, src->type, src->priority);
      }
    }
    s21_pop(&src);
  }

  while (tmp) {
    if (tmp->type != LEFTScobe && tmp->type != RIGHTScobe) {
      s21_push(res, tmp->value, tmp->type, tmp->priority);
    }
    s21_pop(&tmp);
  }
  // freeList(&src);
}

double s21_cal_mopr(double value1, int type) {
  double result = 0.0;
  if (type == 9) {
    result = -1 * value1;
  }
  if (type == 10) {
    result = value1;
  }
  if (type == 11) {
    result = cos(value1);
  }
  if (type == 12) {
    result = sin(value1);
  }
  if (type == 13) {
    result = tan(value1);
  }
  if (type == 14) {
    result = acos(value1);
  }
  if (type == 15) {
    result = asin(value1);
  }
  if (type == 16) {
    result = atan(value1);
  }
  if (type == 17) {
    result = sqrt(value1);
  }
  if (type == 18) {
    result = log(value1);
  }
  if (type == 19) {
    result = log10(value1);
  }
  return result;
}

double s21_cal_opr(double value1, double value2, int type) {
  double result = 0.0;
  if (type == 3) {
    result = value1 - value2;
  }
  if (type == 4) {
    result = value1 + value2;
  }
  if (type == 5) {
    result = value1 / value2;
  }
  if (type == 6) {
    result = value1 * value2;
  }
  if (type == 7) {
    result = (double)powl((long double)value1, (long double)value2);
  }
  if (type == 8) {
    result = (double)fmod((long double)value1, (long double)value2);
  }
  return result;
}

double s21_chech_num(node_calc **src, node_calc **dst, double *value1,
                     double *value2, int *calc_flag, _Bool *opr_flag,
                     int *x_flag, _Bool is_x, double x_value) {
  double result = 0.0;
  if (*calc_flag == 0) {
    if (is_x == 0) {
      if (check_x(src) == 1) {
        *x_flag = 1;
      } else if (*x_flag != 2) {
        *x_flag = 0;
      }
    }
    if (is_x == 1 && check_x(src) == 1) {
      *value1 = x_value;
    } else {
      *value1 = (*src)->value;
    }
    *calc_flag = 1;
  } else if (*calc_flag == 1) {
    if (is_x == 0) {
      if (check_x(src) == 1) {
        *x_flag = 2;
      } else if (*x_flag != 1) {
        *x_flag = 0;
      }
    }
    if (is_x == 1 && check_x(src) == 1) {
      *value2 = x_value;
    } else {
      *value2 = (*src)->value;
    }
    *calc_flag = 2;
  } else if (*calc_flag == 2) {
    if (*opr_flag == 1) {
      *opr_flag = 0;
    } else {
      if (*x_flag != 1) {
        s21_push(dst, *value1, DIG, DIG_p);
      } else {
        s21_push(dst, *value1, X, X_p);
        *x_flag = 0;
      }
    }
    *value1 = *value2;
    if (*x_flag == 2) {
      *x_flag = 1;
    }
    *value2 = (*src)->value;
    if (is_x == 0) {
      if (check_x(src) == 1) {
        *x_flag = 2;
      } else if (*x_flag != 1) {
        *x_flag = 0;
      }
    }
  }
  if ((*src)->next != NULL) {
    s21_pop(src);
  } else {
    freeList(src);
    //*src = NULL;
  }

  return result;
}

int check_x(node_calc **src) {
  _Bool result = 0;
  if ((*src)->type == X) {
    result = 1;
  }
  return result;
}

double s21_chech_opr(node_calc **src, node_calc **dst, double *value1,
                     double *value2) {
  double result = s21_cal_opr(*value1, *value2, (*src)->type);
  *value1 = result;

  s21_push(dst, result, DIG, DIG_p);

  if ((*src)->next != NULL) {
    s21_pop(src);
    if ((*src)->type >= COS && (*src)->type <= LOG) {
      s21_pop(dst);
    }
  } else {
    freeList(src);
    //(*src) = NULL;
  }
  return result;
}

double s21_chech_mopr(node_calc **src, node_calc **dst, double math_value) {
  double result = s21_cal_mopr(math_value, (*src)->type);
  s21_push(dst, result, DIG, DIG_p);
  if ((*src)->next != NULL) {
    s21_pop(src);
    if ((*src)->type >= UNARM && (*src)->type <= LOG) {
      s21_pop(dst);
    }
  } else {
    freeList(src);
    //(*src) = NULL;
  }
  return result;
}

_Bool s21_check_zero_delim(node_calc **src, node_calc **dst, double value1,
                           double value2) {
  _Bool answer = 0;
  if ((value2 == 0.0 && (*src)->type == DIV) ||
      (value1 == 0.0 && (*src)->type == MOD)) {
    answer = 1;
    freeList(src);
    (*src) = NULL;
    freeList(dst);
    (*dst) = NULL;
  }
  return answer;
}

double s21_prepare_mopr(node_calc **dst, int *calc_flag, _Bool *opr_flag,
                        double value1, double value2) {
  double result = 0.0;
  if (*calc_flag == 2) {
    if (*opr_flag == 1) {
      *opr_flag = 0;
    } else {
      s21_push(dst, value1, DIG, DIG_p);
    }
    result = value2;
  } else {
    result = value1;
  }
  *calc_flag = 1;
  *opr_flag = 1;

  return result;
}

void s21_prepare_opr(node_calc **dst, int *calc_flag, _Bool *opr_flag) {
  if (*opr_flag == 1) {
    if ((*dst) != NULL) {
      s21_pop(dst);
    }
    *opr_flag = 0;
  }
  *calc_flag = 1;
}
void s21_write_remainder(node_calc **src, node_calc **dst) {
  while ((*src) != NULL) {
    s21_push(dst, (*src)->value, (*src)->type, (*src)->priority);
    s21_pop(src);
  }
  //*src = NULL;
}

void s21_x_mopr(node_calc **src, node_calc **dst, int *calc_flag,
                _Bool *x_opr_flag, double value1, double value2) {
  if (*calc_flag == 2) {
    s21_push(dst, value1, DIG, DIG_p);
  }
  *calc_flag = 0;
  *x_opr_flag = 1;

  s21_push(dst, value2, X, X_p);
  s21_push(dst, 0, (*src)->type, (*src)->priority);

  if ((*src)->next != NULL) {
    s21_pop(src);
  } else {
    freeList(src);
  }
}

void s21_x_opr(node_calc **src, node_calc **dst, int *calc_flag, int x_flag,
               _Bool *x_opr_flag, _Bool *opr_flag, double value1,
               double value2) {
  *calc_flag = 0;
  *x_opr_flag = 1;
  if (x_flag == 1) {
    s21_push(dst, value1, X, X_p);
    s21_push(dst, value2, DIG, DIG_p);

  } else if (x_flag == 2) {
    if (*opr_flag == 0) {
      s21_push(dst, value1, DIG, DIG_p);
    } else {
      *opr_flag = 0;
    }

    s21_push(dst, value2, X, X_p);
  }
  s21_push(dst, 0, (*src)->type, (*src)->priority);

  if ((*src)->next != NULL) {
    s21_pop(src);
  } else {
    freeList(src);
    //(*src) = NULL;
  }
}

void s21_calculate(node_calc *src, node_calc **dst, _Bool is_x, double x_value,
                   double *result, int *error) {
  double value1 = 0.0;
  double value2 = 0.0;
  double math_value = 0.0;

  _Bool opr_flag = 0;
  _Bool x_opr_flag = 0;
  int calc_flag = 0;
  int x_flag = 0;

  while (src != NULL) {
    if (src != NULL && (src->type == DIG || src->type == X)) {
      s21_chech_num(&src, dst, &value1, &value2, &calc_flag, &opr_flag, &x_flag,
                    is_x, x_value);
    }
    if (src != NULL && calc_flag == 1 && src->type >= MINUS &&
        src->type <= MOD) {
      if (x_opr_flag == 1) {
        s21_push(dst, value1, DIG, DIG_p);
      }
      if (x_flag != 0) {
        x_opr_flag = 1;
      }
      break;
    }
    if (src != NULL && src->type >= UNARM && src->type <= LOG) {
      if (x_flag != 0) {
        s21_x_mopr(&src, dst, &calc_flag, &x_opr_flag, value1, value2);
        if (src != NULL && s21_type(&src) != DIG) {
          break;
        }
      } else {
        math_value =
            s21_prepare_mopr(dst, &calc_flag, &opr_flag, value1, value2);

        *result = s21_chech_mopr(&src, dst, math_value);
        value1 = *result;
      }
    }
    if (src != NULL && src->type >= MINUS && src->type <= MOD &&
        calc_flag == 2) {
      if (x_flag != 0) {
        s21_x_opr(&src, dst, &calc_flag, x_flag, &x_opr_flag, &opr_flag, value1,
                  value2);
        if (src != NULL && s21_type(&src) != DIG) {
          break;
        }
      } else {
        if (src->next != NULL) {
          x_opr_flag = 0;
        }
        s21_prepare_opr(dst, &calc_flag, &opr_flag);
        if (s21_check_zero_delim(&src, dst, value1, value2) == 1) {
          *error = 1;
          *result = NAN;
          break;
        } else {
          *result = s21_chech_opr(&src, dst, &value1, &value2);
          opr_flag = 1;
        }
      }
    }
  }

  if (*error == 0) {
    s21_write_remainder(&src, dst);
    // freeList(&src);
    // src = NULL;
    if ((*dst) != NULL) {
      if ((*dst)->type != DIG && opr_flag == 1 && x_opr_flag != 1) {
        // printf("FFF\n");
        node_calc *dst_inverse = NULL;
        dst_inverse = s21_inverse(dst);
        freeList(dst);
        *dst = NULL;
        s21_calculate(dst_inverse, dst, 0, 0, result, error);
        // freeList(&dst_inverse);
        // dst_inverse = NULL;
      } else {
        if (x_opr_flag != 0) {
          // printf("XXX\n");
          node_calc *dst_inverse = s21_inverse(dst);
          freeList(dst);
          *dst = NULL;
          *dst = dst_inverse;
        } else {
          *result = (*dst)->value;
          // printf("RRR %f\n", *result);
          freeList(dst);
          dst = NULL;
        }
      }
    }
  }
}
