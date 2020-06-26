#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
    
typedef struct Node//�ṹ��  
{
	char data;
	struct Node *LChild;
	struct Node *RChild;
} BinNode,*BinTree;

BinTree CreateTree(BinTree T)
{
    char ch;
    scanf("%c",&ch);
    if(ch=='#')
        return NULL;
    else
    {
        T=(BinTree)malloc(sizeof(BinNode));
        T->data=ch;
        T->LChild=CreateTree(T->LChild);/*����������*/
        T->RChild=CreateTree(T->RChild);/*����������*/
        return T;
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
//Ҷ���� 
int LeafCount(BinTree T)
{
	if(T)
	{
		printf("ִ������1��\n");
		if ((T->LChild==NULL )&&( T->RChild==NULL ) )
		{
			printf("ִ������2��\n");
			return 1;
		}
		else {
			printf("ִ������3��\n");
			return LeafCount(T->LChild ) +LeafCount ( T->RChild );			
		}

	}
	else
		return 0;
}
int main()
{

	BinTree bt;
	printf("һ���밴����ķ�ʽ����������Ľ��Ԫ�أ�ע������#��ʾ�ڵ�Ϊ�գ���:ABC##DE#G##F###\n");
	bt=CreateTree(bt);
	printf("����ǰ�������������\n");
	PreOrder(bt);
	printf("\n");
	printf("�������������������\n");
	InOrder(bt);
	printf("\n");
	printf("�ġ����������������\n");
	PostOrder(bt);
	printf("\n");
    printf("�塢�����������:%d\n",Count(bt));
    printf("����������Ҷ������%d\n",LeafCount(bt));
	system("pause");
}

