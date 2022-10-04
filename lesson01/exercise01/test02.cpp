/*
 * @Description: 有一个单链表的第一个结点指针为head,
 编写一个函数将该单链表逆置,即最后一个结点变成第一个结点,
 原来倒数第二个结点变成第二个结点。
 在逆置中不能建立新的单链表。
 * @Version: 1.0
 * @Autor: Aspartame
 * @Date: 2022-10-04 17:00:05
 */
#include <stdio.h>

#include <stdlib.h>

#include <malloc.h>

//定义存储结构

typedef struct

    Lnode
{

    int data;

    /*每个元素数据信息*/

    struct Lnode *next;

    /*后继元素的地址*/

} LNode, *LinkList;

    void Create_L(LinkList & L, int n);

    void Print_L(LinkList L);

    void ReverseList(LinkList L);
int main(void)

{
    LinkList La; //创建单链表La

    int n;

    printf("请输入链表La中的元素个数:\n");

    scanf("%d", &n);

    Create_L(La, n); //

    printf("现在La中的元素顺序为:\n");

    Print_L(La);

    printf("-------------------------------------\n\n");

    ReverseList(La);

    printf("逆置后，La的元素顺序为:\n");

    Print_L(La);
    return 0;
}

void Create_L(LinkList &L, int n)

{

    int j = 1;

    L = (LinkList)malloc(sizeof(Lnode));

    L->next = NULL; //先建立一个带头结点的单链线性表L

    for (int i = n; i > 0; --i)

    {

        LinkList p = (LinkList)malloc(sizeof(Lnode));

        printf("请输入链表中的第%d个元素:\n", j++);

        scanf("%d", &p->data);

        p->next = L->next;

        L->next = p;

    } 


} //初始化单链表

//输出单链表

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

        /*q指针保留p->next得值*/

        p->next = L->next;

        L->next = p;

        /*将p结点头插入到单链表L中*/

        p = q;

        /*p指向下一个要插入的结点*/
    }
}