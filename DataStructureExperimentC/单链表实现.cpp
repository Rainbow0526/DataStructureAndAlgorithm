//���ݣ�ʵ���˵�����
#include <stdio.h>
#include <stdlib.h>
#define MaxSize 11
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
int Find(List L,ElementType x);

int main(){
    int a;
    int num=1;
    List list;
    list=InitList();
    //1.�������� 
    printf("һ��������ʮ��������");
    while(num<=10){
    	scanf("%d", &a);
    	InSert(list, num,a);
    	//printf("��%d����㴴���ɹ���\n",num);
    	num++; 
	} 
    Print(list);
    //2.����
    printf("�������������������");
    scanf("%d",&a); 
    Find(list,a);
	//3.����
	printf("����������������λ�ã�");
    scanf("%d", &num);
    printf("����������������:");
    scanf("%d", &a);
    InSert(list, num,a);
    Print(list);
    //4.ɾ�� 
    printf("�ġ���������ɾ�����ݵĽ��λ�ã�");
    scanf("%d", &num);
    Delete(list,num);
    Print(list);
}
//��ʼ��
List InitList() {  
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
    return 1;
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
//���� 
int Find(List L,ElementType x){
	int i = 0;
    while(i < L -> Length && L -> elem[i] != x){
    	i++;
	} 
    if(i < L->Length){
    	printf("���������Ľڵ�λ��Ϊ��%d\n",i+1);
		return 1;
	}
    else 
		printf("δ�ҵ�"); 
	return 1;
} 
//�������
int Print(List L){
	printf("���ֵΪ:"); 
    int i = 0;
    for (i; i < L->Length; i++){ 
        printf("%d ",L->elem[i]);
    } 
    printf("\n"); 
}
