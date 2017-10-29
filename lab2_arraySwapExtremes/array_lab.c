#include <stdio.h>
#include <time.h>
#include <stdlib.h>
//==================
#define ARRAYSIZE 10
#define VALUESIZE 100
//===================
void displayArray (int* array,int size);
void swapArrayExtremes(int* array, int size);
//==================================================================
int main (){
  int input;
  int arr[ARRAYSIZE];
  srand(time(NULL));
  //================Filling in the array
  for (int i =0; i < ARRAYSIZE; i++){
    arr[i] = rand() % VALUESIZE;
  }
  printf("Array generated:\n");
  displayArray(arr, ARRAYSIZE);
  //================Array displayed, ready to operate
  swapArrayExtremes(arr, ARRAYSIZE);
  displayArray(arr, ARRAYSIZE);
  return 0;
}
//==================================================================
void displayArray (int* array,int size){
  for(int i = 0;i < size; i++){
    printf(" %d", array[i]);
  }
  printf("\n");
  return;
}
//=====================================
void swapArrayExtremes(int* array, int size){
  int min = VALUESIZE,max = 0;
  int minAdress = NULL;
  int maxAdress = NULL;
  //Initialised
  for (int i = 0; i < size; i++){
    if (array[i] < min ){
      minAdress = i;
      min = array[i];
    }
    if (array[i]> max){
      maxAdress = i;
      max = array[i];
    }
  }
  //Main loop finished. Min and Max found
  array[minAdress] = max;
  array[maxAdress] = min;
  printf("The biggest number in array is %d at index %d\nThe smallest number in array is %d at index %d\nMin and max swapped\n", max , maxAdress, min, minAdress);
  return;
}