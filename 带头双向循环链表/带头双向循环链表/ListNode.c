#define _CRT_SECURE_NO_WARNINGS 1 
#include"ListNode.h"
ListNode* ListCreate()
{
	//ListNode* phead = (ListNode*)malloc(sizeof(ListNode));
	ListNode* phead = BuyListNode(0);
	/*if (phead == NULL)
	{
		perror("ListCreate��");
		exit(-1);
	}*/
	phead->next = phead;
	phead->prev = phead;
	return phead;
}
//����һ���½ڵ�
ListNode* BuyListNode(LTDataType x)
{
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	if (newnode == NULL)
	{
		perror("ListCreate��");
		exit(-1);
	}
	newnode->next = NULL;
	newnode->prev = NULL;
	newnode->data = x;
	return newnode;
}
// ˫����������
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
//	pHead = NULL;//�����ò��ÿ�����ν���ββ���Ӱ��ʵ�Σ���д���ǱȽϺõ�ϰ��
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
// ˫�������ӡ
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
// ˫������β��
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
// ˫������βɾ
void ListPopBack(ListNode* pHead)
{
	assert(pHead);
	assert(!(pHead->next==pHead));//����Ҫ����Ƿ�Ϊ�գ�Ϊ��ɾ��ʧ��
	//ListErase(pHead->prev);//���Ը���ɾ���㷨
	ListNode* head = pHead;
	ListNode* tail = head->prev;
	ListNode* newtail = tail->prev;
	free(tail);//�����ס��Ҫ�ͷţ���ֹ�ڴ�й©
	tail = NULL;
	newtail->next = head;
	head->prev = newtail;
}
// ˫������ͷ��
void ListPushFront(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	ListInsert(pHead->next, x);//��Ϊ����pos���֮ǰ���룬������Ը��ò����㷨
	//ListNode* head = pHead;
	//ListNode* cur = head->next;//��һ�����
	//ListNode* newnode = BuyListNode(x);
	//head->next = newnode;
	//newnode->prev = head;
	//newnode->next = cur;
	//cur->prev = newnode;
}
// ˫������ͷɾ
void ListPopFront(ListNode* pHead)
{
	assert(pHead);
	assert(!(pHead->next == pHead));//����Ҫ����Ƿ�Ϊ�գ�Ϊ��ɾ��ʧ��
	//ListErase(pHead->next);
	ListNode* head = pHead;
	ListNode* cur = head->next;
	ListNode* next = cur->next;
	free(cur);
	cur = NULL;
	head->next = next;
	next->prev = head;
}
// ˫���������
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
// ˫��������pos��ǰ����в���
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
// ˫������ɾ��posλ�õĽڵ�
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
