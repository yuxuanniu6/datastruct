#define _CRT_SECURE_NO_WARNINGS 1 
#include"Queue.h"
// 通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树
BTNode* BinaryTreeCreate(DataType* a, int* pi)
{
	if (a[*pi] == '#')
	{
		(*pi)++;//索引+1，不是地址+1 ，跳过#
		return NULL;
	}
	BTNode* p = (BTNode*)malloc(sizeof(BTNode));
	assert(p != NULL);
	p->_data = a[(*pi)++]; // 索引+1,找到下一个字符
	p->_left = BinaryTreeCreate(a, pi);
	p->_right = BinaryTreeCreate(a, pi);
	return p;
}
// 二叉树销毁
void BinaryTreeDestory(BTNode** root)
{
	if (*root != NULL)
	{
		BinaryTreeDestory(&(*root)->_left);
		BinaryTreeDestory(&(*root)->_right);
		free(*root);
	}
}
// 二叉树节点个数
int BinaryTreeSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	else
		return BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right) + 1;
}
// 二叉树叶子节点个数
int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	// 叶结点无左右孩子
	if (root->_left == NULL && root->_right == NULL)
		return 1;
	else
		return BinaryTreeLeafSize(root->_left) + BinaryTreeLeafSize(root->_right);
}
// 二叉树第k层节点个数
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return BinaryTreeLevelKSize(root->_left, k - 1) + BinaryTreeLevelKSize(root->_right, k - 1);
}
// 二叉树查找值为x的节点
BTNode* BinaryTreeFind(BTNode* root, DataType x)
{
	if (root == NULL)
		return NULL;
	if (root->_data == x)
		return root;
	// 找左子树
	BTNode* p_left = BinaryTreeFind(root->_left, x);
	if (p_left)
		return p_left;
	//左子树未找到，在去右子树找
	BTNode* p_right = BinaryTreeFind(root->_right, x);
	if (p_right)
		return p_right;
	return NULL;
}
// 二叉树前序遍历 
void BinaryTreePrevOrder(BTNode* root)
{
	if (root != NULL)
	{
		printf("%c ", root->_data);
		BinaryTreePrevOrder(root->_left);
		BinaryTreePrevOrder(root->_right);
	}
}
// 二叉树中序遍历
void BinaryTreeInOrder(BTNode* root)
{
	if (root != NULL)
	{
		BinaryTreePrevOrder(root->_left);
		printf("%c ", root->_data);
		BinaryTreePrevOrder(root->_right);
	}
}
// 二叉树后序遍历
void BinaryTreePostOrder(BTNode* root)
{
	if (root != NULL)
	{
		BinaryTreePrevOrder(root->_left);
		BinaryTreePrevOrder(root->_right);
		printf("%c ", root->_data);
	}
}
// 层序遍历
void BinaryTreeLevelOrder(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root)
	{
		QueuePush(&q, root); // 先把根结点入队
	}
	while (!QueueEmpty(&q))
	{
		root = QueueFront(&q);
		printf("%c ", root->_data);
		QueuePop(&q);
		if (root->_left) QueuePush(&q, root->_left); // 依次入左孩子、右孩子
		if (root->_right) QueuePush(&q, root->_right);
	}


}
// 判断二叉树是否是完全二叉树
int BinaryTreeComplete(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root)
	{
		QueuePush(&q, root); // 先把根结点入队
	}
	while (!QueueEmpty(&q))
	{
		BTNode* p = QueueFront(&q);
		QueuePop(&q);
		if (p == NULL) // 遇到空就停止，后面全为空就是完全二叉树，反之不是
			break;
		QueuePush(&q, p->_left);
		QueuePush(&q, p->_right);
	}
	// ABCD#FG
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q); //
		if (front)// 不为空，不是完全二叉树
		{
			QueueDestroy(&q); // 销毁队列
			return false;
		}
	}
	//为完全二叉树
	QueueDestroy(&q);
	return true;
}