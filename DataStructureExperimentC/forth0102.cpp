#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAXQSIZE 100
typedef int Status;
typedef int QElemType;
typedef struct Node
{
    QElemType *base; //��ʼ����̬����洢�ռ�
    int front;
    int rear;
} SqQueue;
Status InitQueue(SqQueue *Q)
{
    Q->base = (QElemType *)malloc(MAXQSIZE * sizeof(QElemType));
    if (!Q->base)
        exit(OVERFLOW);
    Q->front = Q->rear = 0;
    return OK;
}
Status EnQueue(SqQueue *Q, QElemType elem)
{
    //����Ϊ��ʱ 1%100==1,������ʱ(99+1)%100==0,�������99��Ԫ��
    if ((Q->rear + 1) % MAXQSIZE == (Q->front))
        return ERROR;
    Q->base[Q->rear] = elem;
    Q->rear = (Q->rear + 1) % MAXQSIZE; //rearʼ����0-100��ѭ��
    return OK;
}
Status OutQueue(SqQueue *Q, QElemType *e)
{
    if (Q->front == Q->rear)
        return ERROR;
    *e = Q->base[Q->front];
    Q->front = (Q->front + 1) % MAXQSIZE;
    return OK;
}
Status PrintQueue(SqQueue Q)
{
    for (int i = Q.front; i < Q.rear; ++i)
        printf("%d ", Q.base[i]);
    return OK;
}
int main()
{
    SqQueue queue;
    QElemType elem;
    int i,num;
    int j=1; 
    InitQueue(&queue);
    printf("һ��ѭ��˳�������ʵ�ֲ��룺\n");
    while(j<=6){
    	printf("�����������������ݣ�");
    	scanf("%d",&num);
		EnQueue(&queue, num);
		j++;
			
	}
	printf("�Ѳ���Ķ���Ϊ��");
    PrintQueue(queue);
    /* ����Ҫ�����еĸ��� */
    printf("\n����ѭ��˳�������ʵ��ɾ����\n");
    printf("������Ҫɾ���ĸ���:");
    scanf("%d", &i);
    while(i != 0)
    {
        OutQueue(&queue, &elem);
        i--;
    }
    printf("��ɾ���Ķ���Ϊ��");
    PrintQueue(queue);
    return OK;
}
