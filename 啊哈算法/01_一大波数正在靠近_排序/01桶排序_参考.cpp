# include <stdio.h>
//# include <stdlib.h>
int main()
{
	int a[11],i,j,t;
	//�����ʼ��Ϊ��
	for(i=0;i<=10;i++)
	{
		a[i]=0;  
	}
	//�������ͯЬ�ĳɼ�����Ӧ��Ͱ��С���һ 
	for(i=1;i<=5;i++)
	{
		scanf("%d",&t);
		a[t]++;
	 } 
	//ѭ������Ͱ 
	for(i=0;i<=10;i++)
	{	//ÿ��Ͱ���м���С���ѭ����ӡ���� 
		for(j=1;j<=a [i];j++)
		{
			printf("%d ",i);
		}
	 } 
	 
	 //�˴���Ϊ����ͣ���򣬱������һ�����������߿��Դ��� 
	 getchar();
	// system("pause");  ������ͷ�ļ�<stdlib.h>�� 
	 
	 return 0;
}
