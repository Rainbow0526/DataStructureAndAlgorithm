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
    QElemType *base; //初始化动态分配存储空间
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
    //队列为空时 1%100==1,队列满时(99+1)%100==0,最多容纳99个元素
    if ((Q->rear + 1) % MAXQSIZE == (Q->front))
        return ERROR;
    Q->base[Q->rear] = elem;
    Q->rear = (Q->rear + 1) % MAXQSIZE; //rear始终在0-100中循环
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
    printf("一、循环顺序队列上实现插入：\n");
    while(j<=6){
    	printf("请输入待插入队列数据：");
    	scanf("%d",&num);
		EnQueue(&queue, num);
		j++;
			
	}
	printf("已插入的队列为：");
    PrintQueue(queue);
    /* 输入要出队列的个数 */
    printf("\n二、循环顺序队列上实现删除：\n");
    printf("请输入要删除的个数:");
    scanf("%d", &i);
    while(i != 0)
    {
        OutQueue(&queue, &elem);
        i--;
    }
    printf("已删除的队列为：");
    PrintQueue(queue);
    return OK;
}
