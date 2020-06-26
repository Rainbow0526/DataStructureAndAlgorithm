#include <iostream>
#include <cstdlib>
 
/*定义数组的最大长度为100*/
#define MAXSIZE 100
using namespace std;
typedef struct
{
    int data[MAXSIZE];
    int rear;    /*队尾指针*/
    int fronts; /*队首指针*/
}queues;
 
/*队列的初始化*/
queues *CreateQueue();
 
/*入队操作*/
bool AddQ(queues *ptrq, int x);
 
/*出队操作*/
int DeleteQ(queues *ptrq);
int print(queues Q);
int main()
{
    int i,num; 
    queues *s;
    //创建队列 
    s = CreateQueue();
    int a[] = {2, 4, 5, 1, -2, 4, 6, 10};
    int lengths = sizeof(a) / sizeof(a[0]); 
    cout << "已创建的队列为：" << endl;
    for (i = 0; i < lengths; i++)
    {
        cout << a[i] << " ";
        AddQ(s,a[i]);
    }
    
    cout << endl;
    // 插入 
    printf("一、请输入待插入数据：");
    scanf("%d",&num); 
    AddQ(s,num);
    
    //cout << "插入后的队列为：" << endl;
    //while (s->rear != s->fronts)
    {
    //    cout << DeleteQ(s) << " ";
    }
    //cout << endl;
    print(s);
    //删除
	DeleteQ(s);
    return 0;
}
 
/*队列的初始化*/
queues *CreateQueue()
{
    /*初始队列的创建*/
    queues *q;
    q = (queues*)malloc(sizeof(queues));
    q->fronts = 0; //空队列时首指针和尾指针都为0
    q->rear = 0;
}
 
/*入队操作*/
bool AddQ(queues *ptrq, int x)
{
    /*判断队列是否为满队列*/
    if ((ptrq->rear + 1) % MAXSIZE == ptrq->fronts)
    {
        cout << "队列满！"<< endl;
        return false;
    }
    else
    {
        /*加1取余顺序循环*/
        ptrq->rear = (ptrq->rear +1) % MAXSIZE;
        ptrq->data[ptrq->rear] = x;
        return true;
    }
}
 
/*出队操作*/
int DeleteQ(queues *ptrq)
{
    /*判断队列是否为空*/
    if (ptrq->fronts == ptrq->rear)
    {
        cout << "队列为空：" << endl;
        exit(0);
    }
    else
    {
        /*由于第一个位置不用来存放元素所以下标要加1*/
        ptrq->fronts = (ptrq->fronts + 1) % MAXSIZE;
        return ptrq->data[ptrq->fronts];
    }
}
int print(queues Q)
{
	 ///Q在这里是局部变量，且在这Q不是指针类型，这里直接使用Q，不会改变Q的内容，只是输出
	 if(Q.rear==Q.front)///rear和front指向同一个位置说明是空的，返回ERROR
	 	 return 0;
	 while(Q.rear!=(Q.front)%MAXSIZE)///循环队列输出的操作
	 {
		 Q.front%=MAXSIZE;
		printf("%d ",Q.data[Q.front++]);
	 }
	puts("");
	return 1;
}
