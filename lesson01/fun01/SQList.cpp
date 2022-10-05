/*
 * @Description:
 * @Version: 1.0
 * @Autor: Aspartame
 * @Date: 2022-10-04 15:43:42
 */
#include <stdio.h>
#include <malloc.h>
#define INTSIZE 128
typedef struct SqList
{
    int Maxsize;
    int *data;
    int length;
    /* data */
} SqList;
void initList(SqList &l);//初始化顺序表
bool ListDelete(SqList &l, int i);
void initList(SqList &l)
{
    l.data = (int *)malloc(sizeof(int) * INTSIZE);
    l.length = 0;
}
bool ListInsert(SqList &l, int i, int e)
{
    if (i < 0 || i > l.length + 2)
    {
        return false;
    }
    if (l.length >= l.Maxsize - 1)
    {
        return false;
    }
    for (int j = l.length; j >= i; j--)
    {
        /* code */
        l.data[j - 1] = l.data[j];
    }
    l.data[i - 1] = e;
    l.length += 1;
    return true;
}
bool ListDelete(SqList &l, int i)
{
    if (i < 0 || i > l.length - 1)
    {
        return false;
    }
    else
    {
        for (int j = i - 1; j < l.length; j++)
        {
            l.data[j] = l.data[j + 1];
        }
        l.length -= 1;
        return true;
    }
}
bool ListIsEmpty(SqList l){
    return l.length<=0?true:false;//如果顺序表长度小于等于0，则此时顺序表为空
}
bool ListChange(SqList &l, int i, int e){
    if (i>l.length+1|i-1<0){
        return 0;
    }else
    {
        l.data[i-1]=e;
        return 1;
    }
    

}
int ListLength(SqList l){
    return l.length;
}
int ListLocate(SqList l,int e){
    for (int i = 0; i < l.length; i++)
    {
        if(l.data[i]==e){
            return i+1;
        }
    }return -1;
    
}
int ListGetItem(SqList l,int i){
    return l.data[i];
}
bool displayList(SqList l)
{
    int i;
    if (l.length <= 0)
    {
        printf(" error\n");
        return 0;
    }
    else
    {
        printf(" is running--------\n");

        for (i = 0; i < l.length; i++)
        {
            printf(" is for--------%d\n", i);

            printf("%-4d\n", l.data[i]);
            /* code */
        }
        return 1;
    }
}
int main(void)
{
    SqList l;
    printf("this is start.......\n");
    initList(l);
    ListInsert(l, 1, 1);
    ListInsert(l, 2, 2);
    ListInsert(l, 3, 3);
    int i=ListLocate(l,3);
    // ListDelete(l, 2);
    // ListChange(l,1,55);
    // displayList(l);
    // int res=ListIsEmpty(l);
        printf("this is result.......%d\n",i);

    printf("this is end.......");

    return 0;
}
