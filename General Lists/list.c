
#include "list.h"
#include <stdio.h>
#include <stdlib.h>


void  List_Create(list *pq)
{
    pq->size=0;
}

List_Status  List_Add_Element(list *pq, List_Type e)
{
    if(pq->size<Maxlist)
    {
    pq->entry[pq->size]=e;
    pq->size++;
    return List_no_error;
    }
    else
    {
        printf("List is Full\n");
        return List_full;
    }

}

List_Status  List_Insert_Element(int pos, list *pq, List_Type e)
{
    if(pq->size<Maxlist)
    {
         if(pos<(pq->size))
    {
        for(int n=(pq->size)-1; n>=pos-1; n--)
            pq->entry[n+1]=pq->entry[n];
    }
        pq->entry[pos-1]=e;
        pq->size++;
        printf("inserted\n");
        return List_no_error;
    }
    else
    {
        printf("List is Full\n");
        return List_full;
    }

}
List_Status  List_Delete_Element(int pos, list *pq, List_Type *e)
{
    for(int n=pos-1; n<(pq->size)-1; n++)
    {
        pq->entry[n]=pq->entry[n+1];
    }
    *e=pq->entry[pos-1];
    pq->size--;
    return List_no_error;
}

List_Status  List_Empty(list *pq)
{
    if(pq->size==0)
    {
     printf("List is Empty \n");
     return List_empty;
    }
    else
        return List_non_empty;
}

List_Status  List_clear(list *pq)
{
    pq->size=0;
    return List_no_error;
}

List_Status  List_Full(list *pq)
{
    if(pq->size==Maxlist)
        return List_full;
    else
        return List_not_full;
}

List_Status  List_Traverse(list *pq, void(*pf)(List_Type e))
{
    if(pq->size==0)
       {
           printf("List is Empty \n");
           return List_empty;
       }
    else
        {
            for(int n=0; n<=(pq->size)-1; n++)
            {
                 (*pf)(pq->entry[n]);
            }
             return List_no_error;
        }
}
