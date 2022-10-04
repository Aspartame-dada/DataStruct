/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Aspartame
 * @Date: 2022-10-04 15:43:42
 */
#include<stdio.h>
#include<malloc.h>
#define INTSIZE 128
typedef struct SqList
{
    int Maxsize;
    int *data;
    int length;
    /* data */
};

SqList initList(SqList &l){
    l.length=0;
}
bool ListInsert(SqList &l,int i,int e){
    if(i<1||i>l.length){
        return false;
    }
    if (l.length>=l.Maxsize){
        return false;
    }
    for (int j=l.length; j >=i;j++)
    {
        /* code */
        l.data[j]=l.data[j-1];
        l.data[i-1]=e;
        printf("≤Â»Î≥…π¶");
        return true;
    }
    
    
}
int main(void){
    SqList l;
    initList(l);
    ListInsert(l,0,3);

    return 0;
}

