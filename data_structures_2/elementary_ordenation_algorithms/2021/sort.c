#include "sort.h"

void swap(int *array, int index1, int index2){
   int tmp = array[index1];
   array[index1] = array[index2];
   array[index2] = tmp;

   return;
} // end swap

int findPivot(int *array, int leftIndex, int rightIndex){
   int i = leftIndex, j = rightIndex - 1;
   int reference = array[rightIndex];
   char left = 0b00000000, right = 0b00000000;

   for( ; i <= j; ){
      left  =  array[i] >  reference ? 0b00000001 : 0b00000000;
      right =  array[j] <= reference ? 0b00000001 : 0b00000000;

      if(left & right){
         swap(array, i, j);
         i++; j--;
      } else if(left & (!right)){
         j--;
      } else if((!left) & right){
         i++;
      } else {
         i++; j--;
      }
   }
   swap(array, i, rightIndex);

   return i;
} //end findPivot

void useMedianOfThree(int *array, int leftIndex, int rightIndex){
   int middleIndex = (rightIndex + leftIndex) / 2;

   if(array[rightIndex] < array[middleIndex])
      swap(array, middleIndex, rightIndex);
   
   if(array[middleIndex] < array[leftIndex])
      swap(array, middleIndex, leftIndex);

   if(array[middleIndex] < array[rightIndex])
      swap(array, middleIndex, rightIndex);

   return;
} // end useMedianOfThree

void quickSort(int *array, int leftIndex, int rightIndex){
   if(leftIndex >= rightIndex)
      return;

   useMedianOfThree(array, leftIndex, rightIndex);
   int pivotIndex = findPivot(array, leftIndex, rightIndex);

   quickSort(array, leftIndex, pivotIndex-1);
   quickSort(array, pivotIndex+1, rightIndex);

   return;
} // end quickSort