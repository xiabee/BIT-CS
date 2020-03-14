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