#include"student.h"
 
int main(void) {
  student x;
  read_student(&x);
  write_student(x);
  free_student(&x);
  return 0;
}
