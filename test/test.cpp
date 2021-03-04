#include "gtest/gtest.h"
#include "../solution/LFUCache.hpp"
#include "../utility/utility.hpp"
#include <vector>
#include <string>
#include <regex>
#include <unordered_map>
using namespace std;


class SolutionMultipleParametersTests : public ::testing::TestWithParam<std::tuple<vector<vector<string>>, vector<string>>> {
protected:
	LFUCache* obj;
	vector<string> act(vector<vector<string>> inputs);
private:
	enum Action { init, get, put };
	unordered_map<string, Action> dict{ 
		{ "LFUCache", Action::init }, 
		{ "get", Action::get },
		{ "put", Action::put }
	};
};


vector<string> SolutionMultipleParametersTests::act(vector<vector<string>> inputs){
	vector<string> result;
	for(auto commands : inputs){
		string input = commands[0];
		vector<string> args = buildOneDimensionalArray<string>(commands[1]);
		Action action = dict[input];
		int capacity, getVal, idx, putKey, putVal;
		switch (action)
		{
		case Action::init:
			capacity = stoi(args[0]);
			obj = new LFUCache(capacity);
			result.push_back("null");
			break;
		case Action::get:
			getVal = stoi(args[0]);
			result.push_back(to_string(obj->get(getVal)));
			break;
		case Action::put:
			putKey = stoi(args[0]);
			putVal = stoi(args[1]);
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
	vector<vector<string>> inputs = std::get<0>(GetParam());
	vector<string> result = act(inputs);
	vector<string> expected = std::get<1>(GetParam());

	ASSERT_EQ(expected, result);
}

INSTANTIATE_TEST_SUITE_P(
	lfucacheTestProvider,
	SolutionMultipleParametersTests,
	::testing::Values(
		std::make_tuple(
			vector<vector<string>>
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
