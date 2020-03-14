/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */  
 
#include <stdio.h>  
#include <stdlib.h>  
typedef struct numLink  
{  
    int no;  
    struct numLink *next;  
}NODE;  
  
NODE *monenode( NODE *head, int m );  
  
void SetLink( NODE *h, int n )  
{  
    NODE *p=NULL, *q=NULL;  
    int i;  
    for( i=0; i<n; i++)  
    {  
        p = (NODE *)malloc(sizeof(NODE));  
        p->no = i+1;  
        p->next = NULL;  
        if( h->next == NULL )  
        {  
            h->next = p;  
            q = p;  
        }  
        else  
        {  
            q->next = p;  
            q = q->next;  
        }  
    }  
    return;  
}  
int main( )  
{  
    int n,m;  
    NODE *head=NULL, *q=NULL;  
    scanf("%d%d",&n,&m);  
    head = (NODE *)malloc(sizeof(NODE));  
    head->no = -1;  
    head->next = NULL;  
  
    SetLink( head, n );  
  
    q = monenode( head, m );  
  
    do  
    {  
        printf("%d ",q->next->no);  
        q = q->next;  
    }while( q->next != NULL );   
    printf("\n");  
    return 0;  
}  
  
/* PRESET CODE END - NEVER TOUCH CODE ABOVE */  
NODE *monenode( NODE *head, int m )
{
	NODE * p1,*p2,*p3;
	int i=0;
	p1 =p2=p3=head;
	while(p1->next!=NULL && i<m)
	{
		p1=p1->next;
		i++;
	}


	if(p1->next != NULL)
	{

	//while结束后p1指向元素m  
	p2 = p1->next;
	p1->next=NULL;
	
	//把后面的元素放在前面
	p1 = p2;
		while(p1 != NULL)
		{
			p2 = p1->next;  //暂存
			p1->next = p3->next;
			p3->next = p1;
			p3=p3->next;
			p1 = p2;
		}	
	}

	return  head;
}

