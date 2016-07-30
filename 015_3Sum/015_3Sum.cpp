#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		if (nums.size() < 3) return vector<vector<int>>();
		vector<vector<int>> result;
		vector<int> resultTemp;
		resultTemp.resize(3);
		sort(nums.begin(), nums.end());
		unsigned int size = nums.size();
		for (int i = 0; i < size - 2; ++i) {
			if (i > 0 && nums[i] == nums[i - 1]) {
				continue;
			}
			int head = i + 1, tail = size - 1, f = -nums[i];
			while (head < tail) {
				if (nums[head] + nums[tail]>f) {
					--tail;
				} else if (nums[head] + nums[tail] < f) {
					++head;
				} else {
					resultTemp[0] = nums[i];
					resultTemp[1] = nums[head];
					resultTemp[2] = nums[tail];
					result.push_back(resultTemp);
					do {
						++head;
					} while (head < tail&&nums[head] == resultTemp[1]);
					do {
						--tail;
					} while (tail > head&&nums[tail] == resultTemp[2]);
				}
			}
			// 			for (int j = i + 1; j < size - 1; ++j) {
			// 				if (j - 1 > i&&nums[j] == nums[j - 1]) {
			// 					continue;
			// 				}
			// 				int head = j + 1, tail = size - 1, k, f = -nums[i] - nums[j];
			// 				if (nums[head] <= f&&nums[tail] >= f) {
			// 					while (head < tail - 1) {
			// 						k = (head + tail) / 2;
			// 						if (nums[k] < f) {
			// 							head = k;
			// 						} else {
			// 							tail = k;
			// 						}
			// 					}
			// 					if (nums[head] == f) {
			// 						resultTemp[0] = nums[i];
			// 						resultTemp[1] = nums[j];
			// 						resultTemp[2] = nums[head];
			// 						if (result.empty() || result.back()[0] != resultTemp[0] || result.back()[1] != resultTemp[1] || result.back()[2] != resultTemp[2]) {
			// 							result.push_back(resultTemp);
			// 						}
			// 					} else if (nums[tail] == f) {
			// 						resultTemp[0] = nums[i];
			// 						resultTemp[1] = nums[j];
			// 						resultTemp[2] = nums[tail];
			// 						if (result.empty() || result.back()[0] != resultTemp[0] || result.back()[1] != resultTemp[1] || result.back()[2] != resultTemp[2]) {
			// 							result.push_back(resultTemp);
			// 						}
			// 					}
			// 				}
			// 			}
		}
		return result;
	}
};
int main(int argc, char** argv) {
	Solution solution;
	vector<int> nums = { -2, 0, 0, 2, 2};
	vector<vector<int>> result = solution.threeSum(nums);
	for (auto i : result) {
		cout << "[";
		for (auto j : i) {
			cout << j << ",";
		}
		cout << "\b]" << endl;
	}
	return 0;
}