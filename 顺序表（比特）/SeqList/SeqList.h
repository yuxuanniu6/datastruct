#pragma once //��ֹͷ�ļ�����
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int SLDataType;
////��̬˳���
//#define MaxSize 100
//typedef struct SeqList
//{
//	SLDataType arr[MaxSize];
//	size_t size;
//}SeqList;
typedef struct SeqList
{
	SLDataType* a;
	size_t size;
	size_t Capacity;
}SeqList;
void SeqListInit(SeqList* ps);//��ʼ��
void SeqListDestory(SeqList* ps);//����
void SeqListPrint(SeqList* ps);//��ӡ
void SeqListPushBack(SeqList* ps, SLDataType x);//β��
void SeqListPopBack(SeqList* ps);//βɾ
void SeqListPushFront(SeqList* ps, SLDataType x);//ͷ��
void SeqListPopFront(SeqList* ps);//ͷɾ
int SeqListFind(SeqList* ps, SLDataType x);// ����
void SeqListInsert(SeqList* ps, size_t pos, SLDataType x);// ��posλ�ò���x
void SeqListErase(SeqList* ps, size_t pos);// ɾ��posλ�õ�ֵ
void SeqListCheckCapacity(SeqList* ps);//�������