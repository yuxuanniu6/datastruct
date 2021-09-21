#pragma once //防止头文件包含
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int SLDataType;
////静态顺序表
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
void SeqListInit(SeqList* ps);//初始化
void SeqListDestory(SeqList* ps);//销毁
void SeqListPrint(SeqList* ps);//打印
void SeqListPushBack(SeqList* ps, SLDataType x);//尾插
void SeqListPopBack(SeqList* ps);//尾删
void SeqListPushFront(SeqList* ps, SLDataType x);//头插
void SeqListPopFront(SeqList* ps);//头删
int SeqListFind(SeqList* ps, SLDataType x);// 查找
void SeqListInsert(SeqList* ps, size_t pos, SLDataType x);// 在pos位置插入x
void SeqListErase(SeqList* ps, size_t pos);// 删除pos位置的值
void SeqListCheckCapacity(SeqList* ps);//检查容量