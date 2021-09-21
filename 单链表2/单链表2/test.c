#define _CRT_SECURE_NO_WARNINGS 1 
#define _CRT_SECURE_NO_WARNINGS 1 
#include"SListNode.h"
int main()
{
	SLTNode* p = NULL;
	SListInit(&p);
	SListPushBack(&p, 1);
	SListPopFront(&p);
	SListPrint(p);
	//SListInit(&p);
	/*SListPushBack(&p, 1);
	SListPushBack(&p, 2);
	SListPushBack(&p, 3);
	SListPushBack(&p, 4);*/
	//SListPushFront(&p, 1);
	//SListPushFront(&p, 2);
	//SListPushFront(&p, 3);
	//SListPushFront(&p, 4);
	//SListPopFront(&p);
	//SListPrint(p);

	//int len = SListSize(p);
	//printf("%d\n", len);

	//printf("%d\n", SListEmpty(p));

	//SListPopFront(&p);
	//SListPopBack(&p);

	//SLTNode* pos = SListFind(&p, 3);
	//if (pos)
	//{
	//	printf("找到了\n");
	//	//pos->data = 50;
	//}
	//SListPrint(p);

	////找到3位置的节点
	//pos = SListFind(&p, 9);
	//SListInsert(&p, pos, 50);
	//SListInsertAfter(pos, 30);
	//SListPrint(p);

	//SListErase(&p, pos);
	//SListPrint(p);
	//pos = SListFind(&p, 2);
	//SListEraseAfter(pos);
	//SListPrint(p);
	//p = reverseList(&p);
	//SListPrint(p);
	//SListDestory(&p);

	return 0;
}