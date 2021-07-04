#include "../src/utility/utility.hpp"
#include "../src/solution/solution.hpp"
#include "gtest/gtest.h"


// ListNode* swapPairs(ListNode* head);

class SolutionMultipleParametersTests : public ::testing::TestWithParam<std::tuple<string,string>>
{
protected:
	solution sol;
};

TEST_P(SolutionMultipleParametersTests, solutionSwapPairs)
{

	ListNode* head = buildSingularLinkedList(std::get<0>(GetParam()));
	string expected = std::get<1>(GetParam());
	ASSERT_EQ(expected, outputSingularLinkedList(sol.swapPairs(head)));
}

INSTANTIATE_TEST_SUITE_P(
	swapPairsSolutionTest,
	SolutionMultipleParametersTests,
	::testing::Values(
		std::make_tuple("[1,2,3,4]", "[2,1,4,3]"),
		std::make_tuple("[]","[]"),
		std::make_tuple("[1]", "[1]")
	));
