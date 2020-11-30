#include "binaryTreeUtility.hpp"


TreeNode* binaryTreeUtility::buildBinaryTreeByLevelOrder(string& input){
	trimLeftTrailingSpaces(input);
	trimRightTrailingSpaces(input);
	input = input.substr(1, input.length() - 2);
	if (!input.size()) {
		return nullptr;
	}

	string item;
	stringstream ss;
	ss.str(input);

	getline(ss, item, ',');
	TreeNode* root = new TreeNode(stoi(item));
	queue<TreeNode*> nodeQueue;
	nodeQueue.push(root);

	while (true) {
		TreeNode* node = nodeQueue.front();
		nodeQueue.pop();

		if (!getline(ss, item, ',')) {
			break;
		}

		trimLeftTrailingSpaces(item);
		if (item != "null") {
			int leftNumber = stoi(item);
			node->left = new TreeNode(leftNumber);
			nodeQueue.push(node->left);
		}

		if (!getline(ss, item, ',')) {
			break;
		}

		trimLeftTrailingSpaces(item);
		if (item != "null") {
			int rightNumber = stoi(item);
			node->right = new TreeNode(rightNumber);
			nodeQueue.push(node->right);
		}
	}
	return root;
}

void binaryTreeUtility::trimLeftTrailingSpaces(string& input) {
	input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
		return !isspace(ch);
		}));
}
void binaryTreeUtility::trimRightTrailingSpaces(string& input) {
	input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
		return !isspace(ch);
		}).base(), input.end());
}


string binaryTreeUtility::outputBinaryTreeWithLevelOrderTraverse(TreeNode* node, bool display) {
	int count = 0;
	queue<TreeNode*> seq;
	seq.push(node);
	const char* token = "";
	stringstream ss;

	int N = countNotNullTreeNode(node);

	ss << "[";
	while (!seq.empty() && count < N) {
		TreeNode* currentNode = seq.front();
		seq.pop();
		if (!currentNode)
			ss << token << "null";
		else {
			ss << token << currentNode->val;
			++count;
			currentNode->left ? seq.push(currentNode->left) : seq.push(nullptr);
			currentNode->right ? seq.push(currentNode->right) : seq.push(nullptr);
		}
		token = ",";
	}
	ss << "]";
	if (display) cout << ss.str() << endl;
	return ss.str();
}


int binaryTreeUtility::countNotNullTreeNode(TreeNode* node){
	if(!node)
		return 0;
	
	queue<TreeNode*> seq;
	seq.push(node);
	int count = 0;
	while (!seq.empty()) {
		++count;
		TreeNode* currentNode = seq.front();
		if (currentNode->left)	seq.push(currentNode->left);
		if (currentNode->right)	seq.push(currentNode->right);
		seq.pop();
	}
	return count;
}
void binaryTreeUtility::displayBinaryTreeDFSTraverse(TreeNode* node, binaryTreeUtility::DFSOption option)
{
	vector<int> data;
	switch (option) 
	{
	case binaryTreeUtility::DFSOption::Preorder:
		binaryTreeWithPreorderTraverse(node, data);
		break;
	case binaryTreeUtility::DFSOption::Inorder:
		binaryTreeWithInorderTraverse(node, data);
		break;
	case binaryTreeUtility::DFSOption::Postorder:
		binaryTreeWithPostorderTraverse(node, data);
		break;
	default:
		binaryTreeWithInorderTraverse(node, data);
		break;
	}
	string token = "";
	cout << "[";
	for (auto x : data) {
		cout << token << x;
		token = ",";
	}
	cout << "]";
}

void binaryTreeUtility::binaryTreeWithPreorderTraverse(TreeNode* node, vector<int>& data) {
	if (node) {
		data.push_back(node->val);
		binaryTreeWithInorderTraverse(node->left,data);
		binaryTreeWithInorderTraverse(node->right,data);
	}
}
void binaryTreeUtility::binaryTreeWithInorderTraverse(TreeNode* node, vector<int>& data) {
	if (node) {
		binaryTreeWithInorderTraverse(node->left, data);
		data.push_back(node->val);
		binaryTreeWithInorderTraverse(node->right, data);
	}
}

void binaryTreeUtility::binaryTreeWithPostorderTraverse(TreeNode* node, vector<int>& data) {
	if (node) {
		binaryTreeWithInorderTraverse(node->left,data);
		binaryTreeWithInorderTraverse(node->right,data);
		data.push_back(node->val);

	}
}
