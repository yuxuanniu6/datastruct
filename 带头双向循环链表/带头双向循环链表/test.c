#define _CRT_SECURE_NO_WARNINGS 1 
#include"ListNode.h"
int main()
{
	ListNode* p = ListCreate();
	//β��
	ListPushBack(p, 1);
	ListPushBack(p, 2);
	ListPushBack(p, 3);
	ListPushBack(p, 4);
	ListPrint(p);
	//βɾ
	ListPopBack(p);
	ListPrint(p);
	//ͷ��
	ListPushFront(p,4);
	ListPrint(p);
	//ͷɾ
	ListPopFront(p);
	ListPrint(p);
	//����
	ListNode* x = ListFind(p, 2);
	if (x)
	{
		printf("%d\n", x->data);
	}
	//����
	ListInsert(x, 1);
	ListPrint(p);
	//ɾ��
	ListErase(x);
	ListPrint(p);
	//һ��ָ������
	/*ListDestory(p);
	p = NULL;*/
	//����ָ������
	ListDestory(&p);
	return 0;
}