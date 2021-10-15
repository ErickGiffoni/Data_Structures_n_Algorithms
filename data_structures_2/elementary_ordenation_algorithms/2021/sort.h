#ifndef SORT_H
#define SORT_H

void  swap(int *array, int index1, int index2);
int   findPivot(int *array, int leftIndex, int rightIndex);
void  useMedianOfThree(int *array, int leftIndex, int rightIndex);
void  quickSort(int *array, int leftIndex, int rightIndex);
void  merge(int *array, int leftIndex, int middleIndex, int rightIndex);
void  mergeSort(int *array, int leftIndex, int rightIndex);

#endif