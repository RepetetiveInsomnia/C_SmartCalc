#include "s21_calc_stack.h"

void s21_push(node_calc **head, double value, int type, int priority) {
  node_calc *tmp = (node_calc *)malloc(sizeof(node_calc));
  tmp->value = value;
  tmp->type = type;
  tmp->priority = priority;
  tmp->next = *head;
  *head = tmp;
}

void s21_pop(node_calc **head) {
  node_calc *stack = (*head);
  if (stack) {
    free(*head);
  }
  (*head) = stack->next;
}

node_calc *s21_inverse(node_calc **head) {
  node_calc *new = NULL;
  // node_calc *stack = NULL;
  while (*head) {
    s21_push(&new, (*head)->value, (*head)->type, (*head)->priority);
    s21_pop(head);
  }

  return new;
}

void freeList(node_calc **head) {
  node_calc *stack = NULL;
  while (*head) {
    stack = *head;
    *head = (*head)->next;
    free(stack);
    stack = NULL;
  }
  stack = NULL;
  head = NULL;
  // free(stack);
}
/*
void s21_print_list(node_calc *head) {
  if (head != NULL) {
    while (head) {
      printf("%f ", head->value);
      printf("TYPE %d ", head->type);
      printf("PRIO %d ", head->priority);
      printf("\n");
      head = head->next;
    }
  }
}

void s21_get_info_list(node_calc *head) {
  if (head != NULL) {
    printf("%f ", head->value);
    printf("TYPE %d ", head->type);
    printf("PRIO %d ", head->priority);
    printf("\n");
  }
}

node_calc s21_top(node_calc **head) {
  node_calc *tmp = (*head);
  return *tmp;
}
*/
node_calc *s21_copy_list(node_calc **head) {
  node_calc *new = NULL;
  node_calc *tmp = NULL;
  if (head != NULL) {
    while (*head) {
      s21_push(&new, (*head)->value, (*head)->type, (*head)->priority);
      s21_push(&tmp, (*head)->value, (*head)->type, (*head)->priority);
      s21_pop(head);
      //(*head) = (*head)->next;
    }
    (*head) = s21_inverse(&tmp);
    // new = s21_inverse(head);
    // s21_print_list(*head);
    // free(tmp);
  }
  return new;
}

int s21_type(node_calc **head) { return (*head)->type; }

int s21_priority(node_calc **head) { return (*head)->priority; }
