/*
 * @Description: 将两个非递减有序的单链表归并为一个非递减有序的单链表
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
typedef int ElemType; //元素类型
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

/*尾插法建立单链表*/
Status Creat_Linklist(LinkList &L)
{
    int x;
    LinkList p, rear;
    Init_Linklist(L); /*初始化空表*/
    rear = L;         /*rear为尾指针，指向当前表尾*/
    printf("输入-1表示输入结束\n");
    while (scanf("%d", &x), x != -1)
    {
        p = (LinkList)malloc(sizeof(LinkNode));
        if (!p)
            return ERROR;
        p->data = x;
        rear->next = p; /*p结点插入在表尾后面*/
        rear = p;       /*表尾指针指向新的表尾元素*/
    }
    rear->next = NULL; /*表尾元素的指针域为NULL*/
    return OK;
}

/*单链表遍历*/
void Disp_Linklist(LinkList L)
{
    LinkList p;
    p = L->next; /*p指向表中第一个元素*/
    while (p)
    {
        printf("%d ", p->data);
        p = p->next; /*指针后移指向下一个元素*/
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
            pa->next = Lc->next;     // 每次把小的数插入到Lc的下一位置，类似头插法
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
