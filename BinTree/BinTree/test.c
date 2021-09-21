#define _CRT_SECURE_NO_WARNINGS 1 
#include"BinaryTree.h"
void test01()
{
	BTNode* t;
	DataType* str = "ABD##E#H##CF##G##";
	int index = 0;
	t = BinaryTreeCreate(str, &index);
	BinaryTreePrevOrder(t);
	printf("\n");
	BinaryTreeInOrder(t);
	printf("\n");
	BinaryTreePostOrder(t);
	printf("\n");

	int num = BinaryTreeSize(t);
	printf("结点个数：%d\n", num);

	int LeadSize = BinaryTreeLeafSize(t);
	printf("叶子结点个数：%d\n", LeadSize);

	int knum = BinaryTreeLevelKSize(t, 2);
	printf("第二层结点个数：%d\n", knum);

	BTNode* find_xnode = BinaryTreeFind(t, 'D');
	printf("已找到：%c\n", find_xnode->_data);

	printf("层次遍历：");
	BinaryTreeLevelOrder(t);
	
	printf("\n完全二叉树判定，0不是，1是：%d", BinaryTreeComplete(t));
	BinaryTreeDestory(&t);
	//BinaryTreePostOrder(t); // 已经被销毁，无法继续遍历
}
int main()
{
	test01();
	
	return 0;
}