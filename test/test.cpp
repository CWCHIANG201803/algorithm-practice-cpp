#include "../src/solution/solution.hpp"
#include "gtest/gtest.h"


class SolutionMultipleParametersTests : public ::testing::TestWithParam<std::tuple<vector<int>,int, vector<int>>> {
protected:
	solution sol;
};
TEST_P(SolutionMultipleParametersTests, SolutionTwoSums)
{

	vector<int> inputData = std::get<0>(GetParam());
	int inputTarget = std::get<1>(GetParam());

	vector<int> expected = std::get<2>(GetParam());

	ASSERT_EQ(expected, sol.twoSum(inputData, inputTarget));
}

INSTANTIATE_TEST_SUITE_P(
	twoSumSolutionTest,
	SolutionMultipleParametersTests,
	::testing::Values(
		std::make_tuple(vector<int>{2, 11, 18, 7, 15}, 13, vector<int>{0, 1}),
		std::make_tuple(vector<int>{}, 0, vector<int>{}),
		std::make_tuple(vector<int>{2, 11, 18, 7, 15}, 25, vector<int>{2, 3}),
		std::make_tuple(vector<int>{2, 11, 18, 7, 15}, 0, vector<int>{})));
