#define _CRT_SECURE_NO_WARNINGS 1 
#include"SeqList.h"
int main()
{
	SeqList ps1;
	SeqListInit(&ps1);

	SeqListPushBack(&ps1, 1);//β��
	//SeqListPopBack(&ps1);//βɾ
	SeqListPushFront(&ps1, 2);//ͷ��
	//SeqListPopFront(&ps1);//ͷɾ
	int ret = SeqListFind(&ps1, 1);
	printf("%d\n", ret);
	SeqListInsert(&ps1, 1, 5);
	//SeqListErase(&ps1, 1);
	SeqListInsert(&ps1, 1, 2);
	SeqListInsert(&ps1, 1, 3);
	SeqListInsert(&ps1, 1, 4);
	SeqListInsert(&ps1, 1, 6);
	SeqListInsert(&ps1, 1, 7);
	SeqListPrint(&ps1);
	SeqListErase(&ps1, 1);
	SeqListPrint(&ps1);
	SeqListDestory(&ps1);

	
	return 0;
}