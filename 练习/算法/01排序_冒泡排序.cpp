// 2、利用E62.CPP实现冒泡排序算法；
#include <stdio.h>
int main()
{
    int i,j,t,a[11];    //定义变量及数组为基本整型
    printf(" 2、利用E62.CPP实现冒泡排序算法；\n");
    printf("请输入10个待排序数据：\n");
    for(i=1;i<11;i++)
        scanf("%d",&a[i]);    //从键盘中输入10个数
    for(i=1;i<10;i++)    //变量i代表比较的趟数
        for(j=1;j<11-i;j++)    //变最j代表每趟两两比较的次数
            if(a[j]>a[j+1])
            {
                t=a[j];    //产利用中间变童实现两值互换
                a[j]=a[j+1];
                a[j+1]=t;
            }
            printf("\n插入数据排序后顺序：\n");
            for(i=1;i<=10;i++)
                printf("%d ",a[i]);    //将胃泡排序后的顺序输出
        printf("\n");
    return 0;
}
