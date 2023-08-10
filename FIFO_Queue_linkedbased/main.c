
#include "fifo.h"
#include "stdio.h"
#include "stdlib.h"

void Display(Queue_Type e)
{
    printf("%d\n", e);
}
int main()
{
    Queue Fifo;
    Queue_Create(&Fifo);
    int x = 45, z=5;
    int y=0;
    Queue_Append(&Fifo, x);
    Queue_Append(&Fifo, z);
    Queue_Serve(&Fifo, &y);
    Queue_Append(&Fifo, x);
    Queue_Append(&Fifo, z);
    printf("%d\n", y);
    Queue_Traverse(&Fifo, &Display);
    return 0;
}
