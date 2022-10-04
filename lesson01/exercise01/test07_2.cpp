/*
 * @Description: 用头插法把单链表b中在单链表a中未出现的结点合并到单链表a中
 * @Version: 1.0
 * @Autor: Aspartame
 * @Date: 2022-10-04 17:26:10
 */
//链式存储

#include <stdio.h>
#include <stdlib.h>

struct num                                  //1.准备工作-结构体定义
{                                           //结构体包含：
	int a;                                  //①数据
	struct num *pNext;                      //②指针
};

#define SIZE sizeof(struct num)             //2.宏定义SIZE, 方便后续分配内存

struct num *CreatLiList(void)               //3.函数-返回结构体指针-建立链表
{
	struct num *spHead,*spPre,*spCur;       //头, 前, 现
	int n, count = 0;                      
	spPre  = (struct num *)malloc(SIZE);    //给Pre分配内存
	spHead = spPre;                         //Head指向Pre
	spHead -> pNext = NULL;                 //头结点中的②指针指向NULL
    
	do 
	{
		scanf("%d",&n);                     //输入数据
		if (count != 6)                     //结束标志
		{
            count ++;
			spCur = (struct num *)malloc(SIZE);  //给Cur分配内存

			spCur -> a = n;                      //赋予Cur①数据

			spCur -> pNext = NULL;               //Cur②指针指向NULL

			spPre -> pNext = spCur;              //Cur移到下一个
			spPre = spCur;                       //Pre移到Cur
		}
	} while (count != 6);                        //结束标志
	return spHead;                               //返回头节点, 成功创建链表
}


int AddNode(struct num *sp, int x)                   //函数-插入节点-传入头结点、插入数据
{
	struct num *spCur,*spNew;
	spCur = sp;
    int flag = 1;
	while((spCur -> pNext)->a < x)
	{
	    spCur = spCur -> pNext; 	
	}                                                //退出循环时，x 要插入Cur 与 Cur->next 之间

	spNew = (struct num *)malloc(SIZE);
	if (spNew == NULL)  return 1;
	
	spNew -> a = x;                                  //赋值
                                                     //e.g. 原来a→c，加入b后，a→b→c
    spNew -> pNext = spCur -> pNext ;                //让b→的 指向 a→的
    spCur -> pNext = spNew;                          //把a→的 改为 b
	
	
    return 1;
}



void TraverLiList(struct num *sp)                 //函数-遍历链表-传入头结点
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
	printf("输入数组6个元素的值。\n");
    struct num* head = CreatLiList();
    printf("此链表各个结点的数据域为：");
    TraverLiList(head); 
	printf("\n");
    int x;
    printf("输入要插入的数据x:");
    scanf("%d", &x);
    int i = AddNode(head, x);
    printf("插入后链表各个结点的数据域为：");
    TraverLiList(head); 
    return 0;
}