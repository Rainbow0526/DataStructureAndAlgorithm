#include <stdio.h>
int main()
{
	int a[100],i,j,t,n;
	scanf("%d",&n);//����һ��������ʾ��������n���� 
	
	for(i=1;i<=n;i++)//ѭ������n����������a�� 
	{
		scanf("%d",&a[i]); 
	}
	//ð������ĺ��Ĳ��� 
	for(i=1;i<=n-1;i++) //n��������ֻ�ܽ���n-1�� 
	{
		for(j=1;j<=n-i;j++) //�ӵ�һλ��ʼ�Ƚ�ֱ�����һ����δ��λ���� 
		{
			//�Ƚϴ�С������ 
			if(a[j]<a[j+1]) 
			{
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}
	}
	//������ 
	for(i=1;i<=n;i++)
	{
		printf("%d ",a[i]);
	 } 
	 
	 getchar();getchar();
	 return 0;
 } 
