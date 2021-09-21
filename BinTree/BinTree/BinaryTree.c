#define _CRT_SECURE_NO_WARNINGS 1 
#include"Queue.h"
// ͨ��ǰ�����������"ABD##E#H##CF##G##"����������
BTNode* BinaryTreeCreate(DataType* a, int* pi)
{
	if (a[*pi] == '#')
	{
		(*pi)++;//����+1�����ǵ�ַ+1 ������#
		return NULL;
	}
	BTNode* p = (BTNode*)malloc(sizeof(BTNode));
	assert(p != NULL);
	p->_data = a[(*pi)++]; // ����+1,�ҵ���һ���ַ�
	p->_left = BinaryTreeCreate(a, pi);
	p->_right = BinaryTreeCreate(a, pi);
	return p;
}
// ����������
void BinaryTreeDestory(BTNode** root)
{
	if (*root != NULL)
	{
		BinaryTreeDestory(&(*root)->_left);
		BinaryTreeDestory(&(*root)->_right);
		free(*root);
	}
}
// �������ڵ����
int BinaryTreeSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	else
		return BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right) + 1;
}
// ������Ҷ�ӽڵ����
int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	// Ҷ��������Һ���
	if (root->_left == NULL && root->_right == NULL)
		return 1;
	else
		return BinaryTreeLeafSize(root->_left) + BinaryTreeLeafSize(root->_right);
}
// ��������k��ڵ����
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return BinaryTreeLevelKSize(root->_left, k - 1) + BinaryTreeLevelKSize(root->_right, k - 1);
}
// ����������ֵΪx�Ľڵ�
BTNode* BinaryTreeFind(BTNode* root, DataType x)
{
	if (root == NULL)
		return NULL;
	if (root->_data == x)
		return root;
	// ��������
	BTNode* p_left = BinaryTreeFind(root->_left, x);
	if (p_left)
		return p_left;
	//������δ�ҵ�����ȥ��������
	BTNode* p_right = BinaryTreeFind(root->_right, x);
	if (p_right)
		return p_right;
	return NULL;
}
// ������ǰ����� 
void BinaryTreePrevOrder(BTNode* root)
{
	if (root != NULL)
	{
		printf("%c ", root->_data);
		BinaryTreePrevOrder(root->_left);
		BinaryTreePrevOrder(root->_right);
	}
}
// �������������
void BinaryTreeInOrder(BTNode* root)
{
	if (root != NULL)
	{
		BinaryTreePrevOrder(root->_left);
		printf("%c ", root->_data);
		BinaryTreePrevOrder(root->_right);
	}
}
// �������������
void BinaryTreePostOrder(BTNode* root)
{
	if (root != NULL)
	{
		BinaryTreePrevOrder(root->_left);
		BinaryTreePrevOrder(root->_right);
		printf("%c ", root->_data);
	}
}
// �������
void BinaryTreeLevelOrder(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root)
	{
		QueuePush(&q, root); // �ȰѸ�������
	}
	while (!QueueEmpty(&q))
	{
		root = QueueFront(&q);
		printf("%c ", root->_data);
		QueuePop(&q);
		if (root->_left) QueuePush(&q, root->_left); // ���������ӡ��Һ���
		if (root->_right) QueuePush(&q, root->_right);
	}


}
// �ж϶������Ƿ�����ȫ������
int BinaryTreeComplete(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root)
	{
		QueuePush(&q, root); // �ȰѸ�������
	}
	while (!QueueEmpty(&q))
	{
		BTNode* p = QueueFront(&q);
		QueuePop(&q);
		if (p == NULL) // �����վ�ֹͣ������ȫΪ�վ�����ȫ����������֮����
			break;
		QueuePush(&q, p->_left);
		QueuePush(&q, p->_right);
	}
	// ABCD#FG
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q); //
		if (front)// ��Ϊ�գ�������ȫ������
		{
			QueueDestroy(&q); // ���ٶ���
			return false;
		}
	}
	//Ϊ��ȫ������
	QueueDestroy(&q);
	return true;
}