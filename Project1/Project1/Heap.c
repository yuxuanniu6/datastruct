#define _CRT_SECURE_NO_WARNINGS 1 
#include"Heap.h"
void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
// 左右子树都是大小堆，向下调整法
void AdjustDown(int* a, int n, int parent)
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (a[child] > a[child + 1] && child + 1 < n)
		{
			++child; // 如果右孩子大于左孩子，就+1 ->右孩子
		}
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			break;
	}
}
// 升序->大堆
// 降序->小堆
void HeapSort(int* a, int n)
{
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(a, n, i);
	}
	int end = n - 1; // 排序  向下调整
	while (end)
	{
		Swap(&a[0], &a[end]);// 将最值 放置末尾
		AdjustDown(a, end, 0);
		--end;
	}
}
void AdjustUp(int* a, int child)
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}
void HeapInit(Heap* hp, HPDataType* a, int n)
{
	assert(hp);
	hp->_a = (HPDataType*)malloc(sizeof(HPDataType) * n);
	if (hp->_a == NULL)
	{
		perror("HeapInit error");
		return;
	}
	memcpy(hp->_a, a, sizeof(HPDataType) * n); // 将数组的字节复制给结构体的_a
	// 建堆
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(hp->_a, n, i);
		//AdjustUp(hp->_a, n - 1);
	}
	hp->_capacity = n;
	hp->_size = n;
}
void HeapPush(Heap* hp, HPDataType x)
{
	assert(hp);
	// 检验是否满了
	if (hp->_size == hp->_capacity)
	{
		// 重新分配内存
		HPDataType* tmp= (HPDataType*)realloc(hp->_a, sizeof(HPDataType) * 2 * hp->_capacity);
		if (tmp == NULL)
		{
			perror("Push realloc!");
			exit(-1);
		}
		hp->_a = tmp;
		hp->_capacity *= 2;
	}
	hp->_a[hp->_size] = x;
	hp->_size++;
	AdjustUp(hp->_a, hp->_size - 1); // 插入，向上调整
}
void HeapPop(Heap* hp)
{
	assert(hp);
	assert(!HeapEmpty(hp));
	Swap(&hp->_a[0], &hp->_a[hp->_size - 1]);
	--hp->_size;
	AdjustDown(hp->_a, hp->_size, 0); // 删除，向下进行调整
}
void HeapDestory(Heap* hp)
{
	assert(hp);
	free(hp->_a);
	hp->_a = NULL;
	hp->_size = hp->_capacity = 0;
}

// 取堆顶的数据
HPDataType HeapTop(Heap* hp)
{
	assert(hp);
	assert(!HeapEmpty(hp));
	return hp->_a[0];
}
// 堆的数据个数
int HeapSize(Heap* hp)
{
	assert(hp);
	return hp->_size;
}
// 堆的判空
int HeapEmpty(Heap* hp)
{
	assert(hp);
	return hp->_size == 0;
}
void HeapPrint(Heap* hp)
{
	assert(hp);
	for (int i = 0; i < hp->_size; ++i)
	{
		printf("%d ", hp->_a[i]);
	}
	printf("\n");
}
void PrintTopK(int* a, int n, int k)
{
	Heap hp;
	HeapInit(&hp, a, k);

	for (int i = k; i < n; ++i)
	{
		if (a[i] > HeapTop(&hp))
		{
			HeapPop(&hp);
			HeapPush(&hp, a[i]);
		}
	}
	HeapPrint(&hp);
	HeapDestory(&hp);
}
void TestTopk()
{
	//数据集合中找最大值 建小堆
	//			找最小值 建大堆
	int n = 10000;
	int* a = (int*)malloc(sizeof(int) * n);
	srand(time(0));
	for (size_t i = 0; i < n; ++i)
	{
		a[i] = rand() % 1000000;
	}
	a[5] = 1000000 + 1;
	a[1231] = 1000000 + 2;
	a[531] = 1000000 + 3;
	a[5121] = 1000000 + 4;
	a[115] = 1000000 + 5;
	a[2335] = 1000000 + 6;
	a[9999] = 1000000 + 7;
	a[76] = 1000000 + 8;
	a[423] = 1000000 + 9;
	a[3144] = 1000000 + 10;
	PrintTopK(a, n, 10);
}