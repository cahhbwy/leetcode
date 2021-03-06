#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		int l = 0, h = nums.size() - 1, m;
		while (l <= h) {
			m = (l + h) / 2;
			if (nums[m] < target) {
				l = m + 1;
			} else if (nums[m] > target) {
				h = m - 1;
			} else {
				return m;
			}
		}
		if (h >= 0 && nums[h] > target) {
			return h;
		} else {
			return l;
		}
	}
};
int main(int argc, char** argv) {
	Solution solution;
	vector<int>nums({ 1,3,5,7,9 });
	cout << solution.searchInsert(nums, 0) << endl;
	cout << solution.searchInsert(nums, 1) << endl;
	cout << solution.searchInsert(nums, 2) << endl;
	cout << solution.searchInsert(nums, 3) << endl;
	cout << solution.searchInsert(nums, 4) << endl;
	cout << solution.searchInsert(nums, 5) << endl;
	cout << solution.searchInsert(nums, 6) << endl;
	cout << solution.searchInsert(nums, 7) << endl;
	cout << solution.searchInsert(nums, 8) << endl;
	cout << solution.searchInsert(nums, 9) << endl;
	cout << solution.searchInsert(nums, 10) << endl;
	system("pause");
	return 0;
}