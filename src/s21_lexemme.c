#include "s21_lexemme.h"

int s21_stack_maker(char* string, node_calc** head) {
  char* tmp = NULL;
  tmp = string;
  double value = 0.0;
  int opr = 0;
  int priority = 0;
  int result = 0;

  while (*tmp != '\0') {
    if (s21_is_x(*tmp) == YES) {
      result = 1;
      s21_push(head, 0, X, X_p);
      tmp++;
    } else if (s21_isnumber(*tmp) == YES) {
      tmp = its_num_func(tmp, &value);
      s21_push(head, value, DIG, DIG_p);
      value = 0.0;
    } else if (s21_is_unarm(*tmp, head) == YES) {
      tmp = s21_get_unarm(tmp, &opr, &priority);
      s21_push(head, 0, opr, priority);
      opr = 0;
      priority = 0;
    } else if (s21_opr(*tmp) == YES) {
      tmp = s21_get_opr(tmp, &opr, &priority);
      s21_push(head, 0, opr, priority);
      opr = 0;
      priority = 0;
    } else if (s21_is_scobe(*tmp) == YES) {
      tmp = s21_get_scobe(tmp, &opr, &priority);
      s21_push(head, 0, opr, priority);
      opr = 0;
      priority = 0;
    } else if (s21_is_m_opr(*tmp) == YES) {
      tmp = s21_get_m_opr(tmp, &opr, &priority);
      s21_push(head, 0, opr, priority);
      opr = 0;
      priority = 0;
    } else {
      tmp++;
    }
    if (s21_type(head) == 0) {
      result = 2;  // unknown oper
      break;
    }
  }

  return result;
}

char* its_num_func(char* str, double* num) {
  char* s;
  int i = 0;
  s = (char*)calloc(255, sizeof(char));
  if (s != NULL) {
    while (str && (('0' <= *str && *str <= '9') || *str == '.')) {
      // printf("%c got\n", *str);
      s[i] = *str;
      i++;
      str++;
    }
    *num = atof(s);
    // printf("num %f\n", *num);
    //  str++;
  }
  free(s);
  // printf("str %s\n", str);
  return str;
}

char* s21_get_opr(char* string, int* result, int* priority) {
  if (*string == '+') {
    *result = PLUS;
    *priority = PLUS_p;
  }
  if (*string == '-') {
    *result = MINUS;
    *priority = MINUS_p;
  }
  if (*string == '*') {
    *result = MUL;
    *priority = MUL_p;
  }
  if (*string == '/') {
    *result = DIV;
    *priority = DIV_p;
  }
  if (*string == '^') {
    *result = POW;
    *priority = POW_p;
  }
  string++;
  return string;
}

char* s21_get_unarm(char* string, int* result, int* priority) {
  if (*string == '+') {
    *result = UNARP;
    *priority = UNARP_p;
  }
  if (*string == '-') {
    *result = UNARM;
    *priority = UNARM_p;
  }
  string++;
  return string;
}

char* s21_get_scobe(char* string, int* result, int* priority) {
  if (*string == '(') {
    *result = LEFTScobe;
    *priority = LEFTScobe_p;
  }
  if (*string == ')') {
    *result = RIGHTScobe;
    *priority = RIGHTScobe_p;
  }
  string++;
  return string;
}

char* s21_get_m_opr(char* string, int* result, int* priority) {
  char reference[5];
  int counter = 0;
  while (s21_isnumber(*string) != YES && s21_is_scobe(*string) != YES &&
         s21_is_x(*string) != YES) {
    reference[counter] = *string;

    string++;
    counter++;
  }
  reference[counter] = '\0';

  if (strcmp((const char*)reference, "ln") == 0) {
    *result = LN;
    *priority = LN_p;
  } else if (strcmp((const char*)reference, "log") == 0) {
    *result = LOG;
    *priority = LOG_p;
  } else if (strcmp((const char*)reference, "mod") == 0) {
    *result = MOD;
    *priority = MOD_p;
  } else if (strcmp((const char*)reference, "atan") == 0) {
    *result = ATAN;
    *priority = ATAN_p;
  } else if (strcmp((const char*)reference, "acos") == 0) {
    *result = ACOS;
    *priority = ACOS_p;
  } else if (strcmp((const char*)reference, "asin") == 0) {
    *result = ASIN;
    *priority = ASIN_p;
  } else if (strcmp((const char*)reference, "sin") == 0) {
    *result = SIN;
    *priority = SIN_p;
  } else if (strcmp((const char*)reference, "cos") == 0) {
    *result = COS;
    *priority = COS_p;
  } else if (strcmp((const char*)reference, "tan") == 0) {
    *result = TAN;
    *priority = TAN_p;
  } else if (strcmp((const char*)reference, "sqrt") == 0) {
    *result = SQRT;
    *priority = SQRT_p;
  }

  return string;
}
