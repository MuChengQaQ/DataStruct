#include "stdio.h"
#include "stdlib.h"

#define State int
#define ERROR 0
#define OK 1
#define Elemtype int
#define MAXSIZE 10

typedef struct SqStack
{
    Elemtype data[MAXSIZE];
    int top;

 }SqStack ;

State init_sqstack(SqStack *s)
{
    s->top = -1;

    return OK ; 
}

State StackEmpty(SqStack S)
{ 
        if (S.top==-1)
                return OK;
        else
                return ERROR ;
}

State CLeanStack (SqStack *s)
{   
    s->top = -1;
    return OK;
}

State push(SqStack *s ,Elemtype e )
{  
    if (s->top == MAXSIZE-1)
        return ERROR;
    
    s->top ++;
    s->data[s->top] = e;
    
    return OK;
}

State pop (SqStack *s ,Elemtype *e)
{   
    if (s->top == -1)
    {
        return ERROR;
    }
    *e = s->data[s->top];
    s->top -- ;

    return OK;
}

State show_sqstack(SqStack *s)
{
    int i ;
    i = 0;
    while (i < s->top)
    {
        printf("%d  ",s->data[s->top]);
        s->top --;

    }
    printf("\n");


    return OK;
}


int main ()
{
        int j;
        SqStack s;
        int e;
        if(init_sqstack(&s)==OK)
                for(j=1;j<=10;j++)
                        push(&s,j);
        printf("栈中元素依次为：");
        show_sqstack(&s);
        pop(&s,&e);
        printf("弹出的栈顶元素 e=%d\n",e);
        printf("栈空否：%d(1:空 0:否)\n",StackEmpty(s));
       // GetTop(s,&e);
       // printf("栈顶元素 e=%d 栈的长度为%d\n",e,StackLength(s));
       CLeanStack(&s);
        printf("清空栈后，栈空否：%d(1:空 0:否)\n",StackEmpty(s));
        

    return 0;
}