/*
 * @Description: ����һ��˳���A������n��Ԫ�أ�
 Ҫ��д��һ�����ñ����õ��㷨��
 ��ֻ������ԭ��Ĵ洢�ռ���������һ�����ӵĹ�����Ԫ
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
    printf("����һ��˳���\n");
    printf("����Ԫ�ظ�����");
    scanf("%d", &n);
    for (i=0;i<n;i++)
    {
        printf("�����%d��Ԫ��ֵ��", i+1);
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
        A[n-i-1]=temp;/*����*/
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