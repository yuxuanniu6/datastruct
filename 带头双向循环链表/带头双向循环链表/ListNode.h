#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
// ��ͷ+˫��+ѭ��������ɾ���ʵ��
typedef int LTDataType;
typedef struct ListNode
{
	LTDataType data;
	struct ListNode* next;
	struct ListNode* prev;
}ListNode;

// �������������ͷ���.
ListNode* ListCreate();
// ˫����������
//һ��ָ����Ȼ�����Ұָ�����⣬���Ǳ�֤�˽ӿڵ�һ����
//����ָ������Ұָ������⣬���ǵ����˽ӿڻ���
//һ��ָ�룬�����ÿգ������ÿղ�������
//����ָ�룬�����ÿռ���
//�����Ƿ�᲻��Ӱ��ʵ�Σ��ͷ��ÿն���һ���õ�ϰ��
//void ListDestory(ListNode* pHead);
void ListDestory(ListNode** pHead);
// ˫�������ӡ
void ListPrint(ListNode* pHead);
// ˫������β��
void ListPushBack(ListNode* pHead, LTDataType x);
// ˫������βɾ
void ListPopBack(ListNode* pHead);
// ˫������ͷ��
void ListPushFront(ListNode* pHead, LTDataType x);
// ˫������ͷɾ
void ListPopFront(ListNode* pHead);
// ˫���������
ListNode* ListFind(ListNode* pHead, LTDataType x);
// ˫��������pos��ǰ����в���
void ListInsert(ListNode* pos, LTDataType x);
// ˫������ɾ��posλ�õĽڵ�
void ListErase(ListNode* pos);
//����һ���½ڵ�
ListNode* BuyListNode(LTDataType x);