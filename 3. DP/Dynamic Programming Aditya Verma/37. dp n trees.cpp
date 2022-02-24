// format

int solve(Node *root, int &res) // final ans will lie with res and it is important to pass it by reference
{
	if(root == NULL)
	{
		return 0;
	}

	// hypothesis
	int l = solve(root->left, res);
	int r = solve(root->right, res);

	// indicution step
	// will vary for all questions
	
}