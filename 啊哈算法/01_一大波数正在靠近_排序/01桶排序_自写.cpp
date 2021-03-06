//想法：桶排序中，每一个桶代表一个数字i，每出现一个分数，分数相对应桶内的数值a[i]加一 
//错误：1.定义数组应该是a[11]而不是a[10];定义a[11]表示有十一个数即a[0]到a[10]
//      2.内层外层循环的变量不能相同，比如这里的i和j  
#include <stdio.h>

int main()
{
	int score;
	int a[11];   //错误1 
	
	//初始化数组：从a[0]开始i=0，到a[10]结束i<=10
	for(int i=0;i<=10;i++)
	{
		a[i]=0;
	}
	printf("请输入0-10分的成绩：\n");
	
	//循环输入五位同学的成绩：从第一位开始i=1，到第五位结束i<=5
	for(int i=1;i<=5;i++)
	{
		scanf("%d",&score);
		//分数相对应桶内数值加一 
		a[score]++; 
	}
	
	//从最高位开始i=10，到数组最低位结束i>=0 ，输出每个不为零的桶的值，输出次数依据a[score]确定 
	for(int i=10;i>=0;i--)
	{
		//不为零就打印 
		if(a[i]!=0) //这里其实不用判断是否等于零，因为内外循环是依据有几个小旗就循环几次，当为零时，其实本来就不会打印 
		{
			for(int j=1;j<=a[i];j++) //错误2 
			{
				printf("%d ",i);
			}
		}
	}
	return 0;
	
} 
