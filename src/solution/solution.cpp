#include "solution.hpp"

ListNode* solution::swapPairs(ListNode* head){
	if (!head || !head->next) return head;
	int count = 0;
	ListNode* currentNode = head;
	ListNode* firstNode = head;
	ListNode* secondNode = head;

	while (currentNode){
		if (currentNode->next){
			firstNode = currentNode;
			secondNode = firstNode->next;
			if (currentNode->next->next) {

				currentNode = currentNode->next->next;
				firstNode->next = currentNode->next;
			}else {
				currentNode = nullptr;
				firstNode->next = currentNode;
			}
		}else {
			firstNode->next = currentNode;
			currentNode->next = nullptr;
			return head;
		}

		secondNode->next = firstNode;
		if (count == 0) head = secondNode;
		++count;
	}
		
	return head;
}
