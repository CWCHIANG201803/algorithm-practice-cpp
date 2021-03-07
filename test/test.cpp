#include "gtest/gtest.h"
#include "../solution/LFUCache.hpp"
#include "../utility/utility.hpp"
#include <vector>
#include <string>
#include <regex>
#include <unordered_map>
using namespace std;


class SolutionMultipleParametersTests : public ::testing::TestWithParam<std::tuple<string, string, string>> {
protected:
	LFUCache* obj;
	string act(vector<string> commands, vector<string> inputs);
private:
	enum Action { init, get, put };
	unordered_map<string, Action> dict{ 
		{ "LFUCache", Action::init }, 
		{ "get", Action::get },
		{ "put", Action::put }
	};
};


string SolutionMultipleParametersTests::act(vector<string> commands, vector<string> inputs){
	vector<string> result;
	int n = commands.size();

	for(int i = 0 ; i < n; ++i){
		string command = commands[i];
		vector<int> args = buildOneDimensionalArray<int>(inputs[i]);

		Action action = dict[command];

		int capacity, getVal, idx, putKey, putVal;

		switch (action)
		{
		case Action::init:
			capacity = args[0];
			obj = new LFUCache(capacity);
			result.push_back("null");
			break;
		case Action::get:
			getVal = args[0];
			result.push_back(to_string(obj->get(getVal)));
			break;
		case Action::put:
			putKey = args[0];
			putVal = args[1];
			obj->put(putKey, putVal);
			result.push_back("null");
			break;
		default:
			break;
		}

	}

	

	return serializeToString<string>(result);
}

TEST_P(SolutionMultipleParametersTests, SolutionLFUCache){
	string i1 = std::get<0>(GetParam());
	vector<string> cmds = buildOneDimensionalArray<string>(i1);

	string i2 = std::get<1>(GetParam());
	vector<string> inputs = parseArguments(i2);

	string result = act(cmds, inputs);
	string expected = std::get<2>(GetParam());

	ASSERT_EQ(expected, result);
}

INSTANTIATE_TEST_SUITE_P(
	lfucacheTestProvider,
	SolutionMultipleParametersTests,
	::testing::Values(
		std::make_tuple("[LFUCache,put,put,get,put,get,get,put,get,get,get]",
		"[[2],[1,1],[2,2],[1],[3,3],[2],[3],[4,4],[1],[3],[4]]",
		"[null,null,null,1,null,-1,3,null,-1,3,4]")
	));


