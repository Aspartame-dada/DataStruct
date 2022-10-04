
#include <stdio.h>
#include <stdlib.h>//���� ��� ���� rand() 
#include <time.h>  //��time()���� ��ȡ ��ǰ ʱ�� 
#include <malloc.h>  //��malloc() ���붯̬�ռ� ���� 
#define N 5
 
int M = rand()%101;//��� ������Χ 
 
typedef struct set{
	int data;
	struct set* next;	
}set;
 
//��ӡ ���� 
void print_set(int a[])
{
	for(int i = 0;i < 2 * N;i ++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
	
	return;
}
 
//���� ���� ���� A �� B
set* generate_set()
{
 
	set *q,*p,*head;
	q = (set *)malloc(sizeof(set));
	
	
	//�Ե�ǰʱ�� Ϊ���ӣ����ģ�� N �� ���� Ԫ�� (range(0,M))
	srand(time(NULL));
	q->data = rand()%(M + 1);
	printf("data:%d ",q->data);
    q->next = NULL;
	head = q;//head ��Ϊ �� ָ��(��ָ�� �� ������) 
	
	for(int i = 0;i < N - 1;i ++)
	{
		p = (set *)malloc(sizeof(set));
		
	    p->data = rand()%(M + 1);
		printf("%d ",p->data);
		p->next = NULL;
		
		q->next = p;
		q = p;
		p = p->next;
	}
	printf("\n");
	return head;
}
 
 
//�� ����(���������ڵ�����Ԫ�غϲ���һ����ɵļ��Ͻ���������A�ͼ���B�Ĳ�����)
void _union(set *A,set *B)
{
	set *q1 = A,*q2 = B;
	int uni[2 * N] = {0};
	int i = 0;
	
	while(q1 != NULL)
	{
		uni[i ++] = q1->data;
		q1 = q1->next;
	}
	while(q2 != NULL)
	{
		uni[i ++] = q2->data;
		q2 = q2->next;
	}
	//��ӡ 
	printf("����:");
	print_set(uni);
	return;
} 
 


//�ͷ� �ռ� 
void release_link(set *head)
{
	set *q,*p;
	q = p = head;
	while(q->next != NULL)
	{
		p = q->next;
		q->next = q->next->next;
		free(p);
	}
	free(head);
}
 
int main()
{
	set *A,*B;
	int *sect,*uni,*diff;
	//���� ���� ���� 
	A = generate_set();
	M = 200;
	B = generate_set();
	
	//����
	_union(A,B);

	//�ͷ� A,B������ �ռ� 
	release_link(A);
	release_link(B);
	return 0;
}