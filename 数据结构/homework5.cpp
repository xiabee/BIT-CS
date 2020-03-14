/*4.6 A full node is a node with two children. 
Prove that the number of full nodes plus one is equal to the number of leaves in a binary tree.*/

证：
 设：
 N=节点数 
 F=有两个儿子的节点个数 
 H=有一个儿子的节点个数 
 L=树叶的个数 
 所以有： 
 N=H+F+L 
 其次，N个节点会占用N-1个指针（每个节点都有一个指针指向它，除过根节点）。
 而F个满节点和H个半节点，能够提供2F+H个指针，
 所以有： 2F+H=N-1 
 两式联立可以得到： F+1=L 
 结论：满节点个数加1等于树叶的个数。


/*4.8 Give the prefix, infix, and postfix expressions corresponding to the tree in Figure 4.60.*/
prefix:		-**ab+cde
infix:		(a*b)*(c+d)-e
postfix:	ab*cd+*e+

/*4.9 a. Show the result of inserting 3, 1, 4, 6, 9, 2, 5, 7 into an initially empty binary search tree.*/



/*b. Show the result of deleting the root.*/