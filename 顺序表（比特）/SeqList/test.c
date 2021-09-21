#define _CRT_SECURE_NO_WARNINGS 1 
#include"SeqList.h"
int main()
{
	SeqList ps1;
	SeqListInit(&ps1);

	SeqListPushBack(&ps1, 1);//Î²²å
	//SeqListPopBack(&ps1);//Î²É¾
	SeqListPushFront(&ps1, 2);//Í·²å
	//SeqListPopFront(&ps1);//Í·É¾
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