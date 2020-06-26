#include <stdio.h>
#include <stdlib.h>
#define MaxSize 10
typedef int ElementType;
struct SqList {
    ElementType elem[MaxSize];
    int Length;
};

typedef struct  SqList *PtrNode;
typedef PtrNode List;

List InitList();
int InSert(List L, int i, ElementType x) ;
int Delete(List L, int i);
int GetElem(List L, int i);
int Print(List L);

int main(){
    int a;
    ElementType x;
    List list;
    list=InitList();
    InSert(list, 1, 1);
    InSert(list, 2, 2);
    InSert(list, 3, 3);
    InSert(list, 2, 4);
    Print(list);
    printf("��һ����Ԫ��Ϊ:%d\n",GetElem(list,1));
    printf("Ҫɾ���ڼ���������");
    scanf("%d", &a);
    Delete(list, a);
    Print(list);
}
List InitList() {  //��ʼ��
    List L;
    L = (List)malloc(sizeof(struct SqList));
    L->Length = 0;
    printf("��ʼ���ɹ�\n");
    return L;
}
//����
int InSert(List L, int i, ElementType x) {
    int j;
    if (i<1 || i>L->Length + 1) {
        printf("Խ��"); return 0;
    }
    for (j = L->Length; j >= i; j--) {
        L->elem[j] = L->elem[j-1];
    }
    L->elem[i - 1] = x;  //��i������Ϊ���������Լ�һ
    L->Length++;
    return 0;
}
//ɾ��
int Delete(List L, int i) {
    int j;
    if (i<1 || i>L->Length) {
        printf("Խ��"); return 0;
    }
    for (j = i - 1; j < L->Length-1; j++)
        L->elem[j] = L->elem[j+1];
    L->Length--;
    return 1;

}
//���ҵ�i��������
int GetElem(List L, int i) {
    if (i<1 || i>L->Length) {
        printf("Խ��"); return 0;
    }
    return L->elem[i - 1];
}
//�������
//�������
int Print(List L){
	printf("���ֵΪ:\n"); 
    int i = 0;
    for (i; i < L->Length; i++){ 
        printf("%d ",L->elem[i]);
    } 
    printf("\n"); 
}
