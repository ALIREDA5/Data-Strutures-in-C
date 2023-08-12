#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#define Maxlist  20
typedef  int List_Type;

// List data types
typedef struct que {
    int size;
    List_Type entry[Maxlist];
}list;

// List status
typedef enum{
List_no_error,
List_full,
List_not_full,
List_empty,
List_non_empty,
List_fail,
List_un_init
}List_Status;

//List APIs
void  List_Create(list *pq);
List_Status  List_Insert_Element(int pos, list *pq, List_Type e);
List_Status  List_Add_Element(list *pq, List_Type e);
List_Status  List_Delete_Element(int pos, list *pq, List_Type *e);
List_Status  List_Empty(list *pq);
List_Status  List_clear(list *pq);
List_Status  List_Full(list *pq);
List_Status  List_Traverse(list *pq, void(*pf)(List_Type e));



#endif // LIST_H_INCLUDED
