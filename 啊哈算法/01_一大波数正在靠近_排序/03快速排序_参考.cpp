#include <stdio.h>
int a[101],n;//����ȫ�ֱ�����������������Ҫ���Ӻ�����ʹ�� 

//���������� 
void quicksort(int left,int right) //�����ڱ����������ͱ��� 
{
	int i,j,t,temp;
	if(left>right)
		return;
	
	temp=a[left];//temp�д�ľ��ǻ�׼�� ��ȡ�������ڱ���Ӧ��ֵ 
	i=left;
	j=right;
	while(i!=j)
	{
		while(a[j]>=temp&&i<j)//˳�����Ҫ��Ҫ�ȴ��������� 
		{
			j--;
		}
		while(a[i]<=temp&&i<j)// �ٴ��������� 
		{
			i++;
		}
		//�����������������е�λ�� 
		if(i<j)//���ڱ�i���ڱ�jû������ʱ 
		{
			t=a[i];
			a[i]=a[j];
			a[j]=t;
		}
	}
	//�����ڱ������ƶ�ײ�����ڱ�ʱ������׼����λ 
	//����ǻ�׼����������С�ڻ�׼�����Ҳ���������ڻ�׼�� 
	a[left]=a[i]; 
	a[i]=temp;
	
	quicksort(left,i-1);//����������ߵģ�������һ���ݹ�Ĺ��� 
	quicksort(i+1,right);//���������ұߵģ�������һ���ݹ�Ĺ��� 
	return;
	
}

int main()
{
	int i,j;
	scanf("%d",&n);//���������� 
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]); //�������������������� 
	}
	quicksort(1,n);
	//��������Ľ�� 
	for(i=1;i<=n;i++)
	{
		printf("%d",a[i]);
	}
	getchar();getchar();
	return 0;
}
