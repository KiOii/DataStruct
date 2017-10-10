#include <stdlib.h>
#ifndef LINKLIST_H
#define LINKLIST_H
/*
    Date     :2017.10.10
    Introuce :One-way linked list of a head-node.
    Note     :some basic operation.
*/
typedef enum
{
	OK    =  0,
	ERROR = -1
}Status;
typedef int    ElemType;
typedef struct LinkList_ *PLinkList;
typedef struct LinkList_
{
	ElemType          mElem;
	PLinkList         mNext;
}LinkList;
/*
To-Do :Creating a LinkList-struct-body and becoming head-node.
Param :In order to give the init-head-note-address to external PLinkList variable.
Time  :O(1)
Return:Status (OK：The function malloc(...) be called successfully.)
*/
Status InitList(PLinkList *pL);

/*
To-Do :Clearing all Elemments ,then Destroying the head-node.
Param :In order to give the NULL to external PLinkList variable.
Time  :O(1)
Return:Status (OK：First call it and successfully.)
*/
Status DestroyList(PLinkList *pL);

/*
To-Do :Clearing all Elemments
Param :In order to use external PLinkList variable.
Time  :O(n)
Return:Status (OK：L is no-NULL.)
*/
Status ClearList(PLinkList L);

/*
To-Do :Is a empty List?
Param :In order to use external PLinkList variable.
Time  :O(1)
Return:int (1: empty  0: no-empty)
*/
int    IsEmptyList(PLinkList L);

/*
To-Do :Geting index-th Elem.
Param :In order to use external PLinkList variable and index range:[1,n].
Time  :O(n)
Return:const ElemType*  (save the elem-address what we want,if not found,return NULL)
*/
const  ElemType* GetElem(PLinkList L, int index);

/*
To-Do :Geting number of elements.
Param :In order to use external PLinkList variable.
Time  :O(n)
Return:int  (return the number of elements what we want.)
*/
int    GetLength(PLinkList L);

/*
To-Do :Geting position（range:[1,n]） of elements.
Param :In order to use external PLinkList variable and external Elem and use the compare-function( compare return 1 mean found).
Time  :O(n)
Return:int  (return the position of elements what we want,if not found return 0)
*/
int    LocateElem(PLinkList L, ElemType *cmpElem, int(*compare)(const ElemType*, const ElemType*));

/*
To-Do :Inserting new element.
Param :In order to use external PLinkList variable and next-index(range:[1,n]) and new-element.
       such thar: case(L:a b c nextIndex:2 new-element:d)===>result(L: a d b c).
Time  :O(n) (use time to find the position.)
Return:Status  (OK: L && nextIndex-in-the-valid-range && malloc(...) be called successfully.)
*/
Status ListInsert(PLinkList L, int nextIndex, ElemType *newElem);

/*
To-Do :Deleting the index-th(range:[1,n]) being-elem. 
Param :In order to use external PLinkList variable and index(range:[1,n]) and return old-element.
       such thar: case(L:a b c index:2 new-element:d)===>result(L: a c).
Time  :O(n) (use time to find the position.)
Return:Status  (OK: L && index-in-the-valid-range)
*/
Status ListDelete(PLinkList L, int index, ElemType *oldElem);

#endif 
