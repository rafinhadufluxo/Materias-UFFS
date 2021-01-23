#include<stdio.h>
#include<stdlib.h>
#include"student.h"
 
void read_student(student *x) {
  int n;
  char c;
  scanf("%d %d ", &x->p1, &x->p2);
  x->name = NULL; n = 0;
  do {
    x->name = (char *)realloc(x->name, (++n) * sizeof(char));
    x->name[n - 1] = (c = getchar()) == '\n' ? '\0' : c;
  } while (c != '\n');
}
 
void write_student(student x) {
  printf("%s %d %d\n", x.name, x.p1, x.p2);
}
 
void free_student(student *x) {
  free(x->name);
  x->name = NULL;
}
