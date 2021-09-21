#define _CRT_SECURE_NO_WARNINGS 1 
#define _CRT_SECURE_NO_WARNINGS 1 
#include"SListNode.h"
//初始化  尾插  头插  选择一个即可
//初始化
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
//创建节点
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
//遍历
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
//尾插
void SListPushBack(SLTNode** pphead, SLTDataType x)
{
	assert(pphead);
	if (*pphead == NULL)
	{
		SLTNode* newnode = BuySListNode(x);//创建新节点
		*pphead = newnode;//将新节点地址给头节点
	}
	else
	{
		SLTNode* tail = *pphead;
		//当有节点存在时
		while (tail->next)
		{
			tail = tail->next;
		}
		SLTNode* newnode = BuySListNode(x);
		tail->next = newnode;
	}
}
//头插
void SListPushFront(SLTNode** pphead, SLTDataType x)
{
	assert(pphead);
	SLTNode* newnode = BuySListNode(x);
	newnode->next = *pphead;//指向第一个节点
	*pphead = newnode;//newnode地址给pphead成为第一个节点
}
void SListPopBack(SLTNode** pphead)
{
	assert(pphead);
	//暴力方式
	assert(*pphead);//检测链表是否为空
	//温和方式
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
//在pos位置之前去插入
void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x)
{
	assert(pphead);
	assert(pos);//暴力
	/*if (pos == NULL)//温柔处理方式
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
//在pos位置之后插入
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
		nextnode->next = pos->next;//pos的前一个节点指向pos的后一个节点
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