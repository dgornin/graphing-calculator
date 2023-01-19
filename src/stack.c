#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

struct stack *init() {
  struct stack *head = NULL;
  head = malloc(sizeof(struct stack));
  head->size = SIZE;
  head->data = malloc(head->size * sizeof(char));
  head->top = 0;
  return head;
}

void chage_size(struct stack *stack) {
  stack->size *= 2;
  stack->data = realloc(stack->data, stack->size * sizeof(char));
}

void destroy(struct stack **stack) {
  free((*stack)->data);
  free(*stack);
}

void push(struct stack *stack, char value) {
  if (stack->top >= stack->size) {
    chage_size(stack);
  }
  stack->data[stack->top] = value;
  stack->top += 1;
}

char pop(struct stack *stack) {
  stack->top -= 1;
  return stack->data[stack->top];
}

struct stack_c *init_c() {
  struct stack_c *head = NULL;
  head = malloc(sizeof(struct stack_c));
  head->size = SIZE;
  head->data = malloc(head->size * sizeof(double));
  head->top = 0;
  return head;
}

void chage_size_c(struct stack_c *stack) {
  stack->size *= 2;
  stack->data = realloc(stack->data, stack->size * sizeof(double));
}

void destroy_c(struct stack_c **stack) {
  free((*stack)->data);
  free(*stack);
}

void push_c(struct stack_c *stack, double value) {
  if (stack->top >= stack->size) {
    chage_size_c(stack);
  }
  stack->data[stack->top] = value;
  stack->top += 1;
}

double pop_c(struct stack_c *stack) {
  stack->top -= 1;
  return stack->data[stack->top];
}
