#include <stdio.h>
//创建了一个结构体存储姓名和分数 
struct student
{
	char name[21];
	int score;
};

int main(){
	struct student a[100],t;
	int i,j,n;
	scanf("%d",&n);//读入一个数n 
	//循环读入n个人名和分数 
	for(i=1;i<=n;i++)
	{
		scanf("%s %d",a[i].name,&a[i].score);
	}
	//分数从高到低进行排序 
	for(i=1;i<=n-1;i++)
	{
		for(j=1;j<=n-i;j++)
		{
			if(a[j].score<a[j+1].score)//对分数进行比较 
			{
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t; 
			 } 
		 } 
	}
	for(i=1;i<=n;i++)
	{
		printf("%s\n",a[i].name);//输出人名 
	}
	
	getchar();getchar();
	return 0; 
}
