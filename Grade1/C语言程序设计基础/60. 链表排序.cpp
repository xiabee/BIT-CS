/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */

#include "stdio.h"
#include "stdlib.h"

struct node
{ int data;
	struct node * next;
} ;

typedef struct node NODE;
typedef struct node * PNODE;
void outlist( PNODE );

int main ( )
{   int num=1;
	PNODE head;

	head = (PNODE)malloc( sizeof(NODE) );
	head->next = NULL;
	head->data = -1;

	while ( num!=0 )
	{   scanf("%d", &num);
		if ( num!=0 )
			sortlist( head, num);
	}
	outlist( head );
	return 0;
}

void outlist( PNODE head )
{ PNODE p;
	p = head->next;
	while ( p != NULL )
	{ printf("%d\n", p->data);
		p = p->next;
	}
}

/* This is an example for list. Please programme your code like it.
sortlist( PNODE h, int num )
{ PNODE p;
	p = (PNODE)malloc( sizeof(NODE) );
	p->data = num;
	p->next = h->next;
	h->next = p;
}
*/

/* PRESET CODE END - NEVER TOUCH CODE ABOVE */

void sortlist(PNODE head, int n)
{
	PNODE pre = head, cur = head->next; 
	for (; cur != NULL && cur->data < n; pre = cur, cur = cur->next);
	if (cur == NULL)
	{
		cur = (PNODE)malloc(sizeof(NODE));
		cur->data = n;
		cur->next = NULL;

		pre->next = cur;
	}
	else
	{
		if (n == cur->data)
			return;
		else if (n < cur->data)
		{
			PNODE add;
			add = (PNODE)malloc(sizeof(NODE));
			add->data = n;
			
			add->next = cur;
			pre->next = add;
		
		}
	}
}