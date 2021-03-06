#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		if (nums.empty()) {
			return 1;
		}
		int i = 0;
		while (i < nums.size()) {
			if (nums[i] > 0 && nums[i] <= nums.size() && nums[i] != nums[nums[i] - 1]) {
				swap(nums[i], nums[nums[i] - 1]);
			} else {
				++i;
			}
		}
		for (i = 0; i < nums.size(); ++i) {
			if (nums[i] != i + 1) {
				return i + 1;
			}
		}
		return nums.back() + 1;
	}
};
int main(int argc, char** argv) {
	Solution solution;
	vector<int> nums({ 3,4,-1,1 });
	cout << solution.firstMissingPositive(nums) << endl;
	system("pause");
	return 0;
}