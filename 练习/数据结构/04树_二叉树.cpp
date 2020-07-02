/*
内容：要求采用二叉链表作为存储结构，完成二叉树的建立，前序、中序和后序遍历的操作，求所有叶子及结点总数的操作等。
具体实现要求：
    1、创建一棵二叉链表存储结构的二叉树;
    2、分别利用前序遍历、中序遍历、后序遍历所建二叉树；
    3、求二叉树结点总数，观察输出结果；
    4、求二叉树叶子总数，观察输出结果；
*/
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
    
typedef struct Node//结构体  
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
        T->LChild=CreateTree(T->LChild);/*创建左子树*/
        T->RChild=CreateTree(T->RChild);/*创建右子树*/
        return T;
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
//叶子数 
int LeafCount(BinTree T){
    if(T == NULL){
        return 0;
    }
    else if ((T->LChild==NULL) && (T->RChild==NULL)){
        return 1;
    }
    else{
        return LeafCount(T->LChild)+LeafCount(T->RChild);
    }
}
int main()
{

	BinTree bt;
	printf("一、请按先序的方式输入二叉树的结点元素（注：输入#表示节点为空）如:ABC##DE#G##F###\n");
	bt=CreateTree(bt);
	printf("二、前序遍历二叉树：\n");
	PreOrder(bt);
	printf("\n");
	printf("三、中序遍历二叉树：\n");
	InOrder(bt);
	printf("\n");
	printf("四、后序遍历二叉树：\n");
	PostOrder(bt);
	printf("\n");
    printf("五、二叉树结点数: %d\n",Count(bt));
    printf("六、叶子节点的个数：%d \n",LeafCount(bt));
	system("pause");
}

