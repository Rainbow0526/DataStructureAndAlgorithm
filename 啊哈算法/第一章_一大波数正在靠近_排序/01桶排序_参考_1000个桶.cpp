# include <stdio.h>
//# include <stdlib.h>
int main()
{
	int book[1001],i,j,t; //数组用来标记每个数字出现的次数，所以用了book 

	for(i=0;i<=1000;i++)
	{
		book[i]=0;  
	}
	//输入十个童鞋的成绩，对应的桶内小旗加一 
	for(i=1;i<=10;i++)
	{
		scanf("%d",&t);
		book[t]++;
	 } 

	for(i=0;i<=1000;i++)
	{	//每个桶内有几个小旗就循环打印几次 
		for(j=1;j<=book [i];j++)
		{
			printf("%d ",i);
		}
	 } 
	 
	 //此处是为了暂停程序，避免程序一闪而过，两者可以代替 
	 getchar();getchar();
	// system("pause");  包含在头文件<stdlib.h>里 
	 
	 return 0;
}
