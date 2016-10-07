//ʹ���ն�һ������һ���ڵ㣬�����ȸ��ڵ㣬����ڵ㣬���ҽڵ�ķ�ʽ��
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

void main()
{
	//����һ�Ŷ��������Ӹ��ڵ㿪ʼ
	struct BTNode * rootNode;
	rootNode = createOneNode();
	if (rootNode != NULL)
	{
		printf("create binary tree succ!");
	}

	//����
	deleteNode(&rootNode);
}