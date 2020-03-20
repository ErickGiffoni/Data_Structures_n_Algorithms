/*
* University of Brasilia - Brazil, UnB
* Software Engineering
* Created by Erick Giffoni Felicíssimo on <date> .
* Copyright © 2020 Erick Giffoni Felicíssimo . All rights reserved.
*/

#include <stdio.h>
#include <stdlib.h>

#define item int
#define less(a, b) (a < b)
#define less_equal(a, b) (a <= b)
#define exch(a, b) \
    {              \
        item t;    \
        t = a;     \
        a = b;     \
        b = t;     \
    }
#define cmp_exch(a, b)  \
    {                   \
        if (less(a, b)) \
            exch(a, b); \
    }

void selection_sort(item *v, int left_index, int right_index){
    for(int i = left_index; i<=right_index; i++){
        int smallest = i; //smallest number in array v is set to i index
        for(int j = i+1; j<=right_index; j++){
            if(less(v[j], v[smallest]))
               smallest = j; 
        }// end internal for
        exch(v[smallest], v[i]);
    }// end external for
}

int main(){

     int array_size = 0;
     printf("Which size is your array ?\n");
     scanf("%d", &array_size);

     if(array_size){
         int *array = (int *) calloc(array_size, sizeof(int));
         int left_index = 0;
         int right_index = array_size - 1;
         printf("Please, type the array numbers, one by one,\nfollowed by an enter :\n");
        for(int i = 0; i<array_size; i++){
            scanf("%d", &array[i]); //scans the array numbers
        }// end for scan
        printf("\n\nYour array is as follows : \n\n");
        for(int i = 0; i<array_size; i++){
            printf("%d ", array[i]); //prints the array
        }// end for print
        printf("\n\nNow, SELECTION SORT ALGORITHM will organize your array...\n\njust a sec...\n\n");

        selection_sort(array, left_index, right_index);

        for(int i = 0; i<array_size; i++){
            printf("%d ", array[i]); //prints the array
        }// end for print

        printf("\n\nThank you !\n");
        free(array);

        return 0;

     }// end if

     printf("Sorry, but your array size must be 1 or more...\n\nTry again later!\n");

    return 0;
}