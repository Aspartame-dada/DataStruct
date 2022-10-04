/*
 * @Description:设计一个算法求A和B两个单链表表示的集合的交集。 提示：A和B中相同的结点的集合。
 * @Version: 1.0
 * @Autor: Aspartame
 * @Date: 2022-10-04 17:16:34
 */

 
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
 
//求 交集(A,B集合 中 相同的 元素)
void _intersection(set *A,set *B)
{
	set *q1 = A,*q2 = B;
	int sect[2*N] = {0};
	int i = 0;
	
	do//一一 比对 比对成功 则为相同 元素 
	{
		q2 = B;
		while(q2 != NULL)
		{
			if(q1->data == q2->data)//进行 比对 
			{
				sect[i ++] = q1->data;//比对 成功 保存在 交集数组 
			}
			else;
			
			q2 = q2->next;
		}
		q1 = q1->next;
		
	}while(q1 != NULL);
	//printf
	printf("交集:");
	print_set(sect);
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
 
int main(void)
{
	set *A,*B;
	int *sect,*uni,*diff;
	//生成 两个 集合 
	A = generate_set();
	M = 200;
	B = generate_set();
	
	//交集
	_intersection(A,B);

	
	//释放 A,B单链表 空间 
	release_link(A);
	release_link(B);
	return 0;
}