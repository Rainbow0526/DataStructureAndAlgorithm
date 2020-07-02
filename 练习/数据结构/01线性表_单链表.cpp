/*
内容：单链表的查找、插入与删除。设计算法，实现线性结构上的单链表的产生以及元素的查找、插入与删除。
具体实现要求：（具体代码作了调整） 
    1、从键盘输入20个整数，产生带表头的单链表，并输出结点值；
    2、从键盘输入1个整数，在单链表中查找该结点。若找到，则显示"找到了"；否则，则显示"找不到"；
    3、从键盘输入2个整数，一个表示欲插入的位置i，另一个表示欲插入的数值x，将x插入在对应位置上，输出单链表所有结点值，观察输出结果；
    4、从键盘输入1个整数，表示欲删除结点的位置，输出单链表所有结点值，观察输出结果；
*/
#include <stdio.h>
#include <stdlib.h>
typedef struct Link {
    int  elem;
    struct Link *next;
}link;
link * initLink();
//链表插入的函数，p是链表，elem是插入的结点的数据域，add是插入的位置
link * insertElem(link * p, int elem, int add);
//删除结点的函数，p代表操作链表，add代表删除节点的位置
link * delElem(link * p, int add);
//查找结点的函数，elem为目标结点的数据域的值
int selectElem(link * p, int elem);
//更新结点的函数，newElem为新的数据域的值
link *amendElem(link * p, int add, int newElem);
void display(link *p);
int main() {
    //创建 
    int n,m;
    link *p = initLink();
    display(p);
    //查找 
    printf("二、请输入待查找元素：");
    scanf("%d",&n) ;
  	selectElem(p, n);
    //插入 
    printf("三、请输入插入位置：");
    scanf("%d",&m);
	printf("请输入插入数值：");
	scanf("%d",&n);
    p = insertElem(p, n, m);
    display(p);
    //删除 
    printf("四、请输入待删除结点位置：");
    scanf("%d",&m);
    p = delElem(p, m);
    display(p);
    return 0;
}
link * initLink() {
	int n,m;
    link * p = (link*)malloc(sizeof(link));//创建一个头结点
    link * temp = p;//声明一个指针指向头结点，用于遍历链表
    p->next=NULL;
    //生成链表
    printf("一、要输入几个数字：");
    scanf("%d",&n);
    for (int i = 1; i <= n; i++) {
        link *a = (link*)malloc(sizeof(link));
        printf("请输入一个数字："); 
        scanf("%d",&m);
        a->elem = m;
        a->next = NULL;
        temp->next = a;
        temp = temp->next;
    }
    return p;
}
link * insertElem(link * p, int elem, int add) {
    link * temp = p;//创建临时结点temp
    //首先找到要插入位置的上一个结点
    for (int i = 1; i < add; i++) {
        temp = temp->next;
        if (temp == NULL) {
            printf("插入位置无效\n");
            return p;
        }
    }
    //创建插入结点c
    link * c = (link*)malloc(sizeof(link));
    c->elem = elem;
    //向链表中插入结点
    c->next = temp->next;
    temp->next = c;
    return  p;
}
link * delElem(link * p, int add) {
    link * temp = p;
    //遍历到被删除结点的上一个结点
    for (int i = 1; i < add; i++) {
        temp = temp->next;
        if (temp->next == NULL) {
            printf("没有该结点\n");
            return p;
        }
    }
    link * del = temp->next;//单独设置一个指针指向被删除结点，以防丢失
    temp->next = temp->next->next;//删除某个结点的方法就是更改前一个结点的指针域
    free(del);//手动释放该结点，防止内存泄漏
    return p;
}
int selectElem(link * p, int elem) {
    link * t = p;
    int i = 1;
    while (t->next) {
        t = t->next;
        if (t->elem == elem) {
        	printf("找到了,在第%d个位置\n",i);
            return i;
        }
        i++;
    }
    printf("找不到\n");
    return -1;
}
link *amendElem(link * p, int add, int newElem) {
    link * temp = p;
    temp = temp->next;//tamp指向首元结点
    //temp指向被删除结点
    for (int i = 1; i < add; i++) {
        temp = temp->next;
    }
    temp->elem = newElem;
    return p;
}
void display(link *p) {
    link* temp = p;//将temp指针重新指向头结点
    //只要temp指针指向的结点的next不是Null，就执行输出语句。
    while (temp->next) {
        temp = temp->next;
        printf("%d ", temp->elem);
    }
    printf("\n");
}
