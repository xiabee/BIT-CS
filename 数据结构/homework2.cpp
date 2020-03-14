#include<stdio.h>
#include<stdlib.h>

typedef struct Node* PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;
struct Node
{
	int x;
	Position next;
};

void PrintLots(List L, List P)
{
	Position Llots, Plots;
	Llots = L->next;
	Plots = P->next;
	int index = 1;
	while (Plots != NULL) {
		while (Llots != NULL && index != Plots->x) {
			Llots = Llots->next;
			index++;
		}
		if (Llots != NULL) {
			printf("%d\n", Llots->x);
			Plots = Plots->next;
		}
		else
			return;
	}
}