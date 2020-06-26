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
    printf("第一处的元素为:%d\n",GetElem(list,1));
    printf("要删除第几处的数据");
    scanf("%d", &a);
    Delete(list, a);
    Print(list);
}
List InitList() {  //初始化
    List L;
    L = (List)malloc(sizeof(struct SqList));
    L->Length = 0;
    printf("初始化成功\n");
    return L;
}
//插入
int InSert(List L, int i, ElementType x) {
    int j;
    if (i<1 || i>L->Length + 1) {
        printf("越界"); return 0;
    }
    for (j = L->Length; j >= i; j--) {
        L->elem[j] = L->elem[j-1];
    }
    L->elem[i - 1] = x;  //第i处，因为是数组所以减一
    L->Length++;
    return 0;
}
//删除
int Delete(List L, int i) {
    int j;
    if (i<1 || i>L->Length) {
        printf("越界"); return 0;
    }
    for (j = i - 1; j < L->Length-1; j++)
        L->elem[j] = L->elem[j+1];
    L->Length--;
    return 1;

}
//查找第i处的数据
int GetElem(List L, int i) {
    if (i<1 || i>L->Length) {
        printf("越界"); return 0;
    }
    return L->elem[i - 1];
}
//遍历输出
//遍历输出
int Print(List L){
	printf("结点值为:\n"); 
    int i = 0;
    for (i; i < L->Length; i++){ 
        printf("%d ",L->elem[i]);
    } 
    printf("\n"); 
}
