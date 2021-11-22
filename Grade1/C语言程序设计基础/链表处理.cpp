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