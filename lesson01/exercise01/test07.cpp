/*
 * @Description: ��ͷ�巨�ѵ�����b���ڵ�����a��δ���ֵĽ��ϲ���������a��
 * @Version: 1.0
 * @Autor: Aspartame
 * @Date: 2022-10-04 17:26:10
 */
//˳��洢
#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int a;
    struct Node *next;
} Node, *list;
void j(list L);            //ͷ�巨
list hb(list LA, list LB); //�ϲ�������
int main()
{
    list A, B, C;
    A = (list)malloc(sizeof(Node));
    B = (list)malloc(sizeof(Node));

    A->next = NULL;
    B->next = NULL;

    printf("��������A��");
    j(A);

    printf("��������B��");
    j(B);
    printf("�ϲ���");
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
void j(list L) //ͷ�巨
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

list hb(list A, list B) //�ϲ���������
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
