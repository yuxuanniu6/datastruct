#define _CRT_SECURE_NO_WARNINGS 1 
#include"stack.h"
int main()
{
	Stack s;
	StackInit(&s);
	StackPush(&s, 1);
	StackPush(&s, 2);
	StackPush(&s, 3);
	StackPush(&s, 4);
	StackPush(&s, 5);
	STDataType x = StackTop(&s);
	printf("%d\n", x);
	//��ջ
	StackPop(&s);
	x = StackTop(&s);
	printf("%d\n", x);
	//��ȡջ����Ч����
	STDataType size = StackSize(&s);
	printf("��Ч������%d\n", size);
	printf("%d\n", !StackEmpty(&s));

	
	return 0;
}