#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include"sort.h"
#define Max 15

#include <stdlib.h>

void quick_sort_iterative(int arr[], int low, int high) {
    int stack[100];
    int top = -1;

    if (low < high) {
        stack[++top] = low;
        stack[++top] = high;
    }

    while (top >= 0) {
        high = stack[top--];
        low = stack[top--];

        int pivot_index = (low + high) / 2;
        int pivot = arr[pivot_index];
        int partition_index = low;

        int i = low;
        int j = high;

        while (i <= j) {
            while (arr[i] < pivot) {
                i++;
            }

            while (arr[j] > pivot) {
                j--;
            }

            if (i < j) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
            else {
                break;
            }
        }

        if (j > partition_index) {
            int temp = arr[partition_index];
            arr[partition_index] = arr[j];
            arr[j] = temp;
        }

        if (j - 1 > low) {
            stack[++top] = low;
            stack[++top] = j - 1;
        }

        if (j + 1 < high) {
            stack[++top] = j + 1;
            stack[++top] = high;
        }
    }
}






void main()
{
	int temp[Max];
	int str[Max] = {44,3,38,5,47,15,36,26,27,2,46,4,19,50,48};
	printf("ÅÅÐòÇ°£º");
	for (int i = 0; i < Max; i++)
	{
		printf("%d  ",str[i]);
	}
	printf("\nÅÅÐòºó£º");

	//insertSort(str,Max);
	//MergeArray(str,0,0+(Max-0)/2,Max-1,temp);
	//MergeSort(str,0,Max-1,temp);
	//QuickSort_Recursion(str,0,Max-1);
	//QuickSort(str,15);
    //quick_sort_iterative(str,0,14);
   // CountSort(str,Max,50);
    RadixCountSort(str,Max);
	for (int i = 0; i < Max; i++)
	{
		printf("%d  ", str[i]);
	}


}