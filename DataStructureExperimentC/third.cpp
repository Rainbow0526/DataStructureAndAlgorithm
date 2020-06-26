#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
    
typedef struct Node//�ṹ��  
{
	char data;
	struct Node *LChild;
	struct Node *RChild;
} BinNode,*BinTree;

void InitList(BinTree *l)//��ʼ��
{
*l= (BinTree)malloc(sizeof(BinNode));
(*l)->LChild = NULL;
(*l)->RChild = NULL;
}

void CreateBiTree(BinTree *bt) //���򴴽������� 
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

void PreOrder(BinTree root)//������� 
{
	if (root != NULL)
	{
		printf("%c", root->data);
		PreOrder(root->LChild);
		PreOrder(root->RChild);
	}
}

void InOrder(BinTree root)//������� 
{
	if (root != NULL)
	{
		InOrder(root->LChild);
		printf("%c", root->data);
		InOrder(root->RChild);
	}
}

void PostOrder(BinTree root)//������� 
{
	if (root != NULL)
	{
		PostOrder(root->LChild);
		PostOrder(root->RChild);
		printf("%c", root->data);
	}
}
/*��������������*/
int Count(BinTree T)
{
    if(T==NULL)
        return 0;                   /*�ն����������Ϊ0*/
    else                            /*�����������������1*/
        return Count(T->LChild)+Count(T->RChild)+1;
}
int main()
{

	BinTree bt;
	InitList(&bt);
	printf("������ABC--DE-G--F---\n");
	CreateBiTree(&bt);
	PreOrder(bt);
	printf("\n");
	InOrder(bt);
	printf("\n");
	PostOrder(bt);
	printf("\n");
    printf("�������������:%d\n",Count(bt));
	system("pause");
}

