#include "../resources/ListNode.hpp"
#include <algorithm>
#include <sstream>
#include <vector>
using namespace std;


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
string serializeToString(vector<vector<T>> input){
    stringstream out;
    string token_outside = "";
    out << "[";
    for(int i = 0 ; i < input.size(); ++i){    
        out << token_outside << "[";
        string token_inside = "";
        for(int j = 0 ; j < input[i].size(); ++j){
			if constexpr (std::is_same_v<T, string>){
				out << token_inside << input[i][j];
			}else {
				out << token_inside << to_string(input[i][j]);
			}
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
		if constexpr (std::is_same_v<T, string>){
			out << token_inside << input[i];
		}else {
			out << token_inside << to_string(input[i]);
		}
        token_inside = ",";
    }
    out << "]";

    return out.str();
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

ListNode* buildSingularLinkedList(string input) {
	// Generate list from the input
	vector<int> list = buildOneDimensionalArray<int>(input);

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



ListNode* stringToCircularList(string input, int pos) {
	// Generate list from the input
	vector<int> list = buildOneDimensionalArray<int>(input);

	if (pos < 0) 
		return buildSingularLinkedList(input);

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


ListNode* reverseList(ListNode* head) {
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

string outputSingularLinkedList(ListNode* head){

	ListNode* current = head;
	stringstream oss;
	oss << "[";
	string token = "";
	while(current){
		oss << token << current->val;
		token = ",";
		current = current->next;
	}
	oss << "]";

	return oss.str();
}