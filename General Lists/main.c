#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void display(List_Type e)
{
    printf("e = %d \n", e);
}

int main()
{
    list l;
    List_Create(&l);
    for(int i=1 ; i<5 ; i++)
    {
        List_Add_Element(&l, i);
    }
    List_Traverse(&l, &display);
    List_Insert_Element(2,&l,8);
    List_Traverse(&l, &display);


    return 0;
}
