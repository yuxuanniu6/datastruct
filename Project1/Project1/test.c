#define _CRT_SECURE_NO_WARNINGS 1 
#include"Heap.h"
void test01()
{
	int a[] = { 15,18,19,25,28,34,65,49,27,37 };
	int n = sizeof(a) / sizeof(a[0]);
	//HeapSort(a, n); // ∂—≈≈–Ú
	Heap hp;
	HeapInit(&hp, a, n);
	//AdjustUp(a, n - 1);
	HeapPush(&hp, 10);
	HeapPrint(&hp);

	HeapPop(&hp);
	HeapPrint(&hp);
}
void test02()
{
	TestTopk();
}
int main()
{
	//test01();
	test02();
	return 0;
}