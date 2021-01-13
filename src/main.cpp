#include <iostream>
#include "solution/solution.hpp"
#include "binaryTreeUtility/binaryTreeUtility.hpp"
using namespace std;


void display(TreeNode* root){
    if(!root) 
        return;
    
    display(root->left);
    cout << root->val << endl;;
    display(root->right);
}

int main(int argc, char* argv[]){
    binaryTreeUtility utility;
    string tree = "[1,2,3]";
    TreeNode* root = utility.buildBinaryTreeByLevelOrder(tree);
    display(root);
    return 0;
}