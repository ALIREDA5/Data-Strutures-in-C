#include <stdio.h>
#include <stdlib.h>
#include "fifo.h"

// initialize Queue fun
Queue_Status  Queue_Create(Queue *pq)
{
    pq->head=pq->entry;
    pq->base=pq->entry;
    pq->tail=pq->entry;
    pq->size=0;
    return Queue_no_error;
}

// check if Queue is full
Queue_Status  Queue_Full(Queue *pq)
{
    if(pq->size == MaxQueue)
        return Queue_full;
    else
        return Queue_not_full;
}
// enqueue an element
Queue_Status  Queue_Append(Queue* pq, Queue_Type e)
{
    if(pq->base == pq->entry)
    {
      *(pq->head)=e;
      pq->head ++;
      if(pq->size < MaxQueue)
            {
            pq->size ++;
            }
            else
            {
            pq->head=pq->base;
            }
            return Queue_no_error;
    }
    else
    {
        printf("Failed to enqueue\n");
        return  Queue_fail;
    }
}

// get element from queue
Queue_Status  Queue_Serve(Queue *pq, Queue_Type *e)
{
    if( pq->size != 0)
    {
      *e=*(pq->tail);
      pq->tail++;
      pq->size--;
      if(pq->tail == pq->base + MaxQueue*sizeof(Queue_Type))
        pq->tail=pq->base;
      return Queue_no_error;
    }
    else
    {
        printf("Failed to dequeue\n");
        return  Queue_fail;
    }
}

// check if queue is empty
Queue_Status  Queue_Empty(Queue *pq)
{
    if(pq->size == 0)
        return Queue_empty;
    else
        return Queue_non_empty;
}

// delete all queue elements
Queue_Status  Queue_clear(Queue *pq)
{
    pq->head=pq->base;
    pq->tail=pq->base;
    pq->size=0;
    return Queue_no_error;
}

// allow the user to go through all elements and apply any fun on the queue
void  Queue_Traverse(Queue *pq, void(*pf)(Queue_Type e))
{
    if(pq->size==0) printf("Queue is empty\n");
    Queue_Type *pos;
    for(pos=pq->tail; pos!=pq->head; pos++)
    {
        (*pf)(*pos);
        if(pos==pq->base+MaxQueue*sizeof(Queue_Type))
            pos=pq->base;
    }
}

