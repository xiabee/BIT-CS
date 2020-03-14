#include<stdio.h>
#include<stdlib.h>
typedef struct Char_
{
	char ch;
	char intch;	
	struct Char_ *next;
}CHAR_;
int main(void)
{
	CHAR_ *node = NULL;
	CHAR_ *ch_ = NULL;	
	CHAR_ *hear = NULL;	
	char zimu = 'a';	
	char panduanzimu;	
	char record;	
	for (; zimu != 'e'; zimu++)	
	{	
		ch_ = (CHAR_ *)malloc(sizeof(CHAR_));		
		if (ch_ == NULL)		
		{		
			exit(0);		
		}		
		ch_->ch = zimu;		
		ch_->next = NULL;		
		if (node == NULL)	
		{		
			node = ch_;		
		}		
		else
		{		
			node->next = ch_;		
			node = node->next;		
		}		
		if (hear == NULL)		
		{		
			hear = node;		
		}	
	}	
	for(zimu -= 2; zimu != ('a' - 1); zimu--)	
	{	
		ch_ = (CHAR_ *)malloc(sizeof(CHAR_));		
		if (ch_ == NULL)		
		{		
			exit(0);		
		}		
		ch_->ch = zimu;		
		ch_->next = NULL;		
		node->next = ch_;		
		node = node->next;	
	}	
	for (node = hear, zimu = '0'; node != NULL; node = node->next, zimu++)	
	{	
		node->intch = zimu;	
	}	
	scanf("%c", &panduanzimu);	
	node = hear;	
	if (panduanzimu >= '0'&&panduanzimu <= '6')	
	{	
		while (node != NULL)		
		{		
			if (panduanzimu == node->intch)			
			{			
				printf("%c", node->ch);				
				break;			
			}			
			node = node->next;		
		}	
	}	
	else if (panduanzimu >= 'a'&&panduanzimu <= 'd')	
	{	
		while (node != NULL)		
		{		
			if (panduanzimu == node->ch)			
			{			
				record = node->intch;			
			}			
			node = node->next;		
		}		
		printf("%c", record);	
	}	
	else{		printf("N");	}	
	node = hear;	
	while (node != NULL)	
	{	
		hear = node->next;		
		free(node);		
		node = hear;	
	}	
	return 0;
}

