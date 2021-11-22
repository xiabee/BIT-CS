/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */  
 
#include "stdio.h"  
#include "stdlib.h"  
  
struct node  
{   int data;  
    struct node * next;  
} ;  
  
typedef struct node NODE;  
typedef struct node * PNODE;  
  
void outlist( PNODE );  
void ins_list( PNODE h, int num );  
  
int main ( )  
{       
	int num=1;  
    PNODE head;  
  
    head = (PNODE)malloc( sizeof(NODE) );  
    head->next = NULL;  
    head->data = -1;  
  
    while ( num!=0 )  
    {   scanf("%d", &num);  
        if ( num!=0 )  
            ins_list( head, num);  
    }  
  
    outlist( head );  
    return 0;  
}  
  
void outlist( PNODE head )  
{   PNODE p;  
    p = head->next;  
    while ( p != NULL )  
    {   printf("%d\n", p->data);  
        p = p->next;  
    }  
}  
//º¯Êý£» 
void ins_list(PNODE head, int n)
{
	PNODE p1 = head, p2;
	while (p1->next!= NULL)
		p1 = p1->next;
	p2 = p1;
	p1 = p1->next;
	
	p1 = (PNODE)malloc(sizeof(NODE));
	p1->data = n;
	p1->next = NULL;
	
	p2->next = p1;
}
