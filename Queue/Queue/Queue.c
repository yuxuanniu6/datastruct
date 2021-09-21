#define _CRT_SECURE_NO_WARNINGS 1 
#include"Queue.h"
// ��ʼ������ 
void QueueInit(Queue* q)
{
	assert(q);
	q->front = q->rear = NULL;
}
// ��β����� 
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
	if (q->rear == NULL)//Ϊ��
	{
		q->front = q->rear = newnode;
	}
	else
	{
		q->rear->next = newnode;
		q->rear = newnode;
	}
}
// ��ͷ������ 
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
// ��ȡ����ͷ��Ԫ�� 
QDataType QueueFront(Queue* q)
{
	assert(q);
	assert(!QueueEmpty(q));
	return q->front->data;
}
// ��ȡ���ж�βԪ�� 
QDataType QueueBack(Queue* q)
{
	assert(q);
	assert(!QueueEmpty(q));
	return q->rear->data;
}
// ��ȡ��������ЧԪ�ظ��� 
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
// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
int QueueEmpty(Queue* q)
{
	assert(q);
	return q->front == NULL && q->rear == NULL;
}
// ���ٶ��� 
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