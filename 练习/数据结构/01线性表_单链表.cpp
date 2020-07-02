/*
���ݣ�������Ĳ��ҡ�������ɾ��������㷨��ʵ�����Խṹ�ϵĵ�����Ĳ����Լ�Ԫ�صĲ��ҡ�������ɾ����
����ʵ��Ҫ�󣺣�����������˵����� 
    1���Ӽ�������20����������������ͷ�ĵ�������������ֵ��
    2���Ӽ�������1���������ڵ������в��Ҹý�㡣���ҵ�������ʾ"�ҵ���"����������ʾ"�Ҳ���"��
    3���Ӽ�������2��������һ����ʾ�������λ��i����һ����ʾ���������ֵx����x�����ڶ�Ӧλ���ϣ�������������н��ֵ���۲���������
    4���Ӽ�������1����������ʾ��ɾ������λ�ã�������������н��ֵ���۲���������
*/
#include <stdio.h>
#include <stdlib.h>
typedef struct Link {
    int  elem;
    struct Link *next;
}link;
link * initLink();
//�������ĺ�����p������elem�ǲ���Ľ���������add�ǲ����λ��
link * insertElem(link * p, int elem, int add);
//ɾ�����ĺ�����p�����������add����ɾ���ڵ��λ��
link * delElem(link * p, int add);
//���ҽ��ĺ�����elemΪĿ������������ֵ
int selectElem(link * p, int elem);
//���½��ĺ�����newElemΪ�µ��������ֵ
link *amendElem(link * p, int add, int newElem);
void display(link *p);
int main() {
    //���� 
    int n,m;
    link *p = initLink();
    display(p);
    //���� 
    printf("���������������Ԫ�أ�");
    scanf("%d",&n) ;
  	selectElem(p, n);
    //���� 
    printf("�������������λ�ã�");
    scanf("%d",&m);
	printf("�����������ֵ��");
	scanf("%d",&n);
    p = insertElem(p, n, m);
    display(p);
    //ɾ�� 
    printf("�ġ��������ɾ�����λ�ã�");
    scanf("%d",&m);
    p = delElem(p, m);
    display(p);
    return 0;
}
link * initLink() {
	int n,m;
    link * p = (link*)malloc(sizeof(link));//����һ��ͷ���
    link * temp = p;//����һ��ָ��ָ��ͷ��㣬���ڱ�������
    p->next=NULL;
    //��������
    printf("һ��Ҫ���뼸�����֣�");
    scanf("%d",&n);
    for (int i = 1; i <= n; i++) {
        link *a = (link*)malloc(sizeof(link));
        printf("������һ�����֣�"); 
        scanf("%d",&m);
        a->elem = m;
        a->next = NULL;
        temp->next = a;
        temp = temp->next;
    }
    return p;
}
link * insertElem(link * p, int elem, int add) {
    link * temp = p;//������ʱ���temp
    //�����ҵ�Ҫ����λ�õ���һ�����
    for (int i = 1; i < add; i++) {
        temp = temp->next;
        if (temp == NULL) {
            printf("����λ����Ч\n");
            return p;
        }
    }
    //����������c
    link * c = (link*)malloc(sizeof(link));
    c->elem = elem;
    //�������в�����
    c->next = temp->next;
    temp->next = c;
    return  p;
}
link * delElem(link * p, int add) {
    link * temp = p;
    //��������ɾ��������һ�����
    for (int i = 1; i < add; i++) {
        temp = temp->next;
        if (temp->next == NULL) {
            printf("û�иý��\n");
            return p;
        }
    }
    link * del = temp->next;//��������һ��ָ��ָ��ɾ����㣬�Է���ʧ
    temp->next = temp->next->next;//ɾ��ĳ�����ķ������Ǹ���ǰһ������ָ����
    free(del);//�ֶ��ͷŸý�㣬��ֹ�ڴ�й©
    return p;
}
int selectElem(link * p, int elem) {
    link * t = p;
    int i = 1;
    while (t->next) {
        t = t->next;
        if (t->elem == elem) {
        	printf("�ҵ���,�ڵ�%d��λ��\n",i);
            return i;
        }
        i++;
    }
    printf("�Ҳ���\n");
    return -1;
}
link *amendElem(link * p, int add, int newElem) {
    link * temp = p;
    temp = temp->next;//tampָ����Ԫ���
    //tempָ��ɾ�����
    for (int i = 1; i < add; i++) {
        temp = temp->next;
    }
    temp->elem = newElem;
    return p;
}
void display(link *p) {
    link* temp = p;//��tempָ������ָ��ͷ���
    //ֻҪtempָ��ָ��Ľ���next����Null����ִ�������䡣
    while (temp->next) {
        temp = temp->next;
        printf("%d ", temp->elem);
    }
    printf("\n");
}
