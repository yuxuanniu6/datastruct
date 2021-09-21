#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
// 带头+双向+循环链表增删查改实现
typedef int LTDataType;
typedef struct ListNode
{
	LTDataType data;
	struct ListNode* next;
	struct ListNode* prev;
}ListNode;

// 创建返回链表的头结点.
ListNode* ListCreate();
// 双向链表销毁
//一级指针虽然会造成野指针问题，但是保证了接口的一致性
//二级指针解决了野指针的问题，但是导致了接口混乱
//一级指针，外面置空，里面置空不起作用
//二级指针，里面置空即可
//不管是否会不会影响实参，释放置空都是一个好的习惯
//void ListDestory(ListNode* pHead);
void ListDestory(ListNode** pHead);
// 双向链表打印
void ListPrint(ListNode* pHead);
// 双向链表尾插
void ListPushBack(ListNode* pHead, LTDataType x);
// 双向链表尾删
void ListPopBack(ListNode* pHead);
// 双向链表头插
void ListPushFront(ListNode* pHead, LTDataType x);
// 双向链表头删
void ListPopFront(ListNode* pHead);
// 双向链表查找
ListNode* ListFind(ListNode* pHead, LTDataType x);
// 双向链表在pos的前面进行插入
void ListInsert(ListNode* pos, LTDataType x);
// 双向链表删除pos位置的节点
void ListErase(ListNode* pos);
//创建一个新节点
ListNode* BuyListNode(LTDataType x);