#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;
const int maxsize=100;
//顺序栈的类型定义
typedef int datatype;
typedef struct{
	datatype data[maxsize];
	int Top;
}SeqStack;

//函数原型的声明
void InitStack(SeqStack*& S);		//栈的初始化函数
int Empty(SeqStack* S);				//判断空栈函数
int Push(SeqStack* S,datatype e);	//入栈函数
int Pop(SeqStack* S,datatype& e);	//出栈函数
void Conversion(int,int);
//主函数
int main(){
	int p,q;
	cout<<"请输入十进制数："<<endl;
	cin>>p;
	cout<<"待转换成的其他的R（2~9）进制数"<<endl;
	cin>>q;
	cout<<"转换结果："<<endl;
	Conversion(p,q);
	return 0;
}
//函数的定义
void InitStack(SeqStack*& S)
{
	S=(SeqStack*)malloc(sizeof(SeqStack));
	S->Top=0;
}
int Push(SeqStack* S,datatype e){
	if(S->Top>=maxsize-1){
		cout<<"栈上溢！"<<endl;
		return 0;
	}
	else{
		S->data[++S->Top]=e;
		return 1;
	}
}
int Pop(SeqStack* S,datatype& e){
	if(Empty(S)){
		cout<<"栈下溢！"<<endl;
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
		if(e>9)printf("%c",e+55);	//超过9进制，余数会大于9时，字符映射到大写字母
		else printf("%c",e+48);		//未超过9进制，余数不大于9时，映射到1-9
	}
	cout<<endl;
}

