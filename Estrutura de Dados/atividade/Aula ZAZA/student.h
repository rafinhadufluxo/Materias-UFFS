#ifndef _STUDENT
#define _STUDENT
 
typedef struct {
  int p1, p2;
  char *name;
} student;
 
void read_student(student *x);
void write_student(student x);
void free_student(student *x);
 
#endif
