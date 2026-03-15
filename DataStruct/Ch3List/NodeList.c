#include "stdio.h"

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
State creat_link_list(LinkList *l ,int n)
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
         
        if (p->next = NULL)
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
    while (j < n)
    {
        j++;
        p = p->next;
         
        if (p->next = NULL)
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
