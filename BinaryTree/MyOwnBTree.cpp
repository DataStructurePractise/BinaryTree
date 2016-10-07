//使用终端一次输入一个节点，采用先根节点，后左节点，再右节点的方式。
//采用递归的方式
//c语言编写
//chenjl:20161007

#include <stdio.h>
#include <stdlib.h>

struct BTNode
{
	int data;
	struct BTNode *lchild;
	struct BTNode *rchild;
};

struct BTNode* createOneNode()
{
	printf("please input one number:");
	int rootData = 0;
	scanf_s("%d", &rootData);
	struct  BTNode *midNode;
	if (rootData < 0)
	{
		midNode = NULL;
		return NULL;
	}
	else
	{
		midNode = (BTNode *)malloc(sizeof(BTNode));
		if (midNode == NULL)
		{
			return NULL;
		}
		midNode->data = rootData;
		midNode->lchild = createOneNode();
		midNode->rchild = createOneNode();
		return midNode;
	}
}

void deleteNode(struct BTNode **oneNode)
{
	if ((*oneNode)->lchild != NULL)
	{
		deleteNode(&(*oneNode)->lchild);
	}
	if ((*oneNode)->rchild != NULL)
	{
		deleteNode(&(*oneNode)->rchild);
	}
	if ((*oneNode)->lchild == NULL && (*oneNode)->rchild == NULL)
	{
		delete(*oneNode);
		*oneNode = NULL;
	}
}

void main()
{
	//建立一颗二叉树，从根节点开始
	struct BTNode * rootNode;
	rootNode = createOneNode();
	if (rootNode != NULL)
	{
		printf("create binary tree succ!");
	}

	//析构
	deleteNode(&rootNode);
}