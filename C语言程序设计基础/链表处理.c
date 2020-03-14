/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */  
 
#include <stdio.h>  
#include <stdlib.h>  
  
typedef struct sdata  
{  int num;  
   struct sdata *next;  
} SNODE;  
  
void movenode( SNODE *, int );  
  
void setlink( SNODE * head, int n )  
{     
    SNODE *p;  
  
    while ( n > 0 )  
    {   p = ( SNODE * ) malloc( sizeof( SNODE ) );  
        p->num = n;  
        p->next = head->next;  
        head->next = p;  
        n --;  
    }  
}  
  
void outlink( SNODE * head )  
{  
    while( head->next != NULL )  
    {  
        head = head->next;  
        printf( "%d,", head->num );  
    }  
    return;  
}  
  
int main( )  
{   int n, m;  
    SNODE * head = NULL;  
  
    scanf("%d%d", &n, &m );  
    head = ( SNODE * ) malloc( sizeof( SNODE ) );  
    head->num = -1;  
    head->next = NULL;  
    setlink( head, n );  
  
    movenode( head, m );   /* This is waiting for you. */  
  
    outlink( head );  
    printf("\n");  
    return 0;  
}  
  
/* PRESET CODE END - NEVER TOUCH CODE ABOVE */  
void movenode(SNODE * head, int m)
{
	SNODE *ed;
	int n = 1;
	for (ed = head->next; ed->next != NULL; ed = ed->next, n++);
	if (m == 0 || m > n || m == n && n == 1)
		return;
	SNODE * pre = NULL,  *cur = head, *p1 = head->next;
	for (; cur->num != m; pre = cur, cur = cur->next);
	pre->next = cur->next;
	head->next = cur;
	cur->next = p1;
}
