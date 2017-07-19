#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
	void nextPermutation(vector<int>& nums)
	{
		int length = nums.size();
		int left = -1;
		for (int i = length - 1; i > 0; i--)
		{
			if (nums[i] > nums[i - 1])
			{
				left = i - 1;
				break;
			}
		}
		if (left == -1)
		{
			reverse(nums.begin(), nums.end());
			return;
		}
		for (int i = length - 1; i > left; i--)
		{
			if (nums[i] > nums[left])
			{
				swap(nums[i], nums[left]);
				break;
			}
		}
		reverse(nums.begin() + left + 1, nums.end());
	}
};
int main()
{
	Solution solution;
	vector<int> nums = { 1,3,2 };
	solution.nextPermutation(nums);
	for (auto i : nums)
	{
		cout << i << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}