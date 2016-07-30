#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		if (nums.empty()) return 0;
		sort(nums.begin(), nums.end());
		int size = nums.size();
		int result = 0x0FFFFFFF, temp;
		for (int i = 0; i < size - 2; ++i) {
			int head = i + 1, tail = size - 1, f = target - nums[i];
			while (head < tail) {
				temp = nums[head] + nums[tail];
				if (temp > f) {
					--tail;
				} else if (temp < f) {
					++head;
				} else {
					return target;
				}
				result = abs(result - target) < abs(temp - f) ? result : temp + nums[i];
			}
		}
		return result;
	}
};
int main(int argc, char** argv) {
	Solution solution;
	vector<int> nums = { -3, -2, -5, 3, -4 };
	cout << solution.threeSumClosest(nums, -1) << endl;
	return 0;
}