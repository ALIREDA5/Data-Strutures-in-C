#include <stdio.h>
#include <stdlib.h>
#include "fifo.h"
#include "string.h"
int main()
{
    Queue runway;
    Queue_Create(&runway);
    printf("========== Airport System Launched ========== \n");
    printf("Option (1) : add landing plane \n");
    printf("Option (2) : add leaving plane \n");
    int x;
    char land;
    char leave;
    while(1)
    {
        printf("Your Option : ");
        scanf("%d", &x);
        if(x==1)
        {
            printf("Enter plane name :");
            scanf(" %c",&land);
            if(Queue_Full(&runway)==Queue_full)
            {
                printf("No empty place \n");
            }
            else
            {
            Queue_Append(&runway, land);
            printf("plane %c is landing\n", land);
            }
        }
        else if(x==2)
        {
            if(Queue_Empty(&runway)==Queue_empty)
            {
                printf("runway is empty\n");
            }
            else
            {
            Queue_Serve(&runway, &leave);
            printf("plane %c is leaving\n", leave);
            }
        }
    }


    return 0;
}
