
#include <stdio.h>
#include <stdlib.h>//包含 随机 函数 rand() 
#include <time.h>  //含time()函数 获取 当前 时间 
#include <malloc.h>  //含malloc() 申请动态空间 函数 
#define N 5
 
int M = rand()%101;//随机 变量范围 
 
typedef struct set{
	int data;
	struct set* next;	
}set;
 
//打印 集合 
void print_set(int a[])
{
	for(int i = 0;i < 2 * N;i ++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
	
	return;
}
 
//生成 两个 集合 A 和 B
set* generate_set()
{
 
	set *q,*p,*head;
	q = (set *)malloc(sizeof(set));
	
	
	//以当前时间 为种子，随机模拟 N 个 集合 元素 (range(0,M))
	srand(time(NULL));
	q->data = rand()%(M + 1);
	printf("data:%d ",q->data);
    q->next = NULL;
	head = q;//head 作为 首 指针(该指针 下 有数据) 
	
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
 
 
//求 并集(两个集合内的所有元素合并在一起组成的集合叫做“集合A和集合B的并集”)
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
	//打印 
	printf("并集:");
	print_set(uni);
	return;
} 
 


//释放 空间 
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
	//生成 两个 集合 
	A = generate_set();
	M = 200;
	B = generate_set();
	
	//并集
	_union(A,B);

	//释放 A,B单链表 空间 
	release_link(A);
	release_link(B);
	return 0;
}