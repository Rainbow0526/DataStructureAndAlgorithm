//内容：顺序表的查找、插入与删除。设计算法，实现线性结构上的顺序表的产生以及元素的查找、插入与删除。
//具体实现要求：
//1、从键盘输入10个整数，产生顺序表，并输出结点值；
//2、从键盘输入1个整数，在顺序表中查找该结点。若找到，输出结点的位置；若找不到，则显示"找不到"；
//3、从键盘输入2个整数，一个表示欲插入的位置i，另一个表示欲插入的数值x，将x插入在对应位置上，输出顺序表所有结点值，观察输出结果；
//4、从键盘输入1个整数，表示欲删除结点的位置，输出顺序表所有结点值，观察输出结果。
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
    //1.输入整数 
    printf("一、请输入十个整数：");
    while(num<=10){
    	scanf("%d", &a);
    	InSert(list, num,a);
    	//printf("第%d个结点创建成功！\n",num);
    	num++; 
	} 
    Print(list);
    //2.查找
    printf("二、请输入待查找数：");
    scanf("%d",&a); 
    Find(list,a);
	//3.插入
	printf("三、请输入欲插入位置：");
    scanf("%d", &num);
    printf("请输入欲插入整数:");
    scanf("%d", &a);
    InSert(list, num,a);
    Print(list);
    //4.删除 
    printf("四、请输入欲删除数据的结点位置：");
    scanf("%d", &num);
    Delete(list,num);
    Print(list);
}
//初始化
List InitList() {  
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
    return 1;
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
//查找 
int Find(List L,ElementType x){
	int i = 0;
    while(i < L -> Length && L -> elem[i] != x){
    	i++;
	} 
    if(i < L->Length){
    	printf("待查找数的节点位置为：%d\n",i+1);
		return 1;
	}
    else 
		printf("未找到"); 
	return 1;
} 
//遍历输出
int Print(List L){
	printf("结点值为:"); 
    int i = 0;
    for (i; i < L->Length; i++){ 
        printf("%d ",L->elem[i]);
    } 
    printf("\n"); 
}
