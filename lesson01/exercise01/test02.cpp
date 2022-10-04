/*
 * @Description: ��һ��������ĵ�һ�����ָ��Ϊhead,
 ��дһ���������õ���������,�����һ������ɵ�һ�����,
 ԭ�������ڶ�������ɵڶ�����㡣
 �������в��ܽ����µĵ�����
 * @Version: 1.0
 * @Autor: Aspartame
 * @Date: 2022-10-04 17:00:05
 */
#include <stdio.h>

#include <stdlib.h>

#include <malloc.h>

//����洢�ṹ

typedef struct

    Lnode
{

    int data;

    /*ÿ��Ԫ��������Ϣ*/

    struct Lnode *next;

    /*���Ԫ�صĵ�ַ*/

} LNode, *LinkList;

    void Create_L(LinkList & L, int n);

    void Print_L(LinkList L);

    void ReverseList(LinkList L);
int main(void)

{
    LinkList La; //����������La

    int n;

    printf("����������La�е�Ԫ�ظ���:\n");

    scanf("%d", &n);

    Create_L(La, n); //

    printf("����La�е�Ԫ��˳��Ϊ:\n");

    Print_L(La);

    printf("-------------------------------------\n\n");

    ReverseList(La);

    printf("���ú�La��Ԫ��˳��Ϊ:\n");

    Print_L(La);
    return 0;
}

void Create_L(LinkList &L, int n)

{

    int j = 1;

    L = (LinkList)malloc(sizeof(Lnode));

    L->next = NULL; //�Ƚ���һ����ͷ���ĵ������Ա�L

    for (int i = n; i > 0; --i)

    {

        LinkList p = (LinkList)malloc(sizeof(Lnode));

        printf("�����������еĵ�%d��Ԫ��:\n", j++);

        scanf("%d", &p->data);

        p->next = L->next;

        L->next = p;

    } 


} //��ʼ��������

//���������

void Print_L(LinkList L)

{

    LinkList p;

    p = L->next;

    while (p)

    {

        printf("%d ", p->data);

        p = p->next;
    }

    printf("\n");
}

void ReverseList(LinkList L)

{

    LinkList p, q;

    p = L->next;

    L->next = NULL;

    while (p != NULL)
    {

        q = p->next;

        /*qָ�뱣��p->next��ֵ*/

        p->next = L->next;

        L->next = p;

        /*��p���ͷ���뵽������L��*/

        p = q;

        /*pָ����һ��Ҫ����Ľ��*/
    }
}