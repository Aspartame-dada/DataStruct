/*
 * @Description: �����Ա��е�����Ԫ���ǰ�ֵ�ǵݼ��������еģ�����˳��洢����ʽ�洢���ִ洢�ṹʵ�֣���дһ�㷨����x���뵽���Ա���ʵ�λ���ϣ��Ա������Ա��������
 * @Version: 1.0
 * @Autor: Aspartame
 * @Date: 2022-10-04 17:26:31
 */
#include<stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
#define OK 1
typedef int ElemType;
typedef int Status;
#define OVEERFLOW -2
typedef struct
{
    ElemType *elem;
    int length;
} SqList;
Status InitList_Sq(SqList &A)
{
    int i;
    A.elem = new ElemType[10];
    if (!A.elem)
        exit(OVEERFLOW);
    A.length = 10;
    for (i = 0; i < 10; i++)
        A.elem[i] = i;
    return OK;
}
int ListInsert(SqList &A, int item)
{
    int i, j, t;
    for (i = 0; i < A.length; i++)
    {
        if (A.elem[i] > item)
        {
            A.length = A.length + 1;
            for (j = A.length - 1; j >= i; j--)
            {
                A.elem[j + 1] = A.elem[j];
                A.elem[i] = item;
            }

            break;
        }
    }

    for (i = 0; i < A.length; i++)
    {
        t = A.elem[i];
        A.elem[i] = A.elem[A.length - i - 1];
        A.elem[A.length - i - 1] = t;
    }
    return OK;
}
int main()
{
    int i, item;
    SqList A;
    InitList_Sq(A);
    for (i = 0; i < 10; i++)
        printf("%5d", A.elem[i]);
    printf("\n");
    printf("������Ҫ�����ֵ��");
    scanf("%d", &item);
    ListInsert(A, item);
    for (i = 0; i < A.length; i++)
        printf("%5d", A.elem[i]);
    printf("\n");
    return 0;
}
