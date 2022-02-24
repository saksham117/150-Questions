// we need to find the maximum path sum from any node to any other node
// does not necessaily have to be a leaf node
// some nodes can hold negative values

// in  main res will be intilaized as INT_MIN

int solve(node *root, int &res)
{
	if(root == NULL)
	{
		return 0;
	}

	int l = solve(root->left, res);
	int r = solve(root->right, res);

	// now we can have 3 cases
	// either the max sum is the present toot node + sum of all its left children and right children
	// or max sum till now is just the root node, its children are both negative
	// or max till now is the current root + max of left subtree or rightsubtree

	// in temp we store those terms jinmein our current root does not give the final answer, but ehich needs to be carried forward
	int temp = max((max(l,r) + root), root);

	int ans = max(temp, l + r + root);

	res = max(ans, res);

	return temp;
	

	

}