#define _CRT_SECURE_NO_WARNINGS 1 
#define _CRT_SECURE_NO_WARNINGS 1 
#include"SListNode.h"
//��ʼ��  β��  ͷ��  ѡ��һ������
//��ʼ��
void SListInit(SLTNode** phead)
{
	assert(phead);
	*phead = (SLTNode*)malloc(sizeof(SLTNode));
	if (*phead == NULL)
	{
		perror("SListInit");
		return;
	}
	(*phead) = NULL;
}
//�����ڵ�
SLTNode* BuySListNode(SLTDataType x)
{
	SLTNode* node = (SLTNode*)malloc(sizeof(SLTNode));
	if (node == NULL)
	{
		perror("BuySListNode");
		exit(-1);
	}
	node->data = x;
	node->next = NULL;
	return node;
}
//����
void SListPrint(SLTNode* phead)
{
	SLTNode* p = phead;
	while (p)
	{
		printf("%d->", p->data);
		p = p->next;
	}
	printf("NULL\n");
}
//β��
void SListPushBack(SLTNode** pphead, SLTDataType x)
{
	assert(pphead);
	if (*pphead == NULL)
	{
		SLTNode* newnode = BuySListNode(x);//�����½ڵ�
		*pphead = newnode;//���½ڵ��ַ��ͷ�ڵ�
	}
	else
	{
		SLTNode* tail = *pphead;
		//���нڵ����ʱ
		while (tail->next)
		{
			tail = tail->next;
		}
		SLTNode* newnode = BuySListNode(x);
		tail->next = newnode;
	}
}
//ͷ��
void SListPushFront(SLTNode** pphead, SLTDataType x)
{
	assert(pphead);
	SLTNode* newnode = BuySListNode(x);
	newnode->next = *pphead;//ָ���һ���ڵ�
	*pphead = newnode;//newnode��ַ��pphead��Ϊ��һ���ڵ�
}
void SListPopBack(SLTNode** pphead)
{
	assert(pphead);
	//������ʽ
	assert(*pphead);//��������Ƿ�Ϊ��
	//�ºͷ�ʽ
	/*if (*pphead == NULL)
	{
		return;
	}*/
	SLTNode* prev = NULL;
	SLTNode* tail = *pphead;
	if (tail->next == NULL)
	{
		free(tail);
		tail = NULL;
	}
	else
	{
		while (tail->next != NULL)
		{
			prev = tail;
			tail = tail->next;
		}
		free(tail);
		prev->next = NULL;
	}
}
void SListPopFront(SLTNode** pphead)
{
	assert(pphead);
	assert(*pphead);
	SLTNode* nextnode = (*pphead)->next;
	*pphead = nextnode;
	free(*pphead);
	*pphead = NULL;
}
size_t SListSize(SLTNode* phead)
{
	size_t size = 0;
	SLTNode* cur = phead;
	while (cur)
	{
		size++;
		cur = cur->next;
	}
	return size;
}
bool SListEmpty(SLTNode* phead)
{
	return phead == NULL ? false : true;
}
SLTNode* SListFind(SLTNode** pphead, SLTDataType x)
{
	assert(pphead);
	SLTNode* cur = *pphead;
	while (cur)
	{
		if (cur->data == x)
		{
			return cur;
		}
		else
		{
			cur = cur->next;
		}
	}
	return NULL;
}
//��posλ��֮ǰȥ����
void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x)
{
	assert(pphead);
	assert(pos);//����
	/*if (pos == NULL)//���ᴦ��ʽ
	{
		perror("pos");
		return;
	}*/
	if (*pphead == pos)
	{
		SListPushFront(pphead, x);
	}
	else
	{
		SLTNode* cur = *pphead;
		while (cur->next != pos)
		{
			cur = cur->next;
		}
		SLTNode* newnode = BuySListNode(x);
		newnode->next = pos;
		cur->next = newnode;
	}
}
//��posλ��֮�����
void SListInsertAfter(SLTNode* pos, SLTDataType x)
{
	assert(pos);
	SLTNode* newnode = BuySListNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}
void SListErase(SLTNode** pphead, SLTNode* pos)
{
	assert(pphead);
	assert(pos);
	if (*pphead == pos)
	{
		SListPopBack(pphead);
	}
	else
	{
		SLTNode* nextnode = *pphead;
		while (nextnode->next != pos)
		{
			nextnode = nextnode->next;
		}
		nextnode->next = pos->next;//pos��ǰһ���ڵ�ָ��pos�ĺ�һ���ڵ�
		free(pos);
		pos = NULL;
	}
}
void SListEraseAfter(SLTNode* pos)
{
	assert(pos);
	assert(pos->next);
	/*SLTNode* nextnode = pos->next->next;
	pos->next = nextnode;
	free(pos->next);
	*/
	SLTNode* nextnode = pos->next;
	pos->next = pos->next->next;
	free(nextnode);
	nextnode = NULL;
}
void SListDestory(SLTNode** pphead)
{
	assert(pphead);
	SLTNode* cur = *pphead;
	while (cur)
	{
		SLTNode* next = cur->next;
		free(cur);
		cur = next;
	}
	*pphead = NULL;
}
SLTNode* reverseList(SLTNode** head)
{
	SLTNode* cur = *head;
	SLTNode* newhead = NULL;
	SLTNode* next = NULL;
	while (cur)
	{
		next = cur->next;
		cur->next = newhead;
		newhead = cur;
		cur = next;
	}

	return newhead;
}