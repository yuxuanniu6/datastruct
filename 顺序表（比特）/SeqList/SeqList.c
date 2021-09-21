#define _CRT_SECURE_NO_WARNINGS 1 
#include"SeqList.h"
//��ʼ��
void SeqListInit(SeqList* ps)
{
	assert(ps);
	ps->a = NULL;
	ps->Capacity = 0;
	ps->size = 0;
}
void SeqListDestory(SeqList* ps)
{
	if (ps->a)
	{
		free(ps->a);
		ps->a = NULL;
	}
	ps->Capacity = 0;
	ps->size = 0;
}
void SeqListPrint(SeqList* ps)
{
	assert(ps);
	for (size_t i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}
//β��
void SeqListPushBack(SeqList* ps, SLDataType x)
{
	assert(ps);
	SeqListCheckCapacity(ps);
	ps->a[ps->size] = x;
	ps->size++;
}
//βɾ
void SeqListPopBack(SeqList* ps)
{
	assert(ps);
	ps->size--;
}
//ͷ��
void SeqListPushFront(SeqList* ps, SLDataType x)
{
	assert(ps);
	SeqListCheckCapacity(ps);
	size_t end = ps->size;
	while (end > 0)
	{
		ps->a[end] = ps->a[end - 1];
		--end;
	}
	ps->a[0] = x;
	ps->size++;
}
//ͷɾ
void SeqListPopFront(SeqList* ps)
{
	assert(ps);
	size_t begin = 1;
	while (begin < ps->size)
	{
		ps->a[begin-1] = ps->a[begin];
		++begin;
	}
	ps->size--;
}
void SeqListCheckCapacity(SeqList* ps)
{
	assert(ps);
	if (ps->size == ps->Capacity)
	{
		size_t newCapacity = ps->Capacity == 0 ? 4 : ps->Capacity * 2;
		SLDataType*ps1 = (SLDataType*)realloc(ps->a, newCapacity * sizeof(SLDataType));
		if (ps1==NULL)
		{
			perror("realloc");
			return;
		}
		ps->a = ps1;
		ps->Capacity = newCapacity;
		
	}
}
//���ң��ҵ���������
int SeqListFind(SeqList* ps, SLDataType x)
{
	assert(ps);
	size_t begin = 0;
	while (begin < ps->size)
	{
		if (ps->a[begin] == x)
			return begin;
		begin++;
	}
	return -1;
}
// ˳�����posλ�ò���x
void SeqListInsert(SeqList* ps, size_t pos, SLDataType x)
{
	assert(ps);
	assert(pos <= ps->size && pos >= 0);
	SeqListCheckCapacity(ps);
	/*size_t end = ps->size - 1;
	while (end >= (int)pos)
	{
		ps->a[end + 1] = ps->a[end];
		--end;
	}*/
	size_t end = ps->size;
	while (end > pos)
	{
		ps->a[end] = ps->a[end - 1];
		--end;
	}
	ps->a[pos] = x;
	ps->size++;
}
// ˳���ɾ��posλ�õ�ֵ
void SeqListErase(SeqList* ps, size_t pos)
{
	assert(ps);
	assert(pos < ps->size && pos >= 0);
	/*size_t begin = pos + 1;
	while (begin < ps->size)
	{
		ps->a[begin - 1] = ps->a[begin];
		++begin;
	}*/
	size_t begin = pos;
	while (begin < ps->size - 1)
	{
		ps->a[begin] = ps->a[begin + 1];
		++begin;
	}
	ps->size--;
}