#include "../solution/LFUCache.hpp"
#include "gtest/gtest.h"
#include <vector>
#include <string>
#include <regex>
#include <unordered_map>
using namespace std;


class SolutionMultipleParametersTests : public ::testing::TestWithParam<std::tuple<vector<pair<string,string>>, vector<string>>> {
protected:
	LFUCache* obj;
	vector<string> utility(vector<pair<string,string>> inputs);
	vector<int> convertStrToArray(string s);
	string convertArrayToStr(const vector<int>& nums);
private:
	enum Action { init, get, put };
	unordered_map<string, Action> dict{ 
		{ "LFUCache", Action::init }, 
		{ "get", Action::get },
		{ "put", Action::put }
	};
};

vector<int> SolutionMultipleParametersTests::convertStrToArray(string s){
	std::regex e ("([.]|[^.,]+)");
	std::regex_iterator<std::string::iterator> rit ( s.begin()+1, s.end()-1, e );
    std::regex_iterator<std::string::iterator> rend;
    vector<int> result;
	
	while (rit!=rend) {
		result.push_back(stoi(rit->str()));
        ++rit;
    }
	return result;
}

string SolutionMultipleParametersTests::convertArrayToStr(const vector<int>& nums){
	stringstream out;
	
	string delimiter = "";
	out << "[";
	for(auto& num : nums){
		out << delimiter << num;
		delimiter = ",";
	}
	out << "]";

	return out.str();
}

vector<string> SolutionMultipleParametersTests::utility(vector<pair<string,string>> inputs){
	vector<string> result;
	for(auto commands : inputs){
		string input = commands.first;
		string arg = commands.second;
		Action action = dict[input];
		int capacity, getVal, idx, putKey, putVal;
		switch (action)
		{
		case Action::init:
			capacity = stoi(arg);
			obj = new LFUCache(capacity);
			result.push_back("null");
			break;
		case Action::get:
			getVal = stoi(arg.substr(1,arg.length()-2));
			result.push_back(to_string(obj->get(getVal)));
			break;
		case Action::put:
			idx = find(arg.begin(), arg.end(), ',')-arg.begin();
			putKey = stoi(arg.substr(1,idx));
			putVal = stoi(arg.substr(idx+1,arg.length()-(idx+1)-1));
			obj->put(putKey, putVal);
			result.push_back("null");
			break;
		default:
			break;
		}
	}
	return result;
}

TEST_P(SolutionMultipleParametersTests, SolutionLFUCache){
	vector<pair<string,string>> inputs = std::get<0>(GetParam());
	vector<string> result = utility(inputs);
	vector<string> expected = std::get<1>(GetParam());

	ASSERT_EQ(expected, result);
}

INSTANTIATE_TEST_SUITE_P(
	lfucacheTestProvider,
	SolutionMultipleParametersTests,
	::testing::Values(
		std::make_tuple(
			vector<pair<string,string>>
			{
				{ "LFUCache", "[2]" }, 
				{ "put", "[1,1]" }, 
				{ "put", "[2,2]" }, 
				{ "get", "[1]" },
				{ "put", "[3,3]" }, 
				{ "get", "[2]" }, 
				{ "get", "[3]" }, 
				{ "put", "[4,4]" }, 
				{ "get", "[1]" }, 
				{ "get", "[3]" }, 
				{ "get", "[4]" }, 
			}, 
			vector<string>
			{	
				"null", 
				"null", 
				"null",
				"1", 
				"null", "-1","3","null","-1","3" ,"4"
			}
		)
	));

/*
["LFUCache","put","put","get","put","get","get","put","get","get","get"]
[[2],[1,1],[2,2],[1],[3,3],[2],[3],[4,4],[1],[3],[4]]
[null,null,null,1,null,-1,3,null,-1,3,4]

*/
