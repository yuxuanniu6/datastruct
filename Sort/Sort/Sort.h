#pragma once
#include<stdlib.h>
#include<stdio.h>
//��ӡ
void PrintArray(int* a, int n);
// ��������
void InsertSort(int* a, int n);
// ϣ������
void ShellSort(int* a, int n);
// ѡ������
void SelectSort(int* a, int n);
// ������
void AdjustDwon(int* a, int n, int root);
void HeapSort(int* a, int n);

// ð������
void BubbleSort(int* a, int n);

// ��������ݹ�ʵ��
// ��������hoare�汾
int PartSort1(int* a, int left, int right);
// ���������ڿӷ�
int PartSort2(int* a, int left, int right);
// ��������ǰ��ָ�뷨
int PartSort3(int* a, int left, int right);
void QuickSort(int* a, int left, int right);
int GetMidIndex(int* a, int left, int right);//����ȡ�У���ֹ����Ӱ��Ч��
// �������� �ǵݹ�ʵ��
void QuickSortNonR(int* a, int left, int right);

// �鲢����ݹ�ʵ��
void _MergeSort(int* a, int left, int right, int* tmp);
void MergeSort(int* a, int n);
// �鲢����ǵݹ�ʵ��
void _MergeSortNonR(int* a, int left, int right, int* tmp);
void MergeSortNonR(int* a, int n);

// ��������
void CountSort(int* a, int n);
