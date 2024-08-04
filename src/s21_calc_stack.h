#ifndef S21_CALC_STACK_H_
#define S21_CALC_STACK_H_

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif
typedef struct Node {
  double value;
  int priority;
  int type;
  struct Node *next;
} node_calc;

void s21_push(node_calc **head, double value, int type, int priority);
void s21_pop(node_calc **head);
// node_calc s21_top(node_calc **head);
int s21_type(node_calc **head);
int s21_priority(node_calc **head);
node_calc *s21_inverse(node_calc **head);
void freeList(node_calc **head);
// void s21_print_list(node_calc *head);
// void s21_get_info_list(node_calc *head);
node_calc *s21_copy_list(node_calc **head);

#ifdef __cplusplus
}
#endif
#endif  // S21_CALC_STACK_H_
