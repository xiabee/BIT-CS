/*6.2 a. Show the result of inserting 10, 12, 1, 14, 6, 5, 8, 15, 3, 9, 7, 4, 11, 13, and 2, one at a time, into an initially empty binary heap.*/
1, 3, 2, 6, 7, 5, 4, 15, 14, 12, 9, 10, 11, 13, 8

/*b. Show the result of using the linear-time algorithm to build a binary heap using the same input.*/
1 3 2 12 6 4 8 15 14 9 7 5 11 13 10

/*6.4 Write the routines to do a percolate up and a percolate down in a binary heap.*/

PtrHeap InsertHeap(PtrHeap h, EleType x) {
	int i = 0;
	if (h->cur >= h->size - 1) {
		ERR_MSG("Heap is full!\n");
		return NULL;
	}

	for (i = ++h->cur; h->ele[i >> 1] > x; i >>= 1) {
		h->ele[i] = h->ele[i >> 1];
	}
	h->ele[i] = x;
	return h;
}

EleType DelMinHeap(PtrHeap h)
{
	int i = 0;
	int child = 0;
	EleType min_ele, last_ele;
	if (h->cur == 0) {
		ERR_MSG("Heap is empty!\n");
		return h->ele[0];
	}    /* empty heap */
	min_ele = h->ele[1];
	last_ele = h->ele[h->cur];
	h->cur--;
	i = 1;
	child = 2 * i;
	while (child <= h->cur) {
		if ((child < h->cur) && (h->ele[child + 1] < h->ele[child]))
			child++;
		/* compare to last_element */
		if (h->ele[child] < last_ele)
			h->ele[i] = h->ele[child];
		else
			break;
		i = child;
		child = 2 * i;
	}
	h->ele[i] = last_ele;
	return min_ele;
}