#include "../src/singularLinkedListUtility/singularLinkedListUtility.hpp"
#include "../src/solution/solution.hpp"
#include "gtest/gtest.h"

class SolutionMultipleParametersTests : public ::testing::TestWithParam<std::tuple<string, int, bool>>
{
protected:
	singularLinkedListUtility utility;
	solution sol;
};

TEST_P(SolutionMultipleParametersTests, solutionHasCycle)
{
	string input = std::get<0>(GetParam());
	int pos = std::get<1>(GetParam());
	ListNode *inputLinkedList = utility.stringToCircularList(input, pos);
	bool expected = std::get<2>(GetParam());

	ASSERT_EQ(expected, sol.hasCycle(inputLinkedList));
}

INSTANTIATE_TEST_SUITE_P(
	hasCycleSolutionTest,
	SolutionMultipleParametersTests,
	::testing::Values(
		std::make_tuple("[3,2,0,-4,7,8]", 2, true),
		std::make_tuple("[1,2]", 0, true),
		std::make_tuple("[2,3,0,4]", 3, true),
		std::make_tuple("[2,3,0,4]", -1, false)
	));
