#include "../src/solution/Solution.hpp"
#include "gtest/gtest.h"
#include <vector>
#include <string>
#include <regex>
#include <unordered_map>
using namespace std;


class SolutionMultipleParametersTests : public ::testing::TestWithParam<std::tuple<vector<pair<string,string>>, vector<string>>> {
protected:
	Solution* obj;
	vector<string> utility(vector<pair<string,string>> inputs);
	vector<int> convertStrToArray(string s);
	string convertArrayToStr(const vector<int>& nums);
private:
	enum Action { init, shuffle, reset };
	unordered_map<string, Action> dict{ 
		{ "Solution", Action::init }, 
		{ "shuffle", Action::shuffle },
		{ "reset", Action::reset }
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
		vector<int> seq;
		switch (action)
		{
		case Action::init:
			seq = convertStrToArray(arg);
			obj = new Solution(seq);
			result.push_back("null");
			break;
		case Action::shuffle:
			result.push_back(convertArrayToStr(obj->shuffle()));
			break;
		case Action::reset:
			result.push_back(convertArrayToStr(obj->reset()));
			break;
		default:
			break;
		}
	}
	return result;
}

TEST_P(SolutionMultipleParametersTests, SolutionShuffle){
	vector<pair<string,string>> inputs = std::get<0>(GetParam());
	vector<string> result = utility(inputs);
	vector<string> expected = std::get<1>(GetParam());

	ASSERT_EQ(expected, result);
}

INSTANTIATE_TEST_SUITE_P(
	shuffleTestProvider,
	SolutionMultipleParametersTests,
	::testing::Values(
		std::make_tuple(
			vector<pair<string,string>>
			{
				{ "Solution", "[1,2,3]"}, { "shuffle", "[]"}, { "reset", "[]"}, { "shuffle", "[]"}
			}, 
			vector<string>
			{	
				"null", "[3,1,2]", "[1,2,3]", "[1,3,2]" 
			}
		)
	));
