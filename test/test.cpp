#include "gtest/gtest.h"
#include "../src/solution/solution.hpp"
#include "../src/binaryTreeUtility/binaryTreeUtility.hpp"
#include <string>
using namespace std;


class SolutionMultipleParametersTests : public ::testing::TestWithParam<std::tuple<string, vector<vector<int>>>> {
protected:
	solution sol;
	binaryTreeUtility utility;
};


TEST_P(SolutionMultipleParametersTests, solutionZigzagLevelOrder) {
	string input = std::get<0>(GetParam());
	vector<vector<int>> expected = std::get<1>(GetParam());
	ASSERT_EQ(expected, sol.zigzagLevelOrder(utility.buildBinaryTreeByLevelOrder(input)));
}

INSTANTIATE_TEST_SUITE_P(
	ZigzagLevelOrderSolution,
	SolutionMultipleParametersTests,
	::testing::Values(
		std::make_tuple("[3,9,20,null,null,15,7]", vector<vector<int>>{ {3}, { 20, 9 }, { 15, 7 }})
	));


