#define _CRT_SECURE_NO_WARNINGS 1 
#define _CRT_SECURE_NO_WARNINGS 1 
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>//boolͷ�ļ�
typedef int SLTDataType;
typedef struct SListNode
{
	SLTDataType data;  // int val;
	struct SListNode* next;
}SLTNode;


size_t SListSize(SLTNode* phead);//���С
bool SListEmpty(SLTNode* phead);//�ж��Ƿ�Ϊ��
SLTNode* SListFind(SLTNode** pphead, SLTDataType x);//����x���ҵ����ظýڵ㣬��֮������NULL
void SListInit(SLTNode** phead);//��ʼ��
void SListPrint(SLTNode* phead);//��ӡ
void SListPushBack(SLTNode** pphead, SLTDataType x);//β��
void SListPushFront(SLTNode** pphead, SLTDataType x);//ͷ��
void SListPopBack(SLTNode** pphead);//βɾ
void SListPopFront(SLTNode** pphead);//ͷɾ
void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x);//��pos�ڵ�֮ǰ����ֵΪx�Ľڵ�
void SListInsertAfter(SLTNode* pos, SLTDataType x);//��pos֮�����
void SListErase(SLTNode** pphead, SLTNode* pos);//ɾ��pos�ڵ�
void SListEraseAfter(SLTNode* pos);//ɾ��pos��Ľڵ�
void SListDestory(SLTNode** pphead);//���ٵ�����
SLTNode* reverseList(SLTNode** head);//��ת����
SLTNode* BuySListNode(SLTDataType x);//�����½ڵ�