#include "../src/solution/MinStack.hpp"
#include "gtest/gtest.h"
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;


class SolutionMultipleParametersTests : public ::testing::TestWithParam<std::tuple<vector<pair<string,string>>, vector<string>>> {
protected:
	MinStack* stack;
	vector<string> utility(vector<pair<string,string>> inputs);
private:
	enum Action { init, push, pop, top, getmin };
	unordered_map<string, Action> dict{ 
		{ "MinStack", Action::init }, 
		{ "push", Action::push },
		{ "pop", Action::pop },
		{ "top", Action::top },
		{ "getMin", Action::getmin }
	};
};

vector<string> SolutionMultipleParametersTests::utility(vector<pair<string,string>> inputs){
	vector<string> result;
	for(auto commands : inputs){
		string input = commands.first;
		string arg = commands.second;
		Action action = dict[input];

		switch (action)
		{
		case Action::init:
			stack = new MinStack();
			result.push_back(stack ? "null":"");
			break;
		case Action::push:
			stack->push(3);
			result.push_back("null");
			break;
		case Action::pop:
			stack->pop();
			result.push_back("null");
			break;
		case Action::top:
			result.push_back(std::to_string(stack->top()));
			break;
		case Action::getmin:
			result.push_back(std::to_string(stack->getMin()));
			break;
		default:
			break;
		}
	}
	return result;
}

TEST_P(SolutionMultipleParametersTests, SolutionMinStack){
	vector<pair<string,string>> inputs = std::get<0>(GetParam());
	vector<string> result = utility(inputs);
	vector<string> expected = std::get<1>(GetParam());

	ASSERT_EQ(expected, result);
}

INSTANTIATE_TEST_SUITE_P(
	minStackTestProvider,
	SolutionMultipleParametersTests,
	::testing::Values(
		std::make_tuple(
			vector<pair<string,string>>
			{
				{ "MinStack", ""}, { "push", "-2"}, { "push", "0"}, { "push", "-3"}, { "getMin", ""}, { "pop", ""}, { "top", ""}, { "getMin", ""}
			}, 
			vector<string>
			{
				"null", "null", "null", "null", "-3", "null", "0", "-2" 
			}
		)
	));
