#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;
int num1, num2;

typedef struct
{
	float coef; //系数
	int	exp; //指数
} Node;

typedef struct
{
	Node *elem; //数据基地址
	int length; //表的长度
} LinkList;

Status Initpolyn(LinkList *L, int n)    //多项式的初始化                            
{
	L->elem = (Node *)malloc(sizeof(Node) * n);
	if (L->elem == NULL) //若空间申请失败，则返回0退出
		return ERROR;
	L->length = 0; //未输入前表的长度置为0
	return OK;
}

void Inputpolyn(LinkList *La, int n) //输入系数和指数
{
	int y, i;
	float x;

	printf("依次输入系数和指数（例：2*x^3输入为2,3）：\n");

	for (i=0; i<n; i++)
	{
		scanf("%f,%d", &x, &y); //x为系数，y为指数

		La->elem[i].coef = x;
		La->elem[i].exp = y;
		La->length++; //完整输入一项后，表长度加1
	}

}

void Outputpolyn(LinkList *L) //遍历输出多项式的内容
{	
	int i = 0;

	for (i = 0; i < L->length; i++)
	{
		printf("%.2f x^%d  | ", L->elem[i].coef, L->elem[i].exp);
	}	
}

Status addpolyn(LinkList *La, LinkList *Lb, LinkList *Lc, int n) //多项式加减运算
{
	int i=0, j=0, k=0;
	float coe;

	Lc->elem = (Node *)malloc(sizeof(Node) * (La->length + Lb->length)); //建立新表
	if (La->length == 0) //若表A为空，则新表等于表B
	{
		Lc = Lb;
		return OK;
	}
	if (Lb->length == 0) //若表B为空，则新表等于表A
	{
		Lc = La;
		return OK;
	}

	while (i<La->length && j<Lb->length) //用i，j分别来表示表A，B已经存入新表的项数
	{
		if (La->elem[i].exp < Lb->elem[i].exp) //若表A的项系数比表B的小，则插入新表
		{
			Lc->elem[k] = La->elem[i];
			k++;
			i++;
		}
		else if (La->elem[i].exp > Lb->elem[i].exp) //若表B的项系数比表A的小，则插入新表
		{
			Lc->elem[k] = Lb->elem[j];
			k++;
			j++;
		}
		else //若两表的系数相等，则判断加或减操作，再判断运算后的系数是否为0
		{
			if (n == 1)
				coe = La->elem[i].coef + Lb->elem[j].coef;
			else if (n == 0)
				coe = La->elem[i].coef - Lb->elem[j].coef;

			if (coe != 0) //若系数不为0，则将运算后得到的系数和表A的指数作为一项存入新表中
			{
				Lc->elem[k].exp = La->elem[i].exp;
				Lc->elem[k].coef = coe;
				k++;
			}
			i++;
			j++;
		}
	}

	if (i == La->length) //若表A已经遍历完且表B还没有，则将表B剩下的内容存入新表中
	{
		while (j < Lb->length)
		{
			Lc->elem[k].exp = Lb->elem[j].exp;
			Lc->elem[k].coef = Lb->elem[j].coef;
			j++;
			k++;
		}
	}

	if (j == Lb->length) //若表B已经遍历完且表A还没有，则将表B剩下的内容存入新表中
	{
		while (i < La->length)
		{
			Lc->elem[k].exp = La->elem[i].exp;
			Lc->elem[k].coef = La->elem[i].coef;
			j++;
			k++;
		}
	}

	Lc->length = k; //设置新表的长度
	return OK;
}

double GetResult(LinkList *La, LinkList *Lb, LinkList *Lc) //对多项式进行计算
{
	LinkList *p;
	int name, L_length, i;
	double x, sum_polyn = 0;

	scanf("%lf,%d", &x, &name);

	switch (name) //判断选择哪一个多项式进行计算
	{
	case 1:
		L_length = La->length;
		p = La;
		break;
	case 2:
		L_length = Lb->length;
		p = Lb;
		break;
	case 3:
		L_length = Lc->length;
		p = Lc;
		break;
	default :
		break;
	}
	
	for (i=0; i<L_length; i++) //遍历的方式进行计算
	{
		sum_polyn += p->elem[i].coef * (pow(x,p->elem[i].exp));
	}
	return sum_polyn;

}

int main(void)
{
	LinkList La, Lb, Lc;
	int change;
	double result;

	printf("输入第一个多项式的项数：");
	scanf("%d", &num1);

	Initpolyn(&La, num1);
	Inputpolyn(&La, num1);
	
	printf("输入第二个多项式的项数：");
	scanf("%d", &num2);

	Initpolyn(&Lb, num2);
	Inputpolyn(&Lb, num2);

	printf("两个多项式分别为：\n");

	Outputpolyn(&La);
	printf("\n");

	Outputpolyn(&Lb);

	printf("\n令多项式相加输入1，相减输入0: \n");
	scanf("%d", &change);

	addpolyn(&La, &Lb, &Lc, change);

	printf("相加减后的结果为: \n");

	Outputpolyn(&Lc);

	printf("\n请输入x的值及其需要计算的多项式[输入格式：2.1,1](前面为x的值，后面可以输入1,2,3分别对应多项式a,b,c)：");

	result = GetResult(&La, &Lb, &Lc);
	printf("%.2lf\n", result);

	return 0;
}
