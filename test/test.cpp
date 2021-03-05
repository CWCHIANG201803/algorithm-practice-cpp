#include "gtest/gtest.h"
#include "../src/solution/solution.hpp"
#include "../src/utility/utility.hpp"
#include <string>
using namespace std;


class SolutionMultipleParametersTests : public ::testing::TestWithParam<std::tuple<string, string>> {
protected:
	solution sol;
};


TEST_P(SolutionMultipleParametersTests, solutionZigzagLevelOrder) {
	string input = std::get<0>(GetParam());
	TreeNode* root = buildBinaryTreeByLevelOrder(input);
	
	string result = serializeToString(sol.zigzagLevelOrder(root));
	string expected = std::get<1>(GetParam());
	
	ASSERT_EQ(expected, result);
}

INSTANTIATE_TEST_SUITE_P(
	zigzagLevelOrderSolution,
	SolutionMultipleParametersTests,
	::testing::Values(
		std::make_tuple("[3,9,20,null,null,15,7]", "[[3],[20,9],[15,7]]")
	)
);


