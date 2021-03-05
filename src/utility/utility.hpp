#include "../resources/TreeNode.hpp"
#include <string>
#include <stack>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

enum class Option { PREORDER, INORDER, POSTORDER, LEVELORDER };

template<typename T>
vector<T> buildOneDimensionalArray(string input){
    if(input.empty())
        return {};
    string str = input.substr(1, input.size()-2);
    istringstream iss(str);
    string val;

    vector<T> res;
    while(std::getline(iss, val, ',')){
      if constexpr (std::is_same_v<T, char>){
          res.push_back(val.front());
      }else if constexpr (std::is_same_v<T, int>){
          res.push_back(stoi(val));
      }else if constexpr (std::is_same_v<T, string>){
          res.push_back(val);
      }
    }
    return res;
}

template<typename T>
vector<vector<T>> buildTwoDimensionalArray(string input){
     string str = input.substr(1,input.length()-2);
    if(str.empty())
        return {};
    
    vector<string> tokens;
    stringstream ss;
    int i = 0;
    while(i < str.size()){
        if(str[i]=='['){
            int j = i;
            while(str[j]!=']')
                ss << str[j++];
            ss << str[j];
            i = j+1;
        }
        if(i < str.size() && str[i++]==','){  // "," at outer loop
            tokens.push_back(ss.str());
            ss.str("");
        }
    }

    tokens.push_back(ss.str());
    vector<vector<T>> res;
    for(const auto& token : tokens)
        res.push_back(buildOneDimensionalArray<T>(token));
    
    return res;
}

TreeNode* buildBinaryTreeByLevelOrder(string& input){

	auto trimLeftTrailingSpaces = [](string& input){
		input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
			return !isspace(ch);
		}));
	};

	auto trimRightTrailingSpaces = [](string& input){
		input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
			return !isspace(ch);
		}).base(), input.end());
	};


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

void displayBinaryTree(TreeNode* node, Option option)
{

	auto preorder = [](TreeNode* root, vector<string>& data) {
		if (!root) return;
		
		stack<TreeNode*> nodes;
		TreeNode* currentNode = root;
		
		while (!nodes.empty() || currentNode) {
			if (currentNode) {
				nodes.push(currentNode);
				data.push_back(to_string(currentNode->val));
				currentNode = currentNode->left;
			}
			else {
				currentNode = nodes.top()->right;
				nodes.pop();
			}
		}
	};

	auto inorder= [](TreeNode* root, vector<string>& data){
		if (!root) return;

		stack<TreeNode*> nodes;
		TreeNode* currentNode = root;

		while (!nodes.empty() || currentNode) {
			if (currentNode) {
				nodes.push(currentNode);
				currentNode = currentNode->left;
			}
			else {
				data.push_back(to_string(nodes.top()->val));
				currentNode = nodes.top()->right;
				nodes.pop();
			}
		}
	};

	auto postorder = [](TreeNode* root, vector<string>& data) {
		if (!root) return;
	
		stack<TreeNode*> s;

		s.push(root);
		TreeNode* head = root;
		while (!s.empty()) {
			TreeNode* t = s.top();
			
			if ((!t->left && !t->right) || t->left == head || t->right == head) {
				data.push_back(to_string(t->val));
				s.pop();
				head = t;
			}
			else {
				if (t->right)
					s.push(t->right);

				if (t->left)
					s.push(t->left);
			}
		}
	};

	auto levelorder = [](TreeNode* node, vector<string>& data) {
		int count = 0;
		queue<TreeNode*> seq;
		seq.push(node);
		const char* token = "";
		auto countNotNullTreeNode = [](TreeNode* node){
			if(!node)	return 0;
		
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
		};

		int N = countNotNullTreeNode(node);

		while (!seq.empty() && count < N) {
			TreeNode* currentNode = seq.front();
			seq.pop();
			if (!currentNode)
				data.push_back("null");
			else {
				data.push_back(to_string(currentNode->val));
				++count;
				currentNode->left ? seq.push(currentNode->left) : seq.push(nullptr);
				currentNode->right ? seq.push(currentNode->right) : seq.push(nullptr);
			}
		}
	};

	vector<string> data;
	switch (option) 
	{
	case Option::PREORDER:
		preorder(node, data);
		break;
	case Option::INORDER:
		inorder(node, data);
		break;
	case Option::POSTORDER:
		postorder(node, data);
		break;
	case Option::LEVELORDER:
		levelorder(node, data);
	default:
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

template<typename T>
string serializeToString(vector<vector<T>> input){
    stringstream out;
    string token_outside = "";
    out << "[";
    for(int i = 0 ; i < input.size(); ++i){    
        out << token_outside << "[";
        string token_inside = "";
        for(int j = 0 ; j < input[i].size(); ++j){
            out << token_inside << to_string(input[i][j]);
            token_inside = ",";
        }
        out << "]";
        token_outside = ",";
    }
    out << "]";

    return out.str();
}

template<typename T>
string serializeToString(vector<T> input){
    stringstream out;
    string token_inside = "";
    out << "[";
    for(int i = 0 ; i < input.size(); ++i){    
        out << token_inside << to_string(input[i]);
        token_inside = ",";
    }
    out << "]";

    return out.str();
}