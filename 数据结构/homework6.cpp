/*4.16 Show the result of inserting 2, 1, 4, 5, 9, 3, 6, 7 into an initially empty AVL tree.*/

/*4.22 Write the functions to perform the double rotation without the inefficiency of doing two single rotations.*/
Position doubleRotateLeft(Position k3) {
	Position k1 = k3->left;
	Position k2 = k1->right;//k3为根
	k1->right = k2->left;
	k3->left = k2->right;
	k2->left = k1;
	k2->right = k3;//旋转为k2为根
	k1->height = Max(height(k1->left), height(k1->right)) + 1;
	k3->height = Max(height(k3->left), height(k3->right)) + 1;
	k2->height = Max(height(k2->left), height(k2->right)) + 1;//求出个节点深度
	return k2;
}

Position doubleRotateRight(Position k1) {
	Position k3 = k1->right;
	Position k2 = k3->left;
	k1->right = k2->left;
	k3->left = k2->right;
	k2->left = k1;
	k2->right = k3;//旋转为k2为根
	k1->height = Max(height(k1->left), height(k1->right)) + 1;
	k3->height = Max(height(k3->left), height(k3->right)) + 1;
	k2->height = Max(height(k2->left), height(k2->right)) + 1;//求出个节点深度
	return k2;
}

/*4.24 Show the result of deleting the element with key 6 in the resulting splay tree for the exercise 4.23.*/

/*4.36 a. Show the result of inserting the following keys into an initially empty 2-3 tree: 3, 1, 4, 5, 9, 2, 6, 8, 7, 0.*/

/*b. Show the result of deleting 0 and then 9 from the 2-3 tree created in part (a).*/