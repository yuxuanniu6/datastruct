#define _CRT_SECURE_NO_WARNINGS 1 
#define _CRT_SECURE_NO_WARNINGS 1 
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>//bool头文件
typedef int SLTDataType;
typedef struct SListNode
{
	SLTDataType data;  // int val;
	struct SListNode* next;
}SLTNode;


size_t SListSize(SLTNode* phead);//求大小
bool SListEmpty(SLTNode* phead);//判断是否为空
SLTNode* SListFind(SLTNode** pphead, SLTDataType x);//查找x，找到返回该节点，反之，返回NULL
void SListInit(SLTNode** phead);//初始化
void SListPrint(SLTNode* phead);//打印
void SListPushBack(SLTNode** pphead, SLTDataType x);//尾插
void SListPushFront(SLTNode** pphead, SLTDataType x);//头插
void SListPopBack(SLTNode** pphead);//尾删
void SListPopFront(SLTNode** pphead);//头删
void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x);//在pos节点之前插入值为x的节点
void SListInsertAfter(SLTNode* pos, SLTDataType x);//在pos之后插入
void SListErase(SLTNode** pphead, SLTNode* pos);//删除pos节点
void SListEraseAfter(SLTNode* pos);//删除pos后的节点
void SListDestory(SLTNode** pphead);//销毁单链表
SLTNode* reverseList(SLTNode** head);//反转链表
SLTNode* BuySListNode(SLTDataType x);//创建新节点