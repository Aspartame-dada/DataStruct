/*
 * @Description: 设有一个顺序表A，包含n个元素，
 要求写出一个将该表逆置的算法，
 并只允许在原表的存储空间外再增加一个附加的工作单元
 * @Version: 1.0
 * @Autor: Aspartame
 * @Date: 2022-10-04 16:57:03
 */
 #include <stdio.h>
#define MaxLen 50
typedef int elemtype;
typedef elemtype sqlist[MaxLen];
 
int create (sqlist A)
{
    int i,n;
    printf("创建一个顺序表\n");
    printf("输入元素个数：");
    scanf("%d", &n);
    for (i=0;i<n;i++)
    {
        printf("输入第%d个元素值：", i+1);
        scanf("%d", &A[i]);
    }
    return n;
}
 
void invert(sqlist A,int n)
{
    int m=n/2,i;
    elemtype temp;
    for (i=0;i<m;i++)
    {
        temp=A[i];
        A[i]=A[n-i-1];
        A[n-i-1]=temp;/*交换*/
    }
}
void disp(sqlist A, int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d", A[i]);
    }
    printf("\n");
}
int main(void)
{
    sqlist A;
    int n;
    n = create(A);
    disp(A, n);
    invert(A, n);
    disp(A, n);
    return 0;
}