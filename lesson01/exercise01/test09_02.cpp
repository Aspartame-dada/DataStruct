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
	float coef; //ϵ��
	int	exp; //ָ��
} Node;

typedef struct
{
	Node *elem; //���ݻ���ַ
	int length; //��ĳ���
} LinkList;

Status Initpolyn(LinkList *L, int n)    //����ʽ�ĳ�ʼ��                            
{
	L->elem = (Node *)malloc(sizeof(Node) * n);
	if (L->elem == NULL) //���ռ�����ʧ�ܣ��򷵻�0�˳�
		return ERROR;
	L->length = 0; //δ����ǰ��ĳ�����Ϊ0
	return OK;
}

void Inputpolyn(LinkList *La, int n) //����ϵ����ָ��
{
	int y, i;
	float x;

	printf("��������ϵ����ָ��������2*x^3����Ϊ2,3����\n");

	for (i=0; i<n; i++)
	{
		scanf("%f,%d", &x, &y); //xΪϵ����yΪָ��

		La->elem[i].coef = x;
		La->elem[i].exp = y;
		La->length++; //��������һ��󣬱��ȼ�1
	}

}

void Outputpolyn(LinkList *L) //�����������ʽ������
{	
	int i = 0;

	for (i = 0; i < L->length; i++)
	{
		printf("%.2f x^%d  | ", L->elem[i].coef, L->elem[i].exp);
	}	
}

Status addpolyn(LinkList *La, LinkList *Lb, LinkList *Lc, int n) //����ʽ�Ӽ�����
{
	int i=0, j=0, k=0;
	float coe;

	Lc->elem = (Node *)malloc(sizeof(Node) * (La->length + Lb->length)); //�����±�
	if (La->length == 0) //����AΪ�գ����±���ڱ�B
	{
		Lc = Lb;
		return OK;
	}
	if (Lb->length == 0) //����BΪ�գ����±���ڱ�A
	{
		Lc = La;
		return OK;
	}

	while (i<La->length && j<Lb->length) //��i��j�ֱ�����ʾ��A��B�Ѿ������±������
	{
		if (La->elem[i].exp < Lb->elem[i].exp) //����A����ϵ���ȱ�B��С��������±�
		{
			Lc->elem[k] = La->elem[i];
			k++;
			i++;
		}
		else if (La->elem[i].exp > Lb->elem[i].exp) //����B����ϵ���ȱ�A��С��������±�
		{
			Lc->elem[k] = Lb->elem[j];
			k++;
			j++;
		}
		else //�������ϵ����ȣ����жϼӻ�����������ж�������ϵ���Ƿ�Ϊ0
		{
			if (n == 1)
				coe = La->elem[i].coef + Lb->elem[j].coef;
			else if (n == 0)
				coe = La->elem[i].coef - Lb->elem[j].coef;

			if (coe != 0) //��ϵ����Ϊ0���������õ���ϵ���ͱ�A��ָ����Ϊһ������±���
			{
				Lc->elem[k].exp = La->elem[i].exp;
				Lc->elem[k].coef = coe;
				k++;
			}
			i++;
			j++;
		}
	}

	if (i == La->length) //����A�Ѿ��������ұ�B��û�У��򽫱�Bʣ�µ����ݴ����±���
	{
		while (j < Lb->length)
		{
			Lc->elem[k].exp = Lb->elem[j].exp;
			Lc->elem[k].coef = Lb->elem[j].coef;
			j++;
			k++;
		}
	}

	if (j == Lb->length) //����B�Ѿ��������ұ�A��û�У��򽫱�Bʣ�µ����ݴ����±���
	{
		while (i < La->length)
		{
			Lc->elem[k].exp = La->elem[i].exp;
			Lc->elem[k].coef = La->elem[i].coef;
			j++;
			k++;
		}
	}

	Lc->length = k; //�����±�ĳ���
	return OK;
}

double GetResult(LinkList *La, LinkList *Lb, LinkList *Lc) //�Զ���ʽ���м���
{
	LinkList *p;
	int name, L_length, i;
	double x, sum_polyn = 0;

	scanf("%lf,%d", &x, &name);

	switch (name) //�ж�ѡ����һ������ʽ���м���
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
	
	for (i=0; i<L_length; i++) //�����ķ�ʽ���м���
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

	printf("�����һ������ʽ��������");
	scanf("%d", &num1);

	Initpolyn(&La, num1);
	Inputpolyn(&La, num1);
	
	printf("����ڶ�������ʽ��������");
	scanf("%d", &num2);

	Initpolyn(&Lb, num2);
	Inputpolyn(&Lb, num2);

	printf("��������ʽ�ֱ�Ϊ��\n");

	Outputpolyn(&La);
	printf("\n");

	Outputpolyn(&Lb);

	printf("\n�����ʽ�������1���������0: \n");
	scanf("%d", &change);

	addpolyn(&La, &Lb, &Lc, change);

	printf("��Ӽ���Ľ��Ϊ: \n");

	Outputpolyn(&Lc);

	printf("\n������x��ֵ������Ҫ����Ķ���ʽ[�����ʽ��2.1,1](ǰ��Ϊx��ֵ�������������1,2,3�ֱ��Ӧ����ʽa,b,c)��");

	result = GetResult(&La, &Lb, &Lc);
	printf("%.2lf\n", result);

	return 0;
}
