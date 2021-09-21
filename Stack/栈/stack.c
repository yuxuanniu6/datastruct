#define _CRT_SECURE_NO_WARNINGS 1 
#include"stack.h"
#include"Sort.h"
// ��ʼ��ջ
void StackInit(Stack* ps)
{
	assert(ps);
	ps->a = NULL;
	ps->top = 0;
	ps->capacity = 0;
}
// ��ջ
void StackPush(Stack* ps, STDataType data)
{
	assert(ps);
	if (ps->top == ps->capacity)
	{
		STDataType newcapacity = ps->capacity == 0 ? 4 : 2 * ps->capacity;
		STDataType* ps1 = (STDataType*)realloc(ps->a, newcapacity * sizeof(STDataType));
		if (ps1 == NULL)
		{
			perror("realloc");
			exit(-1);
		}
		ps->a = ps1;
		ps->capacity = newcapacity;
	}
	ps->a[ps->top] = data;
	ps->top++;
}
// ��ջ
void StackPop(Stack* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));
	--ps->top;
}
// ��ȡջ��Ԫ��
STDataType StackTop(Stack* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));
	return ps->a[ps->top - 1];
}
// ��ȡջ����ЧԪ�ظ���
int StackSize(Stack* ps)
{
	assert(ps);
	return ps->top;
}
// ���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط������������Ϊ�շ���0
int StackEmpty(Stack* ps)
{
	assert(ps);
	return ps->top == 0;
}
// ����ջ
void StackDestroy(Stack* ps)
{
	assert(ps);
	if (ps->a)
	{
		free(ps->a);
	}
	ps->a = NULL;
	ps->top = 0;
	ps->capacity = 0;
}
