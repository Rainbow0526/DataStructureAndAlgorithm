//�뷨��10����ѭ����ÿһ����ѭ�����Ƚϡ����� ���������Ϻ��Ĵ����ʵ�ֲſ���д����
//���ģ��Խ�����������������д��ʱ��������� ��������scanfû�����պ� 
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
