void change(int n, int m, NODE * head)
{
	typedef struct b
	{
		int cs;
		int ys;
		struct b *next;
	}NEW;

	int num = 2, tot = 0;

	NEW * head2, * p2;
	head2 = (NEW*)malloc(sizeof(NEW));
	head2->next = NULL;
	head2->cs = 0;
	head2->ys = 0;

	p2 = (NEW*)malloc(sizeof(NEW));
	p2->ys = n * 10 / m;
	p2->cs = n * 10;
	p2->next = NULL;
	head2->next = p2;
	int cmp = n * 10;

	while (1)
	{
		NEW *pre = head2, *cur = p2;
		for (; cur != NULL && pre->cs != cmp; pre = cur, cur = cur->next);

		if (cur == NULL)
		{ 
			tot++;
			cur = (NEW*)malloc(sizeof(NEW));
			cur->cs = (pre->cs - pre->ys * m) * 10;
			cur->ys = cur->cs / m;
			if (cur->cs % m == 0)
			{
	head->data = -1;
	return;
			}
			pre->next = cur;
			cur->next = NULL;
			cmp = cur->cs;
		}
		else if (cur != NULL)
		{
			while (cur->next != NULL && cur->next->cs != cmp)
			{
	cur = cur->next;
	num++;
			}

			if (cur->next == NULL)
			{
	num--;
	pre->next = pre;
			}
			else
			{
	cur->next = pre;
			}
	
			break;
		}
	}
	int nring = tot - num + 1;

	NEW *p3 = head2->next;
	NODE * p1, *p22 = head, *psring = head;
	head->data = nring;
	for (int i = 1; i <= tot; i++)
	{
		p1 = (NODE*)malloc(sizeof(NODE));
		p1->data = p3->ys;
		p22->next = p1;
		p22 = p1;
		p1->next = NULL;
		p3 = p3->next;
	}

	for (int i = 0; i < nring; i++)
		psring = psring->next;

	p1->next = psring;
}
NODE * find(NODE *head, int * n)
{
	NODE * pring = head;
	int sring = head->data;
	int num = 0;
	if (sring == -1)
	{ 
		*n = 0;
		return NULL;
	}
	for (int i = 0; i < sring; i++)
		pring = pring->next;
	
	NODE * ed = pring;
	do
	{
		num++;
		ed = ed->next;
	} while (ed != pring);

	*n = num;
	
	return pring;

}