#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include"LinkStack.h"
#include<malloc.h>
void insertSort(int* a, int n);//插入排序
void MergeArray(int* a, int begin, int mid, int end, int* temp);//归并排序
void MergeSort(int* a, int begin, int end, int* temp);//归并递归
void QuickSort_Recursion(int* a, int begin, int end);//递归快速排序





//////////////////////////////////////////////////////
void insertSort(int* a, int n)
{
	int temp; 
	int j = 0;
	for (int i = 1; i < n; i++)
	{
		if (*(a+i)<*(a+i-1))
		{
			temp = *(a + i);
			for (j = i - 1; j >= 0 && temp < *(a + j); j--)
			{
				*(a + j + 1) = *(a + j);
			}
			*(a + j + 1) = temp;
		}

	}


}
void MergeArray(int* a, int begin, int mid, int end, int* temp)
{
	int i = begin;	
	int j = mid + 1;
	int k = begin;
	while (i != mid + 1 && j != end + 1)
	{
		if (*(a+i)>*(a+j)) 
		{
			*(temp + k) = *(a + j);
			k++;
			j++;
		}
		else
		{
			*(temp + k) = *(a + i);
			k++;
			i++;
		}
	}
	while (i!=mid+1)
	{
		*(temp + k) = *(a + i);
		k++;
		i++;
	}	
	while (j!=end+1)
	{
		*(temp + k) = *(a + j);
		k++;
		j++;
	}
	for (int i = begin; i <= end; i++)
	{
		*(a + i) = *(temp + i);
	}
}
void MergeSort(int* a, int begin, int end, int* temp)
{
	int mid = 0;
	if (begin<end)
	{
		 mid = begin + (end - begin) / 2;
		MergeSort(a,begin,mid,temp);
		MergeSort(a,mid+1,end,temp);
		MergeArray(a,begin,mid,end,temp);
	}
	
}

void pswap(int* x, int* y) {
	int temp = *y;
	*y = *x;    //将x指针所指地址的值 赋值给 y指针所指地址；*x相当于一个整数，将其赋值给指针变量所指的地址
	*x = temp;
}

void QuickSort_Recursion(int *a, int begin, int end) {
	int i = begin;
	int j = end;
	if (i >= j) {
		return;
	}

	int temp = *(a+begin);
	while (i != j) {
		while (*(a+j) >= temp && i < j) {
			j--;
		}
		while (*(a+i) <= temp && i < j) {
			i++;
		}
		if (i < j) {
			pswap(a+i, a+j);
		}
	}

	//将基准temp放于自己的位置，（第i个位置）
	pswap(a+begin, a+i);
	QuickSort_Recursion(a, begin, i - 1);
	QuickSort_Recursion(a, i + 1, end);
}
int Partition(int* a, int begin, int end)
{
	int point = *(a + begin);
	while (begin<end)
	{
		while (begin<end&&*(a+end)>=point) 
		{
			end--;
		}
		*(a + begin) = *(a + end);
		while (begin<end&&*(a+begin)<=point)
		{
			begin++;
		}
		int temp = *(a+end);
		*(a + end) = *(a + begin);
		*(a + begin) = temp;
	}
	*(a + begin) = point;
	return begin;
}
void QuickSort(int* a, int size)
{

	int stack[100];
	int top = -1;
	int low = 0;
	int high = size - 1;
	int bou = Partition(a,low,high);
	int l = low;
	int h = high;
	if (low<high)
	{
		stack[++top] = low;
		stack[++top] = bou-1;
		stack[++top] = bou + 1;
		stack[++top] = high;
	}
	while (top>=0)
	{
		high = stack[top--];
		low = stack[top--];
		int mid = (high + low) / 2;
		bou = Partition(a,l,h);
		if (bou-1>l)
		{
			stack[++top] = low;
			stack[++top] = bou - 1;
		}
		if (bou+1<high)
		{
			stack[++top] = bou + 1;
			stack[++top] = high;
		}

	}



}
void CountSort(int* a, int size, int max)
{

	int str[100];
	for (int i = 0; i <= max; i++)
	{
		str[i] = 0;
	}
	for (int i = 0; i < size; i++)
	{
		int p = *(a + i);
		str[p]++;
	}
	int j = 0;
	for (int i = 0; i <= max; i++)
	{
		while (str[i]!=0)
		{
			*(a + j) = i;
			str[i]--;
			j++;
		}
	}


}
void RadixCountSort(int* a, int size)
{
	int max = *a;
	for (int i = 0; i < size; i++)
	{
		if (max < *(a + i))
		{
			max=* (a + i);
		}
	}
	int count1 = max;
	int i; int k;
	int radix = 1;
	for ( i = 0; ; i++)
	{
		count1 = count1 % 10;
		if (count1==0)
		{
			break;
		}
	}
	int* tmp = (int*)malloc(sizeof(int)*size);
	int* count = (int*)malloc(sizeof(int) * 10);
	int m = 2;
	while (m)
	{
		m--;
		for ( i = 0; i < 10; i++)
		{
			count[i] = 0;
		}
		for (int j = 0; j < size; j++)
		{
			k = (*(a + j) / radix) % 10;
			count[k]++;
		}
		for ( i = 1; i < 10; i++)
		{
			count[i] = count[i - 1] + count[i];
		}
		for ( i = size-1; i >=0; i--)
		{
			k = (*(a + i) / radix) % 10;
			tmp[count[k] - 1] = *(a + i);
			count[k]--;
		}
		for ( i = 0; i < size; i++)
		{
			*(a + i) = tmp[i];
		}
		radix = radix * 10;
	}

}