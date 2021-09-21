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
	printf("��������%d\n", num);

	int LeadSize = BinaryTreeLeafSize(t);
	printf("Ҷ�ӽ�������%d\n", LeadSize);

	int knum = BinaryTreeLevelKSize(t, 2);
	printf("�ڶ����������%d\n", knum);

	BTNode* find_xnode = BinaryTreeFind(t, 'D');
	printf("���ҵ���%c\n", find_xnode->_data);

	printf("��α�����");
	BinaryTreeLevelOrder(t);
	
	printf("\n��ȫ�������ж���0���ǣ�1�ǣ�%d", BinaryTreeComplete(t));
	BinaryTreeDestory(&t);
	//BinaryTreePostOrder(t); // �Ѿ������٣��޷���������
}
int main()
{
	test01();
	
	return 0;
}