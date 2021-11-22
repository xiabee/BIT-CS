#include <stdio.h> 
#include <string.h> 
typedef struct
{ 
	char name[14]; 
	int value; 
}st; 
int main() 
{ 
	int n,i = 0,m,j,k = 0,money = 0,children = 0; 
	st people[10]; 
	char name[14]; 
	scanf("%d\n",&n); 
	m = n; 
	while (n--) 
	{ 
		scanf("%s",people[i].name); 
		people[i++].value = 0; 
	} 
	while (i--) 
	{ 
		scanf("%s\n%d %d",name,&money,&children); 
		if (children) 
		{ 
			for (j = 0; ; j++) 
			if (strcmp(people[j].name,name) == 0) 
			break; 
			people[j].value -= (money / children) * children ; 
			j = children; 
			while (j--) 
			{ 
				scanf("%s",name); 
				for (k = 0; ; k++) 
				if (strcmp(people[k].name,name) == 0) 
				break; 
				people[k].value += money / children; 
			} 
		} 
	} 
	for (i = 0; i < m; i++ ) 
	printf("%s %d\n",people[i].name,people[i].value); 
	return 0; 
}
