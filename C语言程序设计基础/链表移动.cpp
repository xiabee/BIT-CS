NODE *monenode( NODE *head, int m )
{ 
	
	NODE *now =head->next, *ed = head->next; 
	int n = 1, tot = 1;
	for (ed; ed->next != NULL; ed = ed->next, n++);
	if (n == 1) 
		return head;
	for (NODE * later = now->next; tot <= n && now->no <= m ; later = now->next, tot++)
	{ 
		NODE * tempnow = now;
		now = now->next;
		
		head->next = later;
		ed->next = tempnow;
		tempnow->next = NULL;
		ed = tempnow;
	}
	return head;
}