#include<stdio.h>
#include<stdlib.h>
typedef struct node 
{
	int data;
	struct node *next;
}NODE;
int main()
{
	NODE *head;
	head = (NODE *)malloc(sizeof(NODE));
	head->next=NULL;
	
	NODE *p,*q;
	p=head;
	q=(NODE *)malloc(sizeof(NODE));
	
	q->next=p->next;
	p->next=q;
	p=p->next;
	
	return 0;
}

