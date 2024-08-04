#include "s21_check_string.h"

int s21_check_string(char* string) {
  operation_result result = OK;

  result = s21_simple_check(string);

  int i = 0, scob = 0;
  while (string[i] != '\0' && result == OK) {
    if (isspace(string[i]) == 0) {
      if (result == OK) {
        result = s21_check_num_x(string, i);
      }
      if (result == OK) {
        result = s21_check_num_dot(string, i);
      }
      if (result == OK) {
        result = s21_check_oper(string, i);
      }
      if (result == OK) {
        result = s21_check_stray_scob_close(string, i, &scob);
      }
      if (result == OK) {
        result = s21_check_stray_scob_open(string, i, &scob);
      }
      if (result == OK) {
        result = s21_check_math_opr(string, i);
      }
    }
    i++;
  }
  if (scob != 0) {
    result = ERROR;
  }
  return result;
}

int s21_check_num_x(char* string, int i) {
  operation_result result = OK;
  if (string[i] == 'x') {
    if (i != 0) {
      if (string[i - 1] != 'd') {
        if (string[i - 1] == ')' ||
            (string[i - 1] <= '9' && string[i - 1] >= '0')) {
          result = ERROR;
        }
      }
    }
    if (string[i + 1] != '\0') {
      if (string[i + 1] == '(' ||
          (string[i + 1] <= '9' && string[i + 1] >= '0') ||
          string[i + 1] == 's' || string[i + 1] == 'c' ||
          string[i + 1] == 't' || string[i + 1] == 'a' ||
          string[i + 1] == 'l' || string[i + 1] == 'i' ||
          string[i + 1] == 'o' || string[i + 1] == 'q' ||
          string[i + 1] == 'n') {
        result = ERROR;
      }
    }
  }
  return result;
}

int s21_check_num_dot(char* string, int i) {
  operation_result result = OK;

  if (string[i] == '.') {
    if (i == 0 || i == (int)strlen(string) - 1) {
      result = ERROR;
    } else {
      if (string[i - 1] > '9' || string[i - 1] < '0' || string[i + 1] > '9' ||
          string[i + 1] < '0') {
        result = ERROR;
      }
    }
  }
  return result;
}

int s21_check_oper(char* string, int i) {
  operation_result result = OK;
  if (string[i] == '+' || string[i] == '-' || string[i] == '*' ||
      string[i] == '/' || string[i] == '^') {
    if (i == 0) {
      if (string[i] != '-' && string[i] != '+') {
        result = ERROR;
      } else if ((string[i] == '-' || string[i] == '+') &&
                 (string[i + 1] <= '0' || string[i + 1] >= '9') &&
                 s21_check_math_opr(string, i + 1) != 0) {
        result = ERROR;
      }
    } else if (i == (int)strlen(string) - 1) {
      result = ERROR;
    } else if ((string[i] == '-' || string[i] == '+') &&
               (string[i - 1] == '+' || string[i - 1] == '-' ||
                string[i - 1] == '*' || string[i] == '/' || string[i] == '^')) {
      if (string[i - 2] == '+' || string[i - 2] == '-' ||
          string[i - 2] == '*' || string[i - 2] == '/' ||
          string[i - 2] == '^') {
        result = ERROR;
      }
    } else {
      if (s21_check_math_opr(string, i + 1) == 0) {
        if (string[i - 1] != 'x' && string[i + 1] != 'x' &&
            string[i - 1] != '(' && string[i + 1] != '(' &&
            string[i - 1] != ')') {
          if (string[i + 1] == 'm' || string[i + 1] == '*' ||
              string[i + 1] == '/' || string[i + 1] == '^') {
            result = ERROR;
          }
        }
      }
    }
  }

  return result;
}

int s21_check_stray_scob_close(char* string, int i, int* scob) {
  scob++;
  scob--;
  operation_result result = OK;
  if (string[i] == ')') {
    *scob -= 1;
    if (*scob == -1) {
      result = ERROR;
    }
    if (i != 0) {
      if (string[i - 1] == '+' || string[i - 1] == '/' ||
          string[i - 1] == '*' || string[i - 1] == '-' ||
          string[i - 1] == '^' || string[i - 1] == '(') {
        result = ERROR;
      }
      if ((string[i + 1] == 's' && string[i + 2] == 'i' &&
           string[i + 3] == 'n') ||
          (string[i + 1] == 'c' && string[i + 2] == 'o' &&
           string[i + 3] == 's') ||
          (string[i + 1] == 't' && string[i + 2] == 'a' &&
           string[i + 3] == 'n') ||
          (string[i + 1] == 'a' && string[i + 2] == 's' &&
           string[i + 3] == 'i' && string[i + 4] == 'n') ||
          (string[i + 1] == 'a' && string[i + 2] == 'c' &&
           string[i + 3] == 'o' && string[i + 4] == 's') ||
          (string[i + 1] == 'l' && string[i + 2] == 'n') ||
          (string[i + 1] == 'l' && string[i + 2] == 'o' &&
           string[i + 3] == 'g') ||
          (string[i + 1] == 'a' && string[i + 2] == 't' &&
           string[i + 3] == 'a' && string[i + 4] == 'n') ||
          (string[i + 1] == 's' && string[i + 2] == 'q' &&
           string[i + 3] == 'r' && string[i + 4] == 't')) {
        result = ERROR;
      }
    } else {
      result = ERROR;
    }
  }
  return result;
}

int s21_check_stray_scob_open(char* string, int i, int* scob) {
  operation_result result = OK;
  if (string[i] == '(') {
    *scob += 1;
    if (i != (int)strlen(string) - 1) {
      if (string[i + 1] == '/' || string[i + 1] == '*' ||
          string[i + 1] == '^' || string[i + 1] == ')') {
        result = ERROR;
      } else if (i != 0 && isspace(string[i - 1]) == 0) {
        if (string[i - 1] != '+' && string[i - 1] != '/' &&
            string[i - 1] != '*' && string[i - 1] != '-' &&
            string[i - 1] != '^' && string[i - 1] != '(' &&
            string[i - 1] != 'n' && string[i - 1] != 's' &&
            string[i - 1] != 't' && string[i - 1] != 'g' &&
            string[i - 1] != 'd') {
          result = ERROR;
        }
      }
    } else {
      result = ERROR;
    }
  }
  return result;
}

int s21_check_math_opr(char* string, int i) {
  operation_result result = OK;
  if (string[i] == 'l' && string[i + 1] == 'n') {
    if (i != 0) {
      if (string[i - 1] == ')' || string[i - 1] <= '9' ||
          string[i - 1] >= '0') {
        result = ERROR;
      }
    }
    if (string[i + 2] != '(') {
      result = ERROR;
    }
  }
  if ((string[i] == 's' && string[i + 1] == 'i' && string[i + 2] == 'n') ||
      (string[i] == 'c' && string[i + 1] == 'o' && string[i + 2] == 's') ||
      (string[i] == 't' && string[i + 1] == 'a' && string[i + 2] == 'n') ||
      (string[i] == 'l' && string[i + 1] == 'o' && string[i + 2] == 'g')) {
    if (i != 0) {
      if (string[i - 1] != 'a' && string[i - 1] != '+' &&
          string[i - 1] != '/' && string[i - 1] != '*' &&
          string[i - 1] != '-' && string[i - 1] != '^' && string[i - 1] != '(')
        if (string[i - 1] == ')' || string[i - 1] <= '9' ||
            string[i - 1] >= '0') {
          result = ERROR;
        }
    }
    if (string[i + 3] != '(') {
      result = ERROR;
    }
  } else if ((string[i] == 'a' && string[i + 1] == 's' &&
              string[i + 2] == 'i' && string[i + 3] == 'n') ||
             (string[i] == 'a' && string[i + 1] == 'c' &&
              string[i + 2] == 'o' && string[i + 3] == 's') ||
             (string[i] == 'a' && string[i + 1] == 't' &&
              string[i + 2] == 'a' && string[i + 3] == 'n') ||
             (string[i] == 's' && string[i + 1] == 'q' &&
              string[i + 2] == 'r' && string[i + 3] == 't')) {
    if (i != 0) {
      if (string[i - 1] == ')' || string[i - 1] <= '9' ||
          string[i - 1] >= '0') {
        result = ERROR;
      }
    }
    if (string[i + 4] != '(') {
      result = ERROR;
    }
  } else if (string[i] == 'm' && string[i + 1] == 'o' && string[i + 2] == 'd') {
    if ((i == 0 && string[i] == 'm') ||
        (string[i] == 'd' && i == (int)strlen(string) - 1)) {
      result = ERROR;
    } else if (i != 0 && string[i] == 'm' &&
               (string[i - 1] == '(' || string[i - 1] == '+' ||
                string[i - 1] == '/' || string[i - 1] == '*' ||
                string[i - 1] == '-' || string[i - 1] == '^')) {
      result = ERROR;
    } else if (i != (int)strlen(string) - 1 && string[i] == 'd' &&
               (string[i + 1] == '+' || string[i + 1] == '/' ||
                string[i + 1] == '*' || string[i + 1] == '-' ||
                string[i + 1] == '^')) {
      result = ERROR;
    }
  }
  return result;
}

int s21_simple_check(char* string) {
  operation_result result = OK;
  if ((int)strlen(string) < 3) {
    result = ERROR;
  } else {
    for (int i = 0; i != (int)strlen(string) && result != ERROR; i++) {
      if (isspace(string[i]) == 0) {
        if ((string[i] < '0' || string[i] > '9') && string[i] != 32 &&
            string[i] != '.' && string[i] != '(' && string[i] != ')' &&
            string[i] != '+' && string[i] != '-' && string[i] != '*' &&
            string[i] != '/' && string[i] != '^' && string[i] != 'a' &&
            string[i] != 'n' && string[i] != 's' && string[i] != 'c' &&
            string[i] != 't' && string[i] != 'i' && string[i] != 'o' &&
            string[i] != 'q' && string[i] != 'r' && string[i] != 'l' &&
            string[i] != 'm' && string[i] != 'd' && string[i] != 'g' &&
            string[i] != 'x') {
          result = ERROR;
        }
      }
    }
  }
  return result;
}
