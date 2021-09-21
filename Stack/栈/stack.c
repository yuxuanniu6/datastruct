#define _CRT_SECURE_NO_WARNINGS 1 
#include"stack.h"
#include"Sort.h"
// 初始化栈
void StackInit(Stack* ps)
{
	assert(ps);
	ps->a = NULL;
	ps->top = 0;
	ps->capacity = 0;
}
// 入栈
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
// 出栈
void StackPop(Stack* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));
	--ps->top;
}
// 获取栈顶元素
STDataType StackTop(Stack* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));
	return ps->a[ps->top - 1];
}
// 获取栈中有效元素个数
int StackSize(Stack* ps)
{
	assert(ps);
	return ps->top;
}
// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0
int StackEmpty(Stack* ps)
{
	assert(ps);
	return ps->top == 0;
}
// 销毁栈
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
