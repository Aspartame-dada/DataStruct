/*
 * @Description: ��ͷ�巨�ѵ�����b���ڵ�����a��δ���ֵĽ��ϲ���������a��
 * @Version: 1.0
 * @Autor: Aspartame
 * @Date: 2022-10-04 17:26:10
 */
//��ʽ�洢

#include <stdio.h>
#include <stdlib.h>

struct num                                  //1.׼������-�ṹ�嶨��
{                                           //�ṹ�������
	int a;                                  //������
	struct num *pNext;                      //��ָ��
};

#define SIZE sizeof(struct num)             //2.�궨��SIZE, ������������ڴ�

struct num *CreatLiList(void)               //3.����-���ؽṹ��ָ��-��������
{
	struct num *spHead,*spPre,*spCur;       //ͷ, ǰ, ��
	int n, count = 0;                      
	spPre  = (struct num *)malloc(SIZE);    //��Pre�����ڴ�
	spHead = spPre;                         //Headָ��Pre
	spHead -> pNext = NULL;                 //ͷ����еĢ�ָ��ָ��NULL
    
	do 
	{
		scanf("%d",&n);                     //��������
		if (count != 6)                     //������־
		{
            count ++;
			spCur = (struct num *)malloc(SIZE);  //��Cur�����ڴ�

			spCur -> a = n;                      //����Cur������

			spCur -> pNext = NULL;               //Cur��ָ��ָ��NULL

			spPre -> pNext = spCur;              //Cur�Ƶ���һ��
			spPre = spCur;                       //Pre�Ƶ�Cur
		}
	} while (count != 6);                        //������־
	return spHead;                               //����ͷ�ڵ�, �ɹ���������
}


int AddNode(struct num *sp, int x)                   //����-����ڵ�-����ͷ��㡢��������
{
	struct num *spCur,*spNew;
	spCur = sp;
    int flag = 1;
	while((spCur -> pNext)->a < x)
	{
	    spCur = spCur -> pNext; 	
	}                                                //�˳�ѭ��ʱ��x Ҫ����Cur �� Cur->next ֮��

	spNew = (struct num *)malloc(SIZE);
	if (spNew == NULL)  return 1;
	
	spNew -> a = x;                                  //��ֵ
                                                     //e.g. ԭ��a��c������b��a��b��c
    spNew -> pNext = spCur -> pNext ;                //��b���� ָ�� a����
    spCur -> pNext = spNew;                          //��a���� ��Ϊ b
	
	
    return 1;
}



void TraverLiList(struct num *sp)                 //����-��������-����ͷ���
{
	struct num *spCur;
	spCur = sp -> pNext;
	while (spCur != NULL)
	{
		printf("%d ", spCur->a);
		spCur = spCur -> pNext;
	}
}

int main()
{
	printf("��������6��Ԫ�ص�ֵ��\n");
    struct num* head = CreatLiList();
    printf("�������������������Ϊ��");
    TraverLiList(head); 
	printf("\n");
    int x;
    printf("����Ҫ���������x:");
    scanf("%d", &x);
    int i = AddNode(head, x);
    printf("����������������������Ϊ��");
    TraverLiList(head); 
    return 0;
}