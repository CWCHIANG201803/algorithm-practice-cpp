#include "gtest/gtest.h"
#include "../solution/WordDistance.hpp"
#include "../utility/utility.hpp"
#include <vector>
#include <string>
#include <regex>
#include <unordered_map>
using namespace std;


class SolutionMultipleParametersTests : public ::testing::TestWithParam<std::tuple<string, string, string>> {
protected:
	WordDistance* obj;
	string act(vector<string> commands, vector<string> inputs);
private:
	enum Action { init, shortest };
	unordered_map<string, Action> dict{ 
		{ "WordDistance", Action::init }, 
		{ "shortest", Action::shortest }
	};
};


string SolutionMultipleParametersTests::act(vector<string> commands, vector<string> inputs){
	vector<string> result;
	int n = commands.size();

	for(int i = 0 ; i < n; ++i){
		string command = commands[i];
		vector<string> args = parseArguments(inputs[i]);

		Action action = dict[command];
		vector<string> words;
		string word1, word2;

		switch (action)
		{
		case Action::init:
			words = buildOneDimensionalArray<string>(args[0]);
			obj = new WordDistance(words);
			result.push_back("null");
			break;
		case Action::shortest:
			word1 = args[0];
			word2 = args[1];
			result.push_back(to_string(obj->shortest(word1, word2)));
			break;
		default:
			break;
		}

	}
	return serializeToString<string>(result);
}

TEST_P(SolutionMultipleParametersTests, SolutionWordDistance){
	string i1 = std::get<0>(GetParam());
	vector<string> cmds = buildOneDimensionalArray<string>(i1);

	string i2 = std::get<1>(GetParam());
	vector<string> inputs = parseArguments(i2);

	string result = act(cmds, inputs);
	string expected = std::get<2>(GetParam());

	ASSERT_EQ(expected, result);
}

INSTANTIATE_TEST_SUITE_P(
	wordDistanceTestProvider,
	SolutionMultipleParametersTests,
	::testing::Values(
		std::make_tuple("[WordDistance,shortest,shortest]",
		"[[[practice,makes,perfect,coding,makes]],[coding,practice],[makes,coding]]",
		"[null,null,null,1,null,-1,3,null,-1,3,4]")
	));


