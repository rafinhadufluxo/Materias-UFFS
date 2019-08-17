#include <stdio.h>

/* codigo de busca binaria em ordem crescente */


int binary_search(int values[], int start, int last_index, int target) {
  int pivot = (start + last_index) / 2;
  int actual_item = values[pivot];

  printf("AA %d \n", pivot);
  if(actual_item == target) {
    return pivot;
  } else if ((last_index == 0) || start == last_index){
    return -1;
  } else if (actual_item > target) {
    return binary_search(values, start, pivot, target);
  } else if (actual_item < target) {
    return binary_search(values, pivot + 1, last_index, target);
  }
  return -1;
}

int main(void){
  int array[] = {1, 3, 5, 6, 7, 8, 10, 12, 15, 17, 18, 19, 20, 21};
  int size = sizeof(array) / sizeof(array[0]);
  int result;
  result = binary_search(array, 0, size - 1, 7);
  printf("AQUI: %d\n", result);
  return 0;
}
