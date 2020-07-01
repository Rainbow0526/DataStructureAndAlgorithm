//想法：10个数循环；每一个数循环向后比较、后移 ；看了书上核心代码的实现才可以写出来
//粗心：对交换两个数不熟练，写的时候错了两次 ；对输入scanf没有掌握好 
# include <stdio.h> 
int main()
{
	int a[100],i,j,t,n;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	} 
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n-i;j++)
		{
			if(a[j]<a[j+1])
			{
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}
	} 
	for(i=1;i<=n;i++)
	{
		printf("%d ",a[i]);
	 } 
	 
	 return 0;
 } 
