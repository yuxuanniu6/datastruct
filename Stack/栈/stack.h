#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>
// �����Ƕ����ľ�̬ջ�Ľṹ��ʵ����һ�㲻ʵ�ã�����������Ҫʵ�������֧�ֶ�̬������ջ
//typedef int STDataType;
//#define N 10
//typedef struct Stack
//{
//	STDataType a[N];
//	int top; // ջ��
//}Stack;
// ֧�ֶ�̬������ջ
typedef int STDataType;
typedef struct Stack
{
	STDataType* a;
	int top; // ջ��
	int capacity; // ����
}Stack;
// ��ʼ��ջ
void StackInit(Stack* ps);
// ��ջ
void StackPush(Stack* ps, STDataType data);
// ��ջ
void StackPop(Stack* ps);
// ��ȡջ��Ԫ��
STDataType StackTop(Stack* ps);
// ��ȡջ����ЧԪ�ظ���
int StackSize(Stack* ps);
// ���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط������������Ϊ�շ���0
int StackEmpty(Stack* ps);
// ����ջ
void StackDestroy(Stack* ps);
