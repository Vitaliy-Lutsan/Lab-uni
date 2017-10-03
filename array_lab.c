#include <stdio.h>
#include <time.h>
#include <stdlib.h>
//==================
#define ARRAYSIZE 10
#define VALUESIZE 100
//===================
void displayArray (int* array,int size);
void displayArraySorted(int* array, int size);
void displayArrayExtremes(int* array, int size);
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
  //================Array displayed, ready to schtuff
  displayArraySorted(arr, ARRAYSIZE);
  displayArrayExtremes(arr, ARRAYSIZE);
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
void displayArraySorted(int* array, int size){
  int odd[size], even[size];
  int sizeOfOdd = 0, sizeOfEven = 0;
  for(int j = 0; j < size; j++){
    if (array[j] % 2 ) {
      odd[sizeOfOdd] = array[j];
      sizeOfOdd+=1;
    }
    else{
      even[sizeOfEven] = array[j];
      sizeOfEven+=1;
    }
  }
  //==============
  printf("Odd elements in the array are:\n");
  displayArray(odd, sizeOfOdd);
  printf("Even elements of the array are:\n");
  displayArray(even, sizeOfEven);
  return;
}
//===================================
void displayArrayExtremes(int* array, int size){
  int min = VALUESIZE,max = 0;
  for (int i = 0; i < size; i++){
    min = (array[i] < min )? array[i] : min;
    max = (array[i]> max) ? array [i] : max;
  }
  printf("The biggest number in array is %d\nThe smallest number in array is %d\n", max , min);
  return;
}