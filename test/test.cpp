#include "../src/solution/solution.hpp"
#include "../src/utility/inputProcessUtility.hpp"
#include "gtest/gtest.h"


class SolutionMultipleParametersTests : public ::testing::TestWithParam<std::tuple<string, int, string>> {
protected:
	solution sol;
	inputProcessUtility utility;
};

TEST_P(SolutionMultipleParametersTests, solutionTwoSums){
	string input = std::get<0>(GetParam());
	vector<int> nums = utility.convertToInt(utility.buildOneDimensionalArray(input));
	int n = std::get<1>(GetParam());

	string expected = std::get<2>(GetParam());
	ASSERT_EQ(expected, utility.serializeToString(sol.twoSum(nums, n)));
}

INSTANTIATE_TEST_SUITE_P(
	solutionTwoSumTest,
	SolutionMultipleParametersTests,
	::testing::Values(
		std::make_tuple("[2,11,18,7,15]", 13, "[0,1]"),
		std::make_tuple("[]", 0, "[]"),
		std::make_tuple("[2,11,18,7,15]", 25, "[2,3]"),
		std::make_tuple("[2,11,18,7,15]", 0, "[]")
	));
