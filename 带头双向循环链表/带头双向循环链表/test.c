#define _CRT_SECURE_NO_WARNINGS 1 
#include"ListNode.h"
int main()
{
	ListNode* p = ListCreate();
	//尾插
	ListPushBack(p, 1);
	ListPushBack(p, 2);
	ListPushBack(p, 3);
	ListPushBack(p, 4);
	ListPrint(p);
	//尾删
	ListPopBack(p);
	ListPrint(p);
	//头插
	ListPushFront(p,4);
	ListPrint(p);
	//头删
	ListPopFront(p);
	ListPrint(p);
	//查找
	ListNode* x = ListFind(p, 2);
	if (x)
	{
		printf("%d\n", x->data);
	}
	//插入
	ListInsert(x, 1);
	ListPrint(p);
	//删除
	ListErase(x);
	ListPrint(p);
	//一级指针销毁
	/*ListDestory(p);
	p = NULL;*/
	//二级指针销毁
	ListDestory(&p);
	return 0;
}