#include <iostream>
#include <cstdlib>
 
/*�����������󳤶�Ϊ100*/
#define MAXSIZE 100
using namespace std;
typedef struct
{
    int data[MAXSIZE];
    int rear;    /*��βָ��*/
    int fronts; /*����ָ��*/
}queues;
 
/*���еĳ�ʼ��*/
queues *CreateQueue();
 
/*��Ӳ���*/
bool AddQ(queues *ptrq, int x);
 
/*���Ӳ���*/
int DeleteQ(queues *ptrq);
int print(queues Q);
int main()
{
    int i,num; 
    queues *s;
    //�������� 
    s = CreateQueue();
    int a[] = {2, 4, 5, 1, -2, 4, 6, 10};
    int lengths = sizeof(a) / sizeof(a[0]); 
    cout << "�Ѵ����Ķ���Ϊ��" << endl;
    for (i = 0; i < lengths; i++)
    {
        cout << a[i] << " ";
        AddQ(s,a[i]);
    }
    
    cout << endl;
    // ���� 
    printf("һ����������������ݣ�");
    scanf("%d",&num); 
    AddQ(s,num);
    
    //cout << "�����Ķ���Ϊ��" << endl;
    //while (s->rear != s->fronts)
    {
    //    cout << DeleteQ(s) << " ";
    }
    //cout << endl;
    print(s);
    //ɾ��
	DeleteQ(s);
    return 0;
}
 
/*���еĳ�ʼ��*/
queues *CreateQueue()
{
    /*��ʼ���еĴ���*/
    queues *q;
    q = (queues*)malloc(sizeof(queues));
    q->fronts = 0; //�ն���ʱ��ָ���βָ�붼Ϊ0
    q->rear = 0;
}
 
/*��Ӳ���*/
bool AddQ(queues *ptrq, int x)
{
    /*�ж϶����Ƿ�Ϊ������*/
    if ((ptrq->rear + 1) % MAXSIZE == ptrq->fronts)
    {
        cout << "��������"<< endl;
        return false;
    }
    else
    {
        /*��1ȡ��˳��ѭ��*/
        ptrq->rear = (ptrq->rear +1) % MAXSIZE;
        ptrq->data[ptrq->rear] = x;
        return true;
    }
}
 
/*���Ӳ���*/
int DeleteQ(queues *ptrq)
{
    /*�ж϶����Ƿ�Ϊ��*/
    if (ptrq->fronts == ptrq->rear)
    {
        cout << "����Ϊ�գ�" << endl;
        exit(0);
    }
    else
    {
        /*���ڵ�һ��λ�ò��������Ԫ�������±�Ҫ��1*/
        ptrq->fronts = (ptrq->fronts + 1) % MAXSIZE;
        return ptrq->data[ptrq->fronts];
    }
}
int print(queues Q)
{
	 ///Q�������Ǿֲ�������������Q����ָ�����ͣ�����ֱ��ʹ��Q������ı�Q�����ݣ�ֻ�����
	 if(Q.rear==Q.front)///rear��frontָ��ͬһ��λ��˵���ǿյģ�����ERROR
	 	 return 0;
	 while(Q.rear!=(Q.front)%MAXSIZE)///ѭ����������Ĳ���
	 {
		 Q.front%=MAXSIZE;
		printf("%d ",Q.data[Q.front++]);
	 }
	puts("");
	return 1;
}
