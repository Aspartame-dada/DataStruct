/*
 * @Description: 生成两个多项式PA和PB，求PA和PB之和，输出“和多项式”。分别用顺序存储和链式存储两种存储结构实现
 * @Version: 1.0
 * @Autor: Aspartame
 * @Date: 2022-10-04 17:26:56
 */
//


#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
#include<math.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;

typedef struct polynmial
{
	float coef; //系数
	int exp; //指数

	struct polynmial *next; //指针
} Node, *LinkList;

Status Initpolyn(Node *L) //初始化链表
{
	L = (LinkList)malloc(sizeof(Node));
	if (!L)              //若空间申请失败则返回0退出
		return ERROR;
	L->next = NULL;  //指针初始化
	return OK;
}

Status Createpolyn(Node *L) //设置多项式
{
	int num, i;
	LinkList p;

	printf("\n请输入一元多项式的个数：\n");
	scanf("%d", &num);

	printf("\n请输入一元多项式的系数和指数（例：2*x^3输入为2，3）：\n");

	p = L;

	for (i=0; i<num; i++) //输入一项则申请一个空间进行储存
	{
		p->next = (LinkList)malloc(sizeof(Node));
		p = p->next;
		scanf("%f,%d", &p->coef, &p->exp);
	}
	p->next = NULL; //尾项指针赋值为空
	return OK;
}

void Display(Node *L) //输出多项式内容
{
	LinkList p;
	p = L->next;

	printf("\n该多项式为：\n");

	while (p != NULL) //若该项地址不为空，则遍历输出该多项式的内容
	{
		printf("%.2f x^%d  | ", p->coef, p->exp);
		p = p->next;
	}
}

void Addpolyn(Node *La, Node *Lb, Node *Lc, int n) //对多项式进行加减操作
{
	float sum;
	LinkList pa, pb, pc;
	pc = (LinkList)malloc(sizeof(Node)); //对实表进行初始化
	pc->next = NULL;

	pc = Lc; //利用一个实参储存新表的首结点

	pa = La->next;
	pb = Lb->next;

	while (pa && pb) //若两个表不为空，则循环对比
	{
		if (pa->exp == pb->exp) //若两项相等，则判断加或减运算，再对系数进行运算
		{
			if (n == 1)
			{
				sum = pa->coef + pb->coef;
			}
			else if (n == 0)
			{
				sum = pa->coef - pb->coef;
			}
			if (sum) //若系数不为0，则把运算后的系数和表A的指数存入新表中作为一项
			{
				pc->next = (LinkList)malloc(sizeof(Node));
				pc = pc->next;
				pc->coef = sum;
				pc->exp = pa->exp;
			}
			pa = pa->next;
			pb = pb->next;
		}
		else   //若两项不相等，则将系数小的一项存入新表中，然后遍历到下一项，循环判断直到一个表结束
		{
			pc->next = (LinkList)malloc(sizeof(Node));
			pc = pc->next;
			if (pa->exp < pb->exp)
			{
				pc->coef = pa->coef;
				pc->exp = pa->exp;
				pa = pa->next;
			}
			else if (pa->exp > pb->exp)
			{
				pc->coef = pb->coef;
				pc->exp = pb->exp;
				pb = pb->next;
			}
		}
	}
	
	while (pa) //若表A未结束，则将剩下的项均存入新表中
	{
		pc->next = (LinkList)malloc(sizeof(Node));
		pc = pc->next;
		pc->coef = pa->coef;
		pc->exp = pa->exp;
		pa = pa->next;
	}

	while (pb) //若表B未结束，则将剩下的项均存入新表中
	{
		pc->next = (LinkList)malloc(sizeof(Node));
		pc = pc->next;
		pc->coef = pb->coef;
		pc->exp = pb->exp;
		pb = pb->next;
	}

	pc->next = NULL;
}

double GetRe(Node *La, Node *Lb, Node *Lc) //计算多项式的值
{
	LinkList p = NULL;
	int name;
	double x, sum_poly = 0;
	
	scanf("%lf,%d", &x, &name); 

	switch (name) //判断对哪一个多项式进行计算
	{
	case 1:
		p = La->next;
		break;
	case 2:
		p = Lb->next;
		break;
	case 3:
		p = Lc->next;
		break;
	default:
		break;
	}

	while (p) //若该表地址非空，则遍历每一项进行运算
	{
		sum_poly += (double)p->coef * (double)(pow(x,p->exp));
		p = p->next;
	}

	return sum_poly;
}

int main()
{
	Node La, Lb, Lc;
	int change;
	double result;

	Initpolyn(&La); //创建表A，B
	Initpolyn(&Lb);

	Createpolyn(&La); //创建多项式A，B
	Display(&La);

	Createpolyn(&Lb);
	Display(&Lb);

	printf("\n若输入1则对多项式进行加操作，输入0则对多项式进行减操作：");
	scanf("%d", &change);

	Addpolyn(&La, &Lb, &Lc, change);
	Display(&Lc);

	printf("\n请输入x的值及需要计算的多项式（多项式可以选择输入1,2,3,对于着多项式a,b,c）[输入格式：2,1]： \n");

	result = GetRe(&La, &Lb, &Lc);
	printf("%.2lf\n", result);

	return 0;
}
