#include <stdio.h>
  

  void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
  }
  
  void heapify(int array[], int n, int i) {
    int largest = i;
    int leftside = 2 * i + 1;
    int rightside = 2 * i + 2;
  
    if (leftside < n && array[leftside] > array[largest])
      largest = leftside;
  
    if (rightside < n && array[rightside] > array[largest])
      largest = rightside;
    if (largest != i) {
      swap(&array[i], &array[largest]);
      heapify(array, n, largest);
    }
  }
  
  void heapSort(int array[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
      heapify(array, n, i);
  
    for (int i = n - 1; i >= 0; i--) {
      swap(&array[0], &array[i]);
      
      heapify(array, i, 0);
    }
  }
  void printarrayay(int array[], int n) {
    for (int i = 0; i < n; ++i)
      printf("%d ", array[i]);
    printf("\n");
  }
  
  int main() {
    int array[] = {8, 1, 5, 15, 7};
    int n = sizeof(array) / sizeof(array[0]);
  
    heapSort(array, n);
  
    printf("Here is the Sorted arrayay: ");
    printarrayay(array, n);
  }