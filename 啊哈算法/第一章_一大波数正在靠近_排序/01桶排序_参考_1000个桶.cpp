# include <stdio.h>
//# include <stdlib.h>
int main()
{
	int book[1001],i,j,t; //�����������ÿ�����ֳ��ֵĴ�������������book 

	for(i=0;i<=1000;i++)
	{
		book[i]=0;  
	}
	//����ʮ��ͯЬ�ĳɼ�����Ӧ��Ͱ��С���һ 
	for(i=1;i<=10;i++)
	{
		scanf("%d",&t);
		book[t]++;
	 } 

	for(i=0;i<=1000;i++)
	{	//ÿ��Ͱ���м���С���ѭ����ӡ���� 
		for(j=1;j<=book [i];j++)
		{
			printf("%d ",i);
		}
	 } 
	 
	 //�˴���Ϊ����ͣ���򣬱������һ�����������߿��Դ��� 
	 getchar();getchar();
	// system("pause");  ������ͷ�ļ�<stdlib.h>�� 
	 
	 return 0;
}
