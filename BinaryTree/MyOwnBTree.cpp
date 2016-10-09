//ʹ���ն�һ������һ���ڵ㣬�����ɸ��ڵ㣬����ڵ㣬���ҽڵ�ķ�ʽ��
//���õݹ�ķ�ʽ
//c���Ա�д
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
	//����һ�Ŷ��������Ӹ��ڵ㿪ʼ
	struct BTNode * rootNode;
	rootNode = createOneNode();
	if (rootNode != NULL)
	{
		printf("create binary tree succ!\n");
	}
	displayBT(rootNode);
	//������ڵ㿪ʼ�������
	preOrderBT(rootNode);
	printf("\n");

	//������ڵ㿪ʼ�������
	midOrderBT(rootNode);
	printf("\n");

	//������ڵ㿪ʼ��������
	postOrderBT(rootNode);
	printf("\n");

	//���������
	int deepth = BTDeepth(rootNode);
	printf("deepth = %d\n", deepth);

	//����
	deleteNode(&rootNode);
}