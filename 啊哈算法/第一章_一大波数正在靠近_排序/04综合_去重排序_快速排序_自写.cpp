//ʵ��ȥ�ء����� 
//������Ͱ���� 
//���󣺿�ʼû�ж�������г�ʼ�� �������ǲ���ֹ��0 
//ʱ�临�Ӷȣ�O��M+N�� 
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
