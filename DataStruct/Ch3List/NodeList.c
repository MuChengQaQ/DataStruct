#include "stdio.h"
#include <stdlib.h>

#define State int
#define ElemType int
#define ERROR 0
#define OK 1


//定义单线形表节点Node
typedef struct Node
{
    ElemType data;
    struct Node * next;
} Node;
typedef Node * LinkList; //头指针类型

//创建一个链表
State creat_link_list(LinkList *l ,int n)//n为全部节点数量，包含头节点
{
int j = 0 ;
LinkList p,q;
*l = (LinkList)malloc(sizeof(Node));
(*l)->next = NULL;
p = *l;
while (j<n+1)
{
    ++j;
    
    q = (LinkList)malloc(sizeof(Node));
    q->next = p->next;
    p->next = q;
    q->data = j-2;
}

return OK;
}

State delete_link_list(LinkList *l)
{
    int j ;
    LinkList p,q ;
    p = *l ;
    while (p != NULL)
    {
        q = p->next;
        free(p);
        p = q;
    }
    return OK;
}

State seach_node (LinkList l , int n , ElemType *e)
{   
    int j = 0;
    LinkList p ;
    p = l ;
    while (j < n)
    {
        j++;
        p = p->next;
         
        if (p->next == NULL)
        {
            printf("输入位置超出链表长度\n");
            return ERROR;
        }
    }
    *e = p->data;

    return OK;
}

State add_node (LinkList l , int n, ElemType e)
{
     
    int j = 0;
    LinkList p ,q;
    p = l ;
        while (j < n-1)
        {
            j++;
            p = p->next;
         
            if (p->next == NULL)
            {
                printf("输入位置超出链表长度\n");
                return ERROR;
            }
        }
        q = (LinkList)malloc (sizeof (Node));
        q->next = p->next ;
        p->next = q ;
        q->data = e;
    return OK;
}

State delete_node (LinkList l , int n,ElemType *e) 
{
  
    int j = 0;
    LinkList p ,q;
    p = l ;
    while (j < n-1)
    {
        j++;
        p = p->next;
         
        if (p->next == NULL)
        {
            printf("输入位置超出链表长度\n");
            return ERROR;
        }
    }
    q = p;
    p = p->next ;
    q->next = p->next;
    *e = p->data;
    free (p);
    return OK;
}

State creat_circle_list (LinkList *l, int n)
{
    int j = 0 ;
    LinkList p,q;
    *l = (LinkList)malloc(sizeof(Node));
    (*l)->next = NULL;
    p = *l;
    while (j<n)
    {
        j++;
        p->data = j;
        q = (LinkList)malloc(sizeof(Node));
        q->next = p->next;
        p->next = q;
    }
    q->next = *l ;

    return OK;
}

int main (void)
{   
    printf("该程序为链表的相关程序，有生成，删除，插入，读取功能\n");
    LinkList l;
    ElemType e, e1=0;
    creat_link_list (&l , 10 );
   
    for (size_t i = 0; i < 10; i++)
    {
        seach_node(l ,i,&e1);
        printf("%d\n",e1);
    }
    

    seach_node(l , 2 , &e);
    seach_node(l , 11, &e);


    add_node(l ,2,222);
    for (size_t i = 0; i < 11; i++)
    {
        seach_node(l ,i,&e1);
        printf("%d\n",e1);
    }
    add_node(l, 15, 2222);
 

    delete_node(l ,2 , &e);
    for (size_t i = 0; i < 10; i++)
    {
        seach_node(l ,i,&e1);
        printf("%d\n",e1);
    }
    delete_node(l , 15, &e);
   

    delete_link_list(&l);
    for (size_t i = 0; i < 10; i++)
    {
        seach_node(l ,i,&e1);
        printf("%d\n",e1);
    }
return 0;
}