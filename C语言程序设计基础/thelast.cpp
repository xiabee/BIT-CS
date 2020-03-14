NODE *inststr(NODE *heada,NODE *headb,int m)
	//输入：两个链表头指针，heada插入位置；返回：heada 
{
	int i;
	NODE *p=heada, *q=NULL;
	if(m>0)
	{
		for(i=1; i<m && p->next != NULL; i++) //遍历heada到第m-1个节点 
			p=p->next;
		q=p->next; // 为了方便新链表指针指回来，保证链表结构完整，储存p的*next
		p->next=headb; // 第m-1个节点的*next指向headb，实现衔接 
		while(p->next != NULL) //遍历到headb尾部 
			p=p->next;
		if(q != NULL) //这里是判断原链表第m-1个节点是否还为空，其实不判断也可以 
			p->next=q; //如果不为空，那么新链表尾部就应该指回原来m-1的*next，保证链表结构完整 
		else  //如果m小于等于0，那么根据题意，直接把新链表插入头部 
		{
			p=headb;
			while(p->next != NULL) //同样，新链表尾部要指回heada 
				p=p->next;
			p->next=heada;
			heada=headb; //保证heada一定是链表头部 
		}
		return heada; //给函数一个返回值 
	}
}


