#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	int search(vector<int>& nums, int target) {
		if (nums.empty())
			return -1;
		int a = 0, c = nums.size() - 1, b;
		while (a <= c) {
			b = (a + c) / 2;
			if (nums[b] == target)
				return b;
			if (nums[a] <= nums[b]) {
				if (nums[a] <= target&&target < nums[b]) {
					c = b;
				} else {
					a = b + 1;
				}
			} else {
				if (nums[b] < target && target <= nums[c]) {
					a = b + 1;
				} else {
					c = b;
				}
			}
		}
		return -1;
	}
};
int main(int argc, char **argv) {
	Solution solution;
	cout << solution.search(vector<int>{3, 4, 5, 1, 2}, 1) << endl;
	system("pause");
	return 0;
}