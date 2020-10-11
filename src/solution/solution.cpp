#include "solution.hpp"


vector<vector<int>> solution::zigzagLevelOrder(TreeNode* root)
{
	queue<TreeNode*> seq;
	if (!root)
		return {};
	seq.push(root);
	vector<vector<int>> res;
	int index = 0;
	while (!seq.empty()){
		vector<int> out;
		int size = seq.size();
		for (int i = 0; i < size; ++i) {
			TreeNode* currentNode = seq.front();
			seq.pop();
			out.push_back(currentNode->val);
			if (currentNode->left)
				seq.push(currentNode->left);
			if (currentNode->right)
				seq.push(currentNode->right);
		}
		++index;
		if (index % 2 == 0)	
			reverse(out.begin(), out.end());
		res.push_back(out);
	}
	return res;
}
