#ifndef LINKLIST2_0_H
#define LINKLIST2_0_H
/*
          Date    :2017.10.11
          Introuce:A one-way linked list with a head-pointer|tail-pointer.
          Note    :
                    1)You must define your _make(...) function and _destroy function and init them in InitList(...) function.
                    2)Please note the warning information.
*/
typedef enum
{
	OK			=  0,
	ERROR		= -1,
	FOUND		=  1
}Status;
typedef struct node_ *PNode;
typedef PNode PFirst, PLast;
typedef struct node_
{
	void       *mData;
	PNode       mpNext;
}node;
typedef unsigned int Size;
typedef struct LinkList2_0
{

	PFirst		  mpHead;
	PLast		    mpTail;

	Size        muLength;

	int(*_destroy)(void*);  // control the data-life-cycle.
	int(*_make)(void**);    // before you make node,you must _make(...) data.
}LinkList,*PLinkList;
/*****************************************************************************/
/*
To-Do :Creating a LinkList-body | Creating a head-node | LinkList-body-mpHead has head-node-address.
Param :In order to give the new LinkList-body-address to external PLinkList and some function-address.
Time  :O(1).
Return:Status (OK: usually malloc(...) be called successfully)
*/
Status InitList(PLinkList *pL,int(*destroy)(void*),int(*_make)(void**));

/*
To-Do  :Destroying the LinkList-body.
Param  :In order to give the NULL to external PLinkList.
Time   :O(1)
Return :Status (OK: LinkList-body from exit to NULL  ERROR: LinkList-body is NULL before called or muLength > 0)
Warning:You must call ClearList(...) before DestroyList,or else you will get a ERROR.
*/
Status DestroyList(PLinkList *pL);

/*
To-Do :Clearing all nodes
Param :In order to use LinkList-body.
Time  :O(n) 
Return:Status (OK: L && has-nodes)
*/
Status ClearList(PLinkList L);

/*
To-Do :Insert new node after head.
Param :LinkList-address | new-node-address.
Time  :O(1)
Return:Status (OK: L && newNode)
*/

Status InsertFirst(PLinkList L, PNode newNode);

/*
To-Do  :Delete first node and return data.
Param  :LinkList-address | data-container
Time   :O(1) 
Return :Status (OK: L && muLength > 0)
Warning:You must call the _destroy(...) function to control oldData after call DeleteFirst.
*/
Status DeleteFirst(PLinkList L, void **oldData);

/*
To-Do :Appen last
Param :LinkList-address | another linked-note-address.
Time  :O(1)
Return:Status (OK: L && another-head)
*/
Status Append(PLinkList L, PFirst linkNode);

/*
To-Do  :delete last
Param  :LinkList-address | data-container
Time   :O(n) (time be used to update mpTail)
Return :Status (OK: L)
Warning:You must call the _destroy(...) function to control oldData after call DeleteLast.
*/
Status DeleteLast(PLinkList L, void **oldData);

/*
To-Do :Insert new-node before exit-node.
Param :LinkList-address | the next-node-address | new-node-address
Time  :O(1)
Return:Status (OK: L && next-node && new-node)
*/
Status InsertBefore(PLinkList L, PNode nextNode, PNode newNode);

/*
To-Do :Insert new-node after exit-node.
Param :LinkList-address | the pre-node-address | new-node-address
Time  :O(1)
Return:Status (OK: L && pre-node && new-node)
*/
Status InsertAfter(PLinkList L, PNode preNode, PNode newNode);

/*****************************************************************************/
/*
To-Do :call _destroy(...) control curNode-data | we have called _make(...),then get the new-data.
Param :LinkList-address | curNode-address | new-data( external-data ,maked by called _make(...))
Time  :O(1)
Return:Status (OK: L && curNode)
*/
Status SetCurNodeData(PLinkList L, PNode curNode, const void *data);

/*
To-Do  :get curent node-data
Param  :curNode-address
Time   :O(1)
Return :const void*
*/
const void* GetCurNodeData(PNode curNode);

/*
To-Do :get the number of nodes.
*/
#define GetLength(L) ( (!L)?(0):(L->muLength) )

/*
To-Do :get head.
*/
#define GetHead(L) ( (!L)?(NULL):(L->mpHead) )

/*
To-Do :get tail
*/
#define GetTail(L) ( (!L)?(NULL):(L->mpTail) )

/*
To-Do :exist node?
*/
#define IsEmpty(L) ( (!L)?(1):(!GetLength(L)))

/*
To-Do :get previous node.
Param :curNode-address.
Time  :O(n)
Return:const PNode* (no found return NULL)
*/
const PNode* GetPreNode(PNode curNode);

/*
To-Do :get next node.
Param :curNode-address.
Time  :O(1)
Return:const PNode* (no found return NULL)
*/
const PNode* GetNextNode(PNode curNode);

/*
To-Do :get indext-th(range:[1,n]) node.
Param :PLinkList-address | index 
Time  :O(n)
Return:const PNode* (no found return NULL)
*/
const PNode* GetIndexNode(PLinkList L, unsigned int index);

/*
To-Do :get on condition that compare(...) function.
Param :PLinkList-address | compare-data | compare-function
Time  :O(n)
Return:const PNode* (no found return NULL)
*/
const PNode* GetLocateNode(PLinkList L, const void *cmpData, int(*compare)(const void*, const void*));

/*
To-Do :traverse all nodes.
Param :PLinkList-address 
Time  :O(n)
Return:Status (OK: L)
*/
Status ListTraverse(PLinkList L, Status(*visit)(const void*));

/*****************************************************************************/

#endif 

