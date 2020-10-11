#include "singularLinkedListUtility.hpp"
#include <algorithm>
#include <sstream>
using namespace std;



void singularLinkedListUtility::trimLeftTrailingSpaces(string& input) {
	input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
		return !isspace(ch);
		}));
}

void singularLinkedListUtility::trimRightTrailingSpaces(string& input) {
	input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
		return !isspace(ch);
		}).base(), input.end());
}

vector<int> singularLinkedListUtility::stringToIntegerVector(string input) {
	vector<int> output;
	trimLeftTrailingSpaces(input);
	trimRightTrailingSpaces(input);
	input = input.substr(1, input.length() - 2);
	stringstream ss;
	ss.str(input);
	string item;
	char delim = ',';
	while (getline(ss, item, delim)) {
		output.push_back(stoi(item));
	}
	return output;
}

ListNode* singularLinkedListUtility::stringToCircularList(string input,int pos) {
	// Generate list from the input
	vector<int> list = stringToIntegerVector(input);

	if (pos < 0) return stringToListNode(input);
	ListNode* dummyRoot = new ListNode(0);
	ListNode* ptr = dummyRoot;
	ListNode* target = dummyRoot;
	int count = 0;
	for (int item : list) {
		ptr->next = new ListNode(item);
		if (count == pos) 
			target = ptr->next;
		ptr = ptr->next;
		++count;
	}
	ptr->next = target;
	ptr = dummyRoot->next;
	delete dummyRoot;
	return ptr;
}

ListNode* singularLinkedListUtility::stringToListNode(string input) {
	// Generate list from the input
	vector<int> list = stringToIntegerVector(input);

	// Now convert that list into linked list
	ListNode* dummyRoot = new ListNode(0);
	ListNode* ptr = dummyRoot;
	for (int item : list) {
		ptr->next = new ListNode(item);
		ptr = ptr->next;
	}
	ptr = dummyRoot->next;
	delete dummyRoot;
	return ptr;
}

int singularLinkedListUtility::stringToInteger(string input) {
	return stoi(input);
}

string singularLinkedListUtility::listNodeToString(ListNode* node) {
	stringstream oss;
	oss << "[";
	string separator = "";
	if (node) {
		ListNode* current = node;
		while (node) {
			oss << separator << node->val;
			separator = ",";
			node = node->next;
		}
	}
	oss << "]";
	return oss.str();
}

ListNode* singularLinkedListUtility::reverseList(ListNode* head) {
	if (!head) 
		return head;
	
	ListNode* dummy = new ListNode(-9999);
	dummy->next = head;
	
	ListNode* current = head;
	ListNode* prev = dummy;
	ListNode* fore = nullptr;
	while (current) {
		fore = current->next;
		current->next = prev;
		prev = current;
		current = fore;
	}
	head->next = nullptr;
	current = nullptr;
	return prev;
}
