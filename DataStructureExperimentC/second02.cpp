#include <stdio.h>
#include <stdlib.h>
typedef struct Link {
    int  elem;
    struct Link *next;
}link;
link * creatElem(int elem, int add);
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
	//һ���������� 
	// 2���Ӽ�������1���������ڵ������в��Ҹý�㡣���ҵ�������ʾ"�ҵ���"����������ʾ"�Ҳ���"
	int index=1;
	int num;
	link * p;
	printf("������20��������");
	if(index <= 5){
		scanf("%d",&num);
		printf("����%d��",num);
		creatElem(num,index); 
		index++;
	}
	//��������
	 // 3���Ӽ�������2��������һ����ʾ�������λ��i����һ����ʾ���������ֵx����x�����ڶ�Ӧλ���ϣ�������������н��ֵ���۲���������
	//��������
	//�ġ�ɾ��������������� 
     //4���Ӽ�������1����������ʾ��ɾ������λ�ã�������������н��ֵ���۲���������
    display(p);
    printf("�ڵ�4��λ�ò���Ԫ��5��\n");
    p = insertElem(p, 5, 4);
    display(p);
    printf("ɾ��������λ�õ�Ԫ��:\n");
    p = delElem(p, 3);
    display(p);
    printf("����Ԫ��2��λ�ã�\n");
    int address = selectElem(p, 2);
    if (address == -1) {
        printf("û�и�Ԫ��");
    }
    else {
        printf("%d\n", address);
    }
    printf("���ĵ�3��λ���ϵ�����Ϊ7:\n");
    p = amendElem(p, 3, 7);
    display(p);
    return 0;
}
link * creatElem(int elem, int add) {
	link * p= (link*)malloc(sizeof(link));
    link * temp = p;//������ʱ���temp
    link *a = (link*)malloc(sizeof(link));
    a->elem = elem;
    a->next = NULL;
    temp->next = a;
    temp = temp->next;
    return  p;
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
