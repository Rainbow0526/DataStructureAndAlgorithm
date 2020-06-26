#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;
const int maxsize=100;
//˳��ջ�����Ͷ���
typedef int datatype;
typedef struct{
	datatype data[maxsize];
	int Top;
}SeqStack;

//����ԭ�͵�����
void InitStack(SeqStack*& S);		//ջ�ĳ�ʼ������
int Empty(SeqStack* S);				//�жϿ�ջ����
int Push(SeqStack* S,datatype e);	//��ջ����
int Pop(SeqStack* S,datatype& e);	//��ջ����
void Conversion(int,int);
//������
int main(){
	int p,q;
	cout<<"������ʮ��������"<<endl;
	cin>>p;
	cout<<"��ת���ɵ�������R��2~9��������"<<endl;
	cin>>q;
	cout<<"ת�������"<<endl;
	Conversion(p,q);
	return 0;
}
//�����Ķ���
void InitStack(SeqStack*& S)
{
	S=(SeqStack*)malloc(sizeof(SeqStack));
	S->Top=0;
}
int Push(SeqStack* S,datatype e){
	if(S->Top>=maxsize-1){
		cout<<"ջ���磡"<<endl;
		return 0;
	}
	else{
		S->data[++S->Top]=e;
		return 1;
	}
}
int Pop(SeqStack* S,datatype& e){
	if(Empty(S)){
		cout<<"ջ���磡"<<endl;
		return 0;
	}
	else{
		e=S->data[S->Top--];
		return 1;
	}
}
int Empty(SeqStack* S)
{
	if(S->Top<=0)return 1;
	else
		return 0;
}
void Conversion(int n,int base){
	datatype e;
	SeqStack* S;
	InitStack(S);
	while(n!=0){
		Push(S,n%base);
		n=n/base;
	}
	while(!Empty(S)){
		Pop(S,e);
		if(e>9)printf("%c",e+55);	//����9���ƣ����������9ʱ���ַ�ӳ�䵽��д��ĸ
		else printf("%c",e+48);		//δ����9���ƣ�����������9ʱ��ӳ�䵽1-9
	}
	cout<<endl;
}

