//实现去重、排序 
//方法：桶排序 
//错误：开始没有对数组进行初始化 ，其结果是不休止的0 
//时间复杂度：O（M+N） 
#include <stdio.h>
int main()
{
	int a[1001],n,num;
	scanf("%d",&n);
	for(int i=0;i<=1000;i++) 
	{
		a[i]=0;
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&num);
		a[num]++;
	}
	for(int i=0;i<=1000;i++)
	{
		if(a[i]>=1)
		{
			printf("%d ",i);
		}
	}
	return 0;
}
