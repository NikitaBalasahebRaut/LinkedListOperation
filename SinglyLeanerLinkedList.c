//program to insert element(node) at first possition of linked list

#include<stdio.h>
#include<stdlib.h>

struct Node
{
  int data;
  struct Node *next;
};

typedef struct Node NODE;
typedef struct Node* PNODE;
typedef struct Node** PPNODE;

void Display(PNODE Head)
{	
	while(Head != NULL)
	{
		printf("%d\t", Head->data);
		Head = Head->next;
	}
}

int Count(PNODE Head)
{
	int icnt = 0;
	
	 while(Head != NULL)
	 {
		 icnt++;
		 Head = Head->next;
	 }
	
	return icnt;
}
	
	
void InsertFirst(PPNODE Head,int no)
{
  PNODE newn = NULL;
  newn = (PNODE) malloc(sizeof(NODE));
  newn->data = no;
  newn->next = NULL;
  
  if(*Head == NULL)
  {
    *Head = newn;
  }
  else
  {
    newn->next = *Head;
	*Head = newn;
  }
}

void InsertLast(PPNODE Head,int no)
{
	PNODE newn = NULL;
	PNODE temp = *Head;
	
	newn = (PNODE)malloc(sizeof(NODE));
	newn->data = no;
	newn->next = NULL;
	
	if(*Head == NULL)
	{
		*Head = newn;
	}
	else
	{
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = newn;
	}
}

void InsertAtPosition(PPNODE Head,int no,int iPose)
{
	PNODE newn = NULL;
	PNODE temp = *Head;
	int iSize = 0;
	iSize = Count(*Head);
	int i = 0;
	
	if((iPose < 1) ||(iPose >iSize+1))
	{
		return;
	}
	else if(iPose == 1)
	{
		InsertFirst(Head,no);
	}
	else if(iPose > iSize+1)
	{
		InsertLast(Head,no);
	}
	else
	{
	newn = (PNODE)malloc(sizeof(NODE));
	newn->data = no;
	newn->next = NULL;
	
	for(i = 1;i < iPose-1; i++)
	{
		temp = temp->next;
	}
    newn->next = temp->next;
    temp->next = newn;	
	}
}

void DeleteFirst(PPNODE Head)
{
  PNODE temp = *Head;
  if(*Head != NULL)
  {
	  *Head = (*Head)->next;
  }
  free(temp);  	   
}

void DeleteLast(PPNODE Head)
{
	PNODE temp = *Head;
	
	if(*Head == NULL)
	{
		return;
	}
	else if((*Head)->next == NULL)
	{
		free(*Head);
		*Head = NULL;
	}
	else
	{
		while(temp->next->next != NULL)
		{
			temp = temp->next;
		}
		free(temp->next);
		temp->next = NULL;
	}
}

void DeleteAtPossition(PPNODE Head,int iPose)
{
	 PNODE temp = *Head;
	 int size = 0;
	size = Count(*Head);
	
	if((iPose < 1)||(iPose >size))
	{
		printf("please Enter The valid possition\n");
		return;
	}
	else if(*Head == NULL)
	{
		printf("Linked List is empty\n");
		return;
	}
	else if((*Head)->next == NULL)
	{
		DeleteFirst(Head);
	}
	else if(temp->next->next == NULL)
	{
		DeleteLast(Head);
	}
	else
	{
		int i = 0;
		PNODE temp2 = NULL;
		
	  for(i = 1;i<iPose-1;i++)
	  {
         temp = temp->next;
	  }	
       temp2 = temp->next;
       temp->next = temp2->next;
       free(temp2);   
	}
}

int main()
{
  int iRet = 0;
  PNODE First = NULL;
  int no = 0;
  int iPose = 0;
  
  printf("\nEnter The Value to insert at first \n");
  scanf("%d",&no);
  InsertFirst(&First,no);
  
  printf("\nEnter The Value to insert at first \n");
  scanf("%d",&no);
  InsertFirst(&First,no);
  
  printf("\nEnter The Value to insert at Last \n");
  scanf("%d",&no);
  InsertLast(&First,no);
  
  printf("\nEnter The Value to insert at Last\n");
  scanf("%d",&no);
  InsertLast(&First,no);
  
  printf("\nEnter The Value \n");
  scanf("%d",&no);
  printf("\nEnter The possition\n");
  scanf("%d",& iPose);
  InsertAtPosition(&First,no,iPose);
  
  printf("\nElements of linked list are\n");
  Display(First);
  
  printf("\nIt will be delete first element of linked list\n");
  DeleteFirst(&First);
  
  printf("\nElements of linked list are\n");
  Display(First);
  
  printf("\nIt will be delete Last element of linked list\n");
  DeleteLast(&First);
  
  printf("\nElements of linked list are\n");
  Display(First);
  
  printf("\nEnter The possition to delete the element\n");
  scanf("%d",&iPose);
  DeleteAtPossition(&First,iPose);
  
  printf("\nElements of linked list are\n");
  Display(First);
  
  iRet = Count(First);
  printf("\nNo of elements are:-%d",iRet);

return 0;
}

/*output
Enter The Value to insert at first
12

Enter The Value to insert at first
11

Enter The Value to insert at Last
13

Enter The Value to insert at Last
14

Enter The Value
15

Enter The possition
5
Elements of linked list are
11      12      13      14      15
It will be delete first element of linked list

Elements of linked list are
12      13      14      15
It will be delete Last element of linked list

Elements of linked list are
12      13      14
Enter The possition to delete the element
2

Elements of linked list are
12      14
No of elements are:-2
*/