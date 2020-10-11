#include "solution.hpp"

vector<int> solution::twoSum(vector<int> &nums, int target)
{
	int i = 0;
	int N = nums.size();
	int j = 0;
	for (i = 0; i < N; i++)
	{
		int secVal = target - nums[i];
		j = 0;
		while (j < N)
		{
			if (secVal == nums[j] && secVal != nums[i])
			{
				return {i, j};
			}
			++j;
		}
	}
	return {};
}
