#include "../resources/ListNode.hpp"
#include <string>
#include <vector>
using namespace std;


class singularLinkedListUtility {
public:
	ListNode* reverseList(ListNode*);
	ListNode* stringToListNode(string);
	ListNode* stringToCircularList(string,int);
	string listNodeToString(ListNode*);
private:
	int stringToInteger(string);
	void trimLeftTrailingSpaces(string&);
	void trimRightTrailingSpaces(string&);
	vector<int> stringToIntegerVector(string);
};
