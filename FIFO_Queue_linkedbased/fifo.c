#include "fifo.h"
#include "stdio.h"
#include "stdlib.h"

void  Queue_Create(Queue *pq)
{
    pq->front=NULL;
    pq->rear=NULL;
    pq->size=0;
}

void  Queue_Append(Queue *pq, Queue_Type e)
{
    QueueNode* pn=(QueueNode*)malloc(sizeof(QueueNode));
    pn->next=NULL;
    pn->entry=e;
    if(pq->rear != NULL)
    {
        pq->rear->next=pn;
    }
    else pq->front=pn;
    pq->rear=pn;
    pq->size++;
}
void  Queue_Serve(Queue *pq, Queue_Type *e)
{
    QueueNode* pn=pq->front;
    *e=pn->entry;
    pq->front=pn->next;
    free(pn);
    if(pq->front !=NULL)
        pq->rear=NULL;
    pq->size--;
}
Queue_Status Queue_Empty(Queue *pq)
{
    if(pq->front ==NULL)
        return Queue_empty;
    else
        return Queue_non_empty;
}

void  Queue_Traverse(Queue *pq, void(*pf)(Queue_Type e))
{
    QueueNode *pn=pq->front;
    while( pn>0){
        (*pf)(pn->entry);
        pn=pn->next;
    }

}
