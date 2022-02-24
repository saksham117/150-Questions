#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
#include<queue>
#include<set>
#include<stack>


using namespace std;
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Pair
{   
    public:
	int height;
	int diameter;
};

class Solution {
public:
    
    Pair helper(TreeNode* root)
	{
		if(root == NULL)
		{
			Pair p;
			p.height = 0;
			p.diameter = 0;

			return p;
		}


		Pair left = helper(root->left);
		Pair right = helper(root->right);

		Pair ans;
		ans.height = 1 + max(left.height, right.height);
		ans.diameter = max(left.height + right.height, max(left.diameter, right.diameter));

		return ans;
	}
    
    
    int diameterOfBinaryTree(TreeNode* root) {
        
        Pair ans = helper(root);
  		return ans.diameter;

    }
};