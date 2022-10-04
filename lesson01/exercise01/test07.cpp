/*
 * @Description: 用头插法把单链表b中在单链表a中未出现的结点合并到单链表a中
 * @Version: 1.0
 * @Autor: Aspartame
 * @Date: 2022-10-04 17:26:10
 */
//顺序存储
#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int a;
    struct Node *next;
} Node, *list;
void j(list L);            //头插法
list hb(list LA, list LB); //合并单链表
int main()
{
    list A, B, C;
    A = (list)malloc(sizeof(Node));
    B = (list)malloc(sizeof(Node));

    A->next = NULL;
    B->next = NULL;

    printf("输入链表A：");
    j(A);

    printf("输入链表B：");
    j(B);
    printf("合并后：");
    C = (list)malloc(sizeof(Node));
    C->next = NULL;
    C = hb(A, B);
    C = C->next;
    while (C != NULL)
    {

        printf("%d ", C->a);
        C = C->next;
    }
    printf("\n");
    return 0;
}
void j(list L) //头插法
{
    list s;
    int c;
    int f = 1;
    while (f)
    {
        scanf("%d", &c);
        if (c != 0)
        {
            s = (list)malloc(sizeof(Node));
            s->a = c;
            s->next = L->next;
            L->next = s;
        }
        else
            f = 0;
    }
}

list hb(list A, list B) //合并两个链表
{
    Node *q, *b, *r;
    list C;
    q = A->next;
    b = B->next;
    C = A;
    C->next = NULL;
    r = C;
    while (q!=NULL)
    {
        /* code */
        for(){

        }
    if (q)
        r->next = q;

    }
    
    while (q != NULL && b != NULL)
    {
        if (q->a >= b->a)
        {
            r->next = q;
            r = q;
            q = q->next;
        }
        else
        {
            r->next = b;
            r = b;
            b = b->next;
        }
    }
    if (q)
        r->next = q;
    else
        r->next = b;
    free(B);
    return C;
}
