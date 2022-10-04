/*
 * @Description: �������ǵݼ�����ĵ�����鲢Ϊһ���ǵݼ�����ĵ�����
 * @Version: 1.0
 * @Autor: Aspartame
 * @Date: 2022-10-04 17:11:15
 */
#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
using namespace std;
typedef int ElemType; //Ԫ������
typedef int Status;


#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
typedef struct node
{
    ElemType data;
    struct node *next;
} LinkNode, *LinkList;

Status Init_Linklist(LinkList &L)
{
    L = (LinkList)malloc(sizeof(LinkNode));
    if (!L)
        return ERROR;
    L->next = NULL;
    return OK;
}

/*β�巨����������*/
Status Creat_Linklist(LinkList &L)
{
    int x;
    LinkList p, rear;
    Init_Linklist(L); /*��ʼ���ձ�*/
    rear = L;         /*rearΪβָ�룬ָ��ǰ��β*/
    printf("����-1��ʾ�������\n");
    while (scanf("%d", &x), x != -1)
    {
        p = (LinkList)malloc(sizeof(LinkNode));
        if (!p)
            return ERROR;
        p->data = x;
        rear->next = p; /*p�������ڱ�β����*/
        rear = p;       /*��βָ��ָ���µı�βԪ��*/
    }
    rear->next = NULL; /*��βԪ�ص�ָ����ΪNULL*/
    return OK;
}

/*���������*/
void Disp_Linklist(LinkList L)
{
    LinkList p;
    p = L->next; /*pָ����е�һ��Ԫ��*/
    while (p)
    {
        printf("%d ", p->data);
        p = p->next; /*ָ�����ָ����һ��Ԫ��*/
    }
    printf("\n");
}
void MergeDescend_Linklist(LinkList La, LinkList Lb, LinkList &Lc)
{
    LinkList pa, pb, pc;
    pa = La->next;
    pb = Lb->next;
    pc = Lc = La;
    La->next = NULL;
    while (pa && pb)
    {
        if (pa->data <= pb->data)
        {
            pc = pa->next;
            pa->next = Lc->next;     // ÿ�ΰ�С�������뵽Lc����һλ�ã�����ͷ�巨
            Lc->next = pa;
            pa = pc;
        }
        else
        {
            pc = pb->next;
            pb->next = Lc->next;
            Lc->next = pb;
            pb = pc;
        }
    }
    while (pa)
    {   pc = pa->next;
        pa->next = Lc->next;
        Lc->next = pa;
        pa = pc;
    }
    while (pb)
    {   pc = pb->next;
        pb->next = Lc->next;
        Lc->next = pb;
        pb = pc;
    }

    
}
int main()
{
    LinkList L,La,Lb,Lc;
    Init_Linklist(La);
    Creat_Linklist(La);
    Init_Linklist(Lb);
    Creat_Linklist(Lb);
    MergeDescend_Linklist(La,Lb,Lc);
    Disp_Linklist(Lc);
    return 0;
}
