//使用终端一次输入一个节点，先生成根节点，后左节点，再右节点的方式。
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

void preOrderBT(struct BTNode* oneNode)
{
	printf("%d ", oneNode->data);
	if (oneNode->lchild != NULL)
	{
		preOrderBT(oneNode->lchild);
	}
	if (oneNode->rchild != NULL)
	{
		preOrderBT(oneNode->rchild);
	}
}

void midOrderBT(struct BTNode * oneNode)
{
	if (oneNode->lchild != NULL)
	{
		midOrderBT(oneNode->lchild);
	}
	printf("%d ", oneNode->data);
	if (oneNode->rchild != NULL)
	{
		midOrderBT(oneNode->rchild);
	}
}

void postOrderBT(struct BTNode *oneNode)
{
	if (oneNode->lchild != NULL)
	{
		postOrderBT(oneNode->lchild);
	}
	if (oneNode->rchild != NULL)
	{
		postOrderBT(oneNode->rchild);
	}
	printf("%d ", oneNode->data);
}

int BTDeepth(struct BTNode * oneNode)
{
	int deepth = 0;
	int ldeepth = 0;
	int rdeepth = 0;
	if (oneNode->lchild != NULL)
	{
		ldeepth = BTDeepth(oneNode->lchild) + 1;
	}
	if (oneNode->rchild != NULL)
	{
		rdeepth = BTDeepth(oneNode->rchild) + 1;
	}
	if (ldeepth >= rdeepth)
	{
		deepth = ldeepth;
	}
	else
	{
		deepth = rdeepth;
	}
	return deepth;
}

void displayBT(struct BTNode* oneNode)
{
	
}

void main()
{
	//建立一颗二叉树，从根节点开始
	struct BTNode * rootNode;
	rootNode = createOneNode();
	if (rootNode != NULL)
	{
		printf("create binary tree succ!\n");
	}
	displayBT(rootNode);
	//传入根节点开始先序遍历
	preOrderBT(rootNode);
	printf("\n");

	//传入根节点开始中序遍历
	midOrderBT(rootNode);
	printf("\n");

	//传入根节点开始后续遍历
	postOrderBT(rootNode);
	printf("\n");

	//计算树深度
	int deepth = BTDeepth(rootNode);
	printf("deepth = %d\n", deepth);

	//析构
	deleteNode(&rootNode);
}