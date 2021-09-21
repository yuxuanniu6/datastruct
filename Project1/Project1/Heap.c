#define _CRT_SECURE_NO_WARNINGS 1 
#include"Heap.h"
void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
// �����������Ǵ�С�ѣ����µ�����
void AdjustDown(int* a, int n, int parent)
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (a[child] > a[child + 1] && child + 1 < n)
		{
			++child; // ����Һ��Ӵ������ӣ���+1 ->�Һ���
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
// ����->���
// ����->С��
void HeapSort(int* a, int n)
{
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(a, n, i);
	}
	int end = n - 1; // ����  ���µ���
	while (end)
	{
		Swap(&a[0], &a[end]);// ����ֵ ����ĩβ
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
	memcpy(hp->_a, a, sizeof(HPDataType) * n); // ��������ֽڸ��Ƹ��ṹ���_a
	// ����
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
	// �����Ƿ�����
	if (hp->_size == hp->_capacity)
	{
		// ���·����ڴ�
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
	AdjustUp(hp->_a, hp->_size - 1); // ���룬���ϵ���
}
void HeapPop(Heap* hp)
{
	assert(hp);
	assert(!HeapEmpty(hp));
	Swap(&hp->_a[0], &hp->_a[hp->_size - 1]);
	--hp->_size;
	AdjustDown(hp->_a, hp->_size, 0); // ɾ�������½��е���
}
void HeapDestory(Heap* hp)
{
	assert(hp);
	free(hp->_a);
	hp->_a = NULL;
	hp->_size = hp->_capacity = 0;
}

// ȡ�Ѷ�������
HPDataType HeapTop(Heap* hp)
{
	assert(hp);
	assert(!HeapEmpty(hp));
	return hp->_a[0];
}
// �ѵ����ݸ���
int HeapSize(Heap* hp)
{
	assert(hp);
	return hp->_size;
}
// �ѵ��п�
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
	//���ݼ����������ֵ ��С��
	//			����Сֵ �����
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