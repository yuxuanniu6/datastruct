#define _CRT_SECURE_NO_WARNINGS 1 
#include"Queue.h"
// 初始化队列 
void QueueInit(Queue* q)
{
	assert(q);
	q->front = q->rear = NULL;
}
// 队尾入队列 
void QueuePush(Queue* q, QDataType data)
{
	assert(q);
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if (newnode == NULL)
	{
		perror("Push");
		exit(-1);
	}
	newnode->data = data;
	newnode->next = NULL;
	if (q->rear == NULL)//为空
	{
		q->front = q->rear = newnode;
	}
	else
	{
		q->rear->next = newnode;
		q->rear = newnode;
	}
}
// 队头出队列 
void QueuePop(Queue* q)
{
	assert(q);
	assert(!QueueEmpty(q));
	if (q->front->next == NULL)
	{
		free(q->front);
		q->front = q->rear = NULL;
	}
	else
	{
		QNode* next = q->front->next;
		free(q->front);
		q->front = next;
	}
}
// 获取队列头部元素 
QDataType QueueFront(Queue* q)
{
	assert(q);
	assert(!QueueEmpty(q));
	return q->front->data;
}
// 获取队列队尾元素 
QDataType QueueBack(Queue* q)
{
	assert(q);
	assert(!QueueEmpty(q));
	return q->rear->data;
}
// 获取队列中有效元素个数 
int QueueSize(Queue* q)
{
	assert(q);
	int len = 0;
	QNode* cur = q->front;
	while (cur)
	{
		len++;
		cur = cur->next;
	}
	return len;
}
// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
int QueueEmpty(Queue* q)
{
	assert(q);
	return q->front == NULL && q->rear == NULL;
}
// 销毁队列 
void QueueDestroy(Queue* q)
{
	assert(q);
	QNode* cur = q->front;
	while (cur)
	{
		QNode* next = cur->next;
		free(cur);
		cur = next;
	}
	q->front = q->rear = NULL;
}