#define _CRT_SECURE_NO_WARNINGS 1 
#include"Queue.h"
int main()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QDataType x = QueueFront(&q);
	printf("%d\n", x);
	x = QueueBack(&q);
	printf("%d\n", x);
	printf("%d\n", QueueSize(&q));
	QueuePop(&q);
	printf("%d\n", QueueSize(&q));
	int a = 6;
	int m = 0;
	m = a & -a;
	printf("%d\n", -2&-3);
	return 0;
}