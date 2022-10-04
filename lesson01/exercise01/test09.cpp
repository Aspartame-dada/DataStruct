/*
 * @Description: ������������ʽPA��PB����PA��PB֮�ͣ�������Ͷ���ʽ�����ֱ���˳��洢����ʽ�洢���ִ洢�ṹʵ��
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
	float coef; //ϵ��
	int exp; //ָ��

	struct polynmial *next; //ָ��
} Node, *LinkList;

Status Initpolyn(Node *L) //��ʼ������
{
	L = (LinkList)malloc(sizeof(Node));
	if (!L)              //���ռ�����ʧ���򷵻�0�˳�
		return ERROR;
	L->next = NULL;  //ָ���ʼ��
	return OK;
}

Status Createpolyn(Node *L) //���ö���ʽ
{
	int num, i;
	LinkList p;

	printf("\n������һԪ����ʽ�ĸ�����\n");
	scanf("%d", &num);

	printf("\n������һԪ����ʽ��ϵ����ָ��������2*x^3����Ϊ2��3����\n");

	p = L;

	for (i=0; i<num; i++) //����һ��������һ���ռ���д���
	{
		p->next = (LinkList)malloc(sizeof(Node));
		p = p->next;
		scanf("%f,%d", &p->coef, &p->exp);
	}
	p->next = NULL; //β��ָ�븳ֵΪ��
	return OK;
}

void Display(Node *L) //�������ʽ����
{
	LinkList p;
	p = L->next;

	printf("\n�ö���ʽΪ��\n");

	while (p != NULL) //�������ַ��Ϊ�գ����������ö���ʽ������
	{
		printf("%.2f x^%d  | ", p->coef, p->exp);
		p = p->next;
	}
}

void Addpolyn(Node *La, Node *Lb, Node *Lc, int n) //�Զ���ʽ���мӼ�����
{
	float sum;
	LinkList pa, pb, pc;
	pc = (LinkList)malloc(sizeof(Node)); //��ʵ����г�ʼ��
	pc->next = NULL;

	pc = Lc; //����һ��ʵ�δ����±���׽��

	pa = La->next;
	pb = Lb->next;

	while (pa && pb) //��������Ϊ�գ���ѭ���Ա�
	{
		if (pa->exp == pb->exp) //��������ȣ����жϼӻ�����㣬�ٶ�ϵ����������
		{
			if (n == 1)
			{
				sum = pa->coef + pb->coef;
			}
			else if (n == 0)
			{
				sum = pa->coef - pb->coef;
			}
			if (sum) //��ϵ����Ϊ0�����������ϵ���ͱ�A��ָ�������±�����Ϊһ��
			{
				pc->next = (LinkList)malloc(sizeof(Node));
				pc = pc->next;
				pc->coef = sum;
				pc->exp = pa->exp;
			}
			pa = pa->next;
			pb = pb->next;
		}
		else   //�������ȣ���ϵ��С��һ������±��У�Ȼ���������һ�ѭ���ж�ֱ��һ�������
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
	
	while (pa) //����Aδ��������ʣ�µ���������±���
	{
		pc->next = (LinkList)malloc(sizeof(Node));
		pc = pc->next;
		pc->coef = pa->coef;
		pc->exp = pa->exp;
		pa = pa->next;
	}

	while (pb) //����Bδ��������ʣ�µ���������±���
	{
		pc->next = (LinkList)malloc(sizeof(Node));
		pc = pc->next;
		pc->coef = pb->coef;
		pc->exp = pb->exp;
		pb = pb->next;
	}

	pc->next = NULL;
}

double GetRe(Node *La, Node *Lb, Node *Lc) //�������ʽ��ֵ
{
	LinkList p = NULL;
	int name;
	double x, sum_poly = 0;
	
	scanf("%lf,%d", &x, &name); 

	switch (name) //�ж϶���һ������ʽ���м���
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

	while (p) //���ñ��ַ�ǿգ������ÿһ���������
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

	Initpolyn(&La); //������A��B
	Initpolyn(&Lb);

	Createpolyn(&La); //��������ʽA��B
	Display(&La);

	Createpolyn(&Lb);
	Display(&Lb);

	printf("\n������1��Զ���ʽ���мӲ���������0��Զ���ʽ���м�������");
	scanf("%d", &change);

	Addpolyn(&La, &Lb, &Lc, change);
	Display(&Lc);

	printf("\n������x��ֵ����Ҫ����Ķ���ʽ������ʽ����ѡ������1,2,3,�����Ŷ���ʽa,b,c��[�����ʽ��2,1]�� \n");

	result = GetRe(&La, &Lb, &Lc);
	printf("%.2lf\n", result);

	return 0;
}
