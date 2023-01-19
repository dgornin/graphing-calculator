#include "graph.h"
#include "stack.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *get_not();
void draw();
void draw(int (*matrix)[RIGHT_BORDER]);
double count(char * not, double x);
int get_pr(char a);

int main() {
  char *not = get_not();
  int matrix[DOWN_BORDER][RIGHT_BORDER];
  for (int i = 0; i < DOWN_BORDER; i++) {
    for (int j = 0; j < RIGHT_BORDER; j++) {
      matrix[i][j] = 0;
    }
  }
  double step = (M_PI * 4) / 79.0;
  printf("%s", not);
  printf("\n");
  for (int i = 0; i < 80; i++) {
    double y = count(not, step * i);
    if (y >= -1.0 && y <= 1.0) {
      double y_step = 1.0 / 12.0;
      for (int j = -12; j < 11; j++) {
        if (y >= y_step * j && y <= y_step * (j + 1)) {
          matrix[j + 12][i] = 1;
        }
      }
    }
  }
  draw(matrix);
  free(not);
  return 0;
}

void draw(int (*matrix)[RIGHT_BORDER]) {
  for (int i = 0; i < DOWN_BORDER; i++) {
    for (int j = 0; j < RIGHT_BORDER; j++) {
      if (matrix[i][j] == 0) {
        printf(".");
      } else {
        printf("*");
      }
    }
    printf("\n");
  }
}

char *get_not() {
  char *num = malloc(1000 * sizeof(char));
  char *buf = malloc(1000 * sizeof(char));
  char tmp[100];
  int l = 0;
  struct stack *head = init();
  char c = getchar();
  while (c != '\n') {
    buf[l] = c;
    l++;
    c = getchar();
  }
  buf[l] = '\0';
  int num_l = 0;
  for (int i = 0; i < l; i++) {
    if ((buf[i] >= '0' && buf[i] <= '9') || buf[i] == 'x') {
      if (i > 0 && buf[i - 1] == '-') {
        if (i == 1) {
          num[num_l] = '-';
          num_l++;
          pop(head);
        } else if (buf[i - 2] == '(') {
          num[num_l] = '-';
          num_l++;
          pop(head);
        }
      }
      int j = 0;
      while ((buf[i + j] >= '0' && buf[i + j] <= '9') || buf[i + j] == '.' ||
             buf[i + j] == 'x') {
        tmp[j] = buf[i + j];
        j++;
      }
      for (int k = 0; k < j; k++) {
        num[num_l] = tmp[k];
        num_l++;
      }
      num[num_l] = ' ';
      num_l++;
      i += j - 1;
    } else if (buf[i] == '+' || buf[i] == '-') {
      if (head->top > 0) {
        if (get_pr(head->data[head->top - 1]) > 1) {
          while (head->top != 0 && (get_pr(head->data[head->top - 1]) > 1)) {
            num[num_l] = pop(head);
            num_l++;
            num[num_l] = ' ';
            num_l++;
          }
          push(head, buf[i]);
        } else {
          push(head, buf[i]);
        }
      } else {
        push(head, buf[i]);
      }
    } else if (buf[i] == '*' || buf[i] == '/' || buf[i] == '(') {
      push(head, buf[i]);
    } else if (buf[i] == ')') {
      while (head->top != 0 && head->data[head->top - 1] != '(') {
        num[num_l] = pop(head);
        num_l++;
        num[num_l] = ' ';
        num_l++;
      }
      pop(head);
    }
  }
  while (head->top > 0) {
    num[num_l] = pop(head);
    num_l++;
    num[num_l] = ' ';
    num_l++;
  }
  num[num_l] = '\0';
  free(buf);
  destroy(&head);
  return num;
}

int get_pr(char a) {
  int ans = 0;
  if (a == '+' || a == '-') {
    ans = 1;
  } else if (a == '*' || a == '/') {
    ans = 2;
  }
  return ans;
}

double count(char * not, double x) {
  char buf[1000];
  strcpy(buf, not);
  char *del = strtok(buf, " ");
  struct stack_c *head = init_c();
  double a, b;
  while (del != NULL) {
    if (del[0] >= '0' && del[0] <= '9') {
      push_c(head, atof(del));
    }
    if (del[0] >= 'x') {
      push_c(head, x);
    }
    if (del[0] == '+') {
      a = pop_c(head);
      b = pop_c(head);
      push_c(head, a + b);
    }
    if (del[0] == '-') {
      a = pop_c(head);
      b = pop_c(head);
      push_c(head, b - a);
    }
    if (del[0] == '*') {
      a = pop_c(head);
      b = pop_c(head);
      push_c(head, a * b);
    }
    if (del[0] == '/') {
      a = pop_c(head);
      b = pop_c(head);
      push_c(head, b / a);
    }
    del = strtok(NULL, " ");
  }
  double ans = pop_c(head);
  destroy_c(&head);
  return ans;
}
