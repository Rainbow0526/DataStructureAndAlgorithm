#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
    
typedef struct Node//结构体  
{
	char data;
	struct Node *LChild;
	struct Node *RChild;
} BinNode,*BinTree;

void InitList(BinTree *l)//初始化
{
*l= (BinTree)malloc(sizeof(BinNode));
(*l)->LChild = NULL;
(*l)->RChild = NULL;
}

void CreateBiTree(BinTree *bt) //先序创建二叉树 
{
	char ch;
	ch = getchar();
	if (ch == ' ') *bt = NULL;
	else
	{
		*bt = (BinTree)malloc(sizeof(BinNode));
		(*bt)->data = ch;
		CreateBiTree(&((*bt)->LChild));
		CreateBiTree(&((*bt)->RChild));
	}
}

void PreOrder(BinTree root)//先序遍历 
{
	if (root != NULL)
	{
		printf("%c", root->data);
		PreOrder(root->LChild);
		PreOrder(root->RChild);
	}
}

void InOrder(BinTree root)//中序遍历 
{
	if (root != NULL)
	{
		InOrder(root->LChild);
		printf("%c", root->data);
		InOrder(root->RChild);
	}
}

void PostOrder(BinTree root)//后序遍历 
{
	if (root != NULL)
	{
		PostOrder(root->LChild);
		PostOrder(root->RChild);
		printf("%c", root->data);
	}
}
/*求二叉树结点总数*/
int Count(BinTree T)
{
    if(T==NULL)
        return 0;                   /*空二叉树结点数为0*/
    else                            /*左右子树结点总数加1*/
        return Count(T->LChild)+Count(T->RChild)+1;
}
int main()
{

	BinTree bt;
	InitList(&bt);
	printf("请输入ABC--DE-G--F---\n");
	CreateBiTree(&bt);
	PreOrder(bt);
	printf("\n");
	InOrder(bt);
	printf("\n");
	PostOrder(bt);
	printf("\n");
    printf("二叉树结点总数:%d\n",Count(bt));
	system("pause");
}

