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
    printf("һ�����ֵΪ��\n");
    link *p = initLink();
    display(p);
    //���� 
    printf("���������������Ԫ�أ�");
    scanf("%d",&n) ;
    int address = selectElem(p, n);
    if (address == -1) {
        printf("�Ҳ���\n");
    }
    else {
        printf("�ҵ���\n");
    }
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
    link * p = (link*)malloc(sizeof(link));//����һ��ͷ���
    link * temp = p;//����һ��ָ��ָ��ͷ��㣬���ڱ�������
    //��������
    for (int i = 1; i < 21; i++) {
        link *a = (link*)malloc(sizeof(link));
        a->elem = i;
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
            return i;
        }
        i++;
    }
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
