//program to perform singly circular linked list

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

void InsertFirst(PPNODE Head,PPNODE Tail,int no)
{
  PNODE newn = NULL;
  newn = (PNODE)malloc(sizeof(NODE));
  newn->data = no;
  newn->next = NULL;
  
  if((*Head == NULL) && (*Tail == NULL))
  {
	  *Head = newn;
	  *Tail = newn;
  }
  else
  {
	  newn->next = *Head;
	  *Head = newn;
  }
  (*Tail)->next = *Head;
}

void InsertLast(PPNODE Head,PPNODE Tail,int no)
{
  PNODE newn = NULL;
  newn = (PNODE)malloc(sizeof(NODE));
  newn->data = no;
  newn->next = NULL;
  
  if((*Head == NULL) && (*Tail == NULL))
  {
	  *Head = newn;
	  *Tail = newn;
  }
  else
  {
	  (*Tail)->next = newn;
	  *Tail = newn;
  }
   (*Tail)->next = *Head;
  
}

void Display(PNODE Head,PNODE Tail)
{
if((Head == NULL) && (Tail == NULL))
{
	return;
}
else
{
  do
  {
    printf("%d\t", Head->data);
    Head = Head->next;
  }while(Head != Tail->next);
  printf("\n");                     //else printf new line after Display function in main method
}
    
}

int Count(PNODE Head,PNODE Tail)
{
	int iCnt = 0;
	
	if((Head == NULL) && (Tail == NULL))
    {
	   return 0;
    }
	else
	{
	do
	{
		iCnt++;
		Head = Head->next;
	}while(Head != Tail->next);
	  printf("\n"); 
	}
	
	return iCnt;
}

void DeleteFirst(PPNODE Head,PPNODE Tail)
{
   if((*Head == NULL) && (*Tail == NULL))
   {
      return;
   }
   else if(*Head == *Tail)
   {
       free(*Head);
	   *Head = NULL;
	   *Tail = NULL;
	   return;
   }	   
   else
   {
	   *Head = (*Head)->next;
	   free((*Tail)->next);
	    (*Tail)->next = *Head;
   }
}

void DeleteLast(PPNODE Head,PPNODE Tail)
{
	PNODE temp = *Head;
   if((*Head == NULL) && (*Tail == NULL))
   {
      return;
   }
   else if(*Head == *Tail)
   {
       free(*Head);
	   *Head = NULL;
	   *Tail = NULL;
	   return;
   }	   
   else
   {
	   while(temp->next != *Tail)
	   {
		   temp = temp->next;
	   }
	   free(*Tail);
	   *Tail = temp;
	   (*Tail)->next = *Head;
   }
}
void InsertAtPossition(PPNODE Head,PPNODE Tail,int no,int iPos)
{
	int size = 0;
	size = Count(*Head,*Tail);
	
	if((iPos < 1)||(iPos > size+1))
	{
		printf("Please Enter The Valid possition \n");
		return;
	}
	else if(iPos == 1)
	{
		InsertFirst(Head,Tail,no);
	}
	else if(iPos == size+1)
	{
		InsertLast(Head,Tail,no);
	}
	else
	{
		  PNODE newn = NULL;
		  PNODE temp = *Head;
		  
          newn = (PNODE)malloc(sizeof(NODE));
          newn->data = no;
		  newn->next = NULL;
		  int i = 0;
		  
		  for(i = 1; i < iPos-1; i++)
		  {
			 temp = temp->next;
		  }
         newn->next = temp->next;
         temp->next = newn;		 
		   
	}
}

void DeleteAtPossition(PPNODE Head,PPNODE Tail,int iPos)
{
	int size = 0;
	size = Count(*Head,*Tail);
	
	if((iPos < 1)||(iPos > size))
	{
		printf("Please Enter The Valid possition \n");
		return;
	}
	else if(iPos == 1)
	{
		DeleteFirst(Head,Tail);
	}
	else if(iPos == size)
	{
		DeleteLast(Head,Tail);
	}
	else
	{
		 PNODE temp = *Head;
		 PNODE temp2 = temp->next;
		 int i = 0;
		 
		 for(i = 1; i < iPos-1; i++)
		  {
			 temp = temp->next;
		  }
		  temp->next = temp2->next;
		  free( temp2);
	}
	
}
int main()
{
 PNODE First = NULL;
 PNODE Last = NULL;
 int no = 0;
 int iRet = 0;
 int iPos = 0;
 
 printf("Enter The Element(InsertFirst)\n");
 scanf("%d",&no);
 InsertFirst(&First,&Last,no);
 printf("Enter The Element(InsertFirst)\n");
 scanf("%d",&no);
 InsertFirst(&First,&Last,no);
 
 printf("Linked List \n");
 Display(First,Last);
 
 printf("Enter The Element(InsertLast)\n");
 scanf("%d",&no);
 InsertLast(&First,&Last,no);
 printf("Enter The Element(InsertLast)\n");
 scanf("%d",&no);
 InsertLast(&First,&Last,no);

 printf("Linked List \n");
 Display(First,Last);
 
 iRet = Count(First,Last);
 printf("No of elements in linked list are :%d", iRet);
 
 DeleteFirst(&First,&Last);
 printf("\nLinked List After Delete First Element \n");
 Display(First,Last);
 
 DeleteLast(&First,&Last);
 printf("\nLinked List After Delete Last Element \n");
 Display(First,Last);
 
 printf("Enter The Element\n");
 scanf("%d",&no);
 printf("Enter The possition to Insert Element\n");
 scanf("%d",&iPos);
 InsertAtPossition(&First,&Last,no,iPos);
 printf("Linked List \n");
 Display(First,Last);
 
 printf("Enter the possition to delete The Element\n");
 scanf("%d",&iPos);
 DeleteAtPossition(&First,&Last,iPos);
 printf("Linked List After delete Element\n");
 Display(First,Last);
return 0;
}

/*
Enter The Element(InsertFirst)
100
Enter The Element(InsertFirst)
110
Linked List
110     100
Enter The Element(InsertLast)
10
Enter The Element(InsertLast)
130
Linked List
110     100     10      130

No of elements in linked list are :4
Linked List After Delete First Element
100     10      130

Linked List After Delete Last Element
100     10
Enter The Element
12
Enter The possition to Insert Element
3

Linked List
100     10      12
Enter the possition to delete The Element
1

Linked List After delete Element
10      12

*/
