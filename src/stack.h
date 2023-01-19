#ifndef SRC_STACK_H_
#define SRC_STACK_H_

#define SIZE 10

struct stack {
    char *data;
    int size;
    int top;
};

struct stack_c {
    double *data;
    int size;
    int top;
};

struct stack* init();
void chage_size(struct stack *stack);
void destroy(struct stack **stack);
void push(struct stack *stack, char value);
char pop(struct stack *stack);

struct stack_c* init_c();
void chage_size_c(struct stack_c *stack);
void destroy_c(struct stack_c **stack);
void push_c(struct stack_c *stack, double value);
double pop_c(struct stack_c *stack);

#endif  // SRC_STACK_H_
