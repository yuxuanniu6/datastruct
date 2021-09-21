#define _CRT_SECURE_NO_WARNINGS 1 
#include"ListNode.h"
ListNode* ListCreate()
{
	//ListNode* phead = (ListNode*)malloc(sizeof(ListNode));
	ListNode* phead = BuyListNode(0);
	/*if (phead == NULL)
	{
		perror("ListCreate：");
		exit(-1);
	}*/
	phead->next = phead;
	phead->prev = phead;
	return phead;
}
//创建一个新节点
ListNode* BuyListNode(LTDataType x)
{
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	if (newnode == NULL)
	{
		perror("ListCreate：");
		exit(-1);
	}
	newnode->next = NULL;
	newnode->prev = NULL;
	newnode->data = x;
	return newnode;
}
// 双向链表销毁
//void ListDestory(ListNode* pHead)
//{
//	assert(pHead);
//	ListNode* cur = pHead->next;
//	while (cur!= pHead)
//	{
//		ListNode* next = cur->next;
//		free(cur);
//		cur = next;
//	}
//	free(pHead);
//	pHead = NULL;//这里置不置空无所谓，形参不会影响实参，但写上是比较好的习惯
//}
void ListDestory(ListNode** pHead)
{
	assert(pHead);
	ListNode* cur = (*pHead)->next;
	while (cur != *pHead)
	{
		ListNode* next = cur->next;
		free(cur);
		cur = next;
	}
	free(*pHead);
	*pHead = NULL;
}
// 双向链表打印
void ListPrint(ListNode* pHead)
{
	assert(pHead);
	ListNode* head = pHead;
	ListNode* cur = head->next;
	while (cur != head)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}
// 双向链表尾插
void ListPushBack(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	ListInsert(pHead, x);
	/*ListNode* head = pHead;
	ListNode* newnode = BuyListNode(x);
	ListNode* cur = head->prev;
	cur->next = newnode;
	newnode->prev = cur;
	head->prev = newnode;
	newnode->next = head;*/
}
// 双向链表尾删
void ListPopBack(ListNode* pHead)
{
	assert(pHead);
	assert(!(pHead->next==pHead));//还需要检查是否为空，为空删除失败
	//ListErase(pHead->prev);//可以复用删除算法
	ListNode* head = pHead;
	ListNode* tail = head->prev;
	ListNode* newtail = tail->prev;
	free(tail);//这里记住还要释放，防止内存泄漏
	tail = NULL;
	newtail->next = head;
	head->prev = newtail;
}
// 双向链表头插
void ListPushFront(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	ListInsert(pHead->next, x);//因为是在pos结点之前插入，这里可以复用插入算法
	//ListNode* head = pHead;
	//ListNode* cur = head->next;//第一个结点
	//ListNode* newnode = BuyListNode(x);
	//head->next = newnode;
	//newnode->prev = head;
	//newnode->next = cur;
	//cur->prev = newnode;
}
// 双向链表头删
void ListPopFront(ListNode* pHead)
{
	assert(pHead);
	assert(!(pHead->next == pHead));//还需要检查是否为空，为空删除失败
	//ListErase(pHead->next);
	ListNode* head = pHead;
	ListNode* cur = head->next;
	ListNode* next = cur->next;
	free(cur);
	cur = NULL;
	head->next = next;
	next->prev = head;
}
// 双向链表查找
ListNode* ListFind(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	ListNode* head = pHead;
	ListNode* cur = head->next;
	while (cur != head)
	{
		if (cur->data == x)
			return cur;
		cur = cur->next;
	}
	return NULL;
}
// 双向链表在pos的前面进行插入
void ListInsert(ListNode* pos, LTDataType x)
{
	assert(pos);
	ListNode* cur = pos;
	ListNode* prev = cur->prev;
	ListNode* newnode = BuyListNode(x);
	newnode->prev = prev;
	prev->next = newnode;
	newnode->next = cur;
	cur->prev = newnode;
}
// 双向链表删除pos位置的节点
void ListErase(ListNode* pos)
{
	assert(pos);
	ListNode* cur = pos;
	ListNode* prev = cur->prev;
	ListNode* next = cur->next;
	free(cur);
	cur = NULL;
	prev->next = next;
	next->prev = prev;	
}
