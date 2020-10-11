#include "../resources/TreeNode.hpp"
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class binaryTreeUtility {
public:
	enum class DFSOption { Preorder, Inorder, Postorder };
	TreeNode* buildBinaryTreeByLevelOrder(string& seq);
	string outputBinaryTreeWithLevelOrderTraverse(TreeNode* node, bool display);
	void displayBinaryTreeDFSTraverse(TreeNode*, binaryTreeUtility::DFSOption);
private:
	void trimLeftTrailingSpaces(string&);
	void trimRightTrailingSpaces(string&);
	int countNotNullTreeNode(TreeNode*);
	void binaryTreeWithPreorderTraverse(TreeNode*, vector<int>&);
	void binaryTreeWithInorderTraverse(TreeNode*, vector<int>&);
	void binaryTreeWithPostorderTraverse(TreeNode*, vector<int>&);
};

