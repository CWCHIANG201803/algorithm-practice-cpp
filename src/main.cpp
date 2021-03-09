#include <iostream>
#include "solution/solution.hpp"
#include "../utility/utility.hpp"
#include "../resources/TreeNode.hpp"
using namespace std;


int main(int argc, char* argv[]){
    
    string input = "[1,2,3,4,null,6,7]";
    TreeNode* root = buildBinaryTreeByLevelOrder(input);

    return 0;
}