#define _CRT_SECURE_NO_WARNINGS 1 
#include"Sort.h"
int main()
{
	int a[] = { 2,2,5,2,2,3,6,5,3 };
	int n = sizeof(a) / sizeof(a[0]);
	//InsertSort(a, n);
	//PrintArray(a, n);
	
	//ShellSort(a, n);
	//PrintArray(a, n);

	//SelectSort(a, n);
	//PrintArray(a, n);

	/*HeapSort(a, n);
	PrintArray(a, n);*/

	//BubbleSort(a, n);
	//PrintArray(a, n);

	//QuickSort(a, 0, n - 1);
	//PrintArray(a, n);

	/*QuickSort(a, 0, n - 1);
	PrintArray(a, n);*/

	//QuickSortNonR(a, 0, n - 1);
	//PrintArray(a, n);

	//MergeSort(a, n);
	//PrintArray(a, n);

	//MergeSortNonR(a, n);
	//PrintArray(a, n);

	CountSort(a, n);
	PrintArray(a, n);
	return 0;
}
