#include <iostream>
#include "solution/solution.hpp"
#include "singularLinkedListUtility/singularLinkedListUtility.hpp"
#include <iostream>
using namespace std;


int main(int argc, char* argv[]){


    cout << "hello world" << endl;

    singularLinkedListUtility utility;
    ListNode* head = utility.stringToListNode("[1,2,3,4]");

    solution sol;
    bool result = sol.hasCycle(head);
    result ? cout << "yes" : cout << "no";
    cout << endl;

    return 0;
}