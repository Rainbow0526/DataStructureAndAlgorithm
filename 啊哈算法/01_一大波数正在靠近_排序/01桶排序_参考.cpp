# include <stdio.h>
//# include <stdlib.h>
int main()
{
	int a[11],i,j,t;
	//数组初始化为零
	for(i=0;i<=10;i++)
	{
		a[i]=0;  
	}
	//输入五个童鞋的成绩，对应的桶内小旗加一 
	for(i=1;i<=5;i++)
	{
		scanf("%d",&t);
		a[t]++;
	 } 
	//循环所有桶 
	for(i=0;i<=10;i++)
	{	//每个桶内有几个小旗就循环打印几次 
		for(j=1;j<=a [i];j++)
		{
			printf("%d ",i);
		}
	 } 
	 
	 //此处是为了暂停程序，避免程序一闪而过，两者可以代替 
	 getchar();
	// system("pause");  包含在头文件<stdlib.h>里 
	 
	 return 0;
}
