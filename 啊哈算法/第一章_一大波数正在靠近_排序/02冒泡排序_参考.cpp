#include <stdio.h>
int main()
{
	int a[100],i,j,t,n;
	scanf("%d",&n);//输入一个数，表示接下来有n个数 
	
	for(i=1;i<=n;i++)//循环读入n个数到数组a中 
	{
		scanf("%d",&a[i]); 
	}
	//冒泡排序的核心部分 
	for(i=1;i<=n-1;i++) //n个数排序，只能进行n-1趟 
	{
		for(j=1;j<=n-i;j++) //从第一位开始比较直到最后一个尚未归位的数 
		{
			//比较大小并交换 
			if(a[j]<a[j+1]) 
			{
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}
	}
	//输出结果 
	for(i=1;i<=n;i++)
	{
		printf("%d ",a[i]);
	 } 
	 
	 getchar();getchar();
	 return 0;
 } 
