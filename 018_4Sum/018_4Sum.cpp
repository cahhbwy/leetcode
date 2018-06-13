#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		if (nums.size() < 4) return vector<vector<int>>();
		vector<vector<int>> result;
		vector<int> resultTemp;
		resultTemp.resize(4);
		sort(nums.begin(), nums.end());
		unsigned int size = nums.size();
		for (int i = 0; i < size - 3; ++i) {
			if (i > 0 && nums[i] == nums[i - 1]) {
				continue;
			}
			for (int j = i + 1; j < size - 2; ++j) {
				if (j > i + 1 && nums[j] == nums[j - 1]) {
					continue;
				}
				int head = j + 1, tail = size - 1, f = target - nums[i] - nums[j];
				while (head < tail) {
					if (nums[head] + nums[tail] > f) {
						--tail;
					} else if (nums[head] + nums[tail] < f) {
						++head;
					} else {
						resultTemp[0] = nums[i];
						resultTemp[1] = nums[j];
						resultTemp[2] = nums[head];
						resultTemp[3] = nums[tail];
						result.push_back(resultTemp);
						do {
							++head;
						} while (head < tail&&nums[head] == resultTemp[2]);
						do {
							--tail;
						} while (tail > head&&nums[tail] == resultTemp[3]);
					}
				}
			}
		}
		return result;
	}
};
int main(int argc, char** argv) {
	Solution solution;
	vector<int> nums = { 1, 0, -1, 0, -2, 2 };
	vector<vector<int>> result = solution.fourSum(nums, 0);
	for (auto i : result) {
		cout << "[";
		for (auto j : i) {
			cout << j << ",";
		}
		cout << "\b]" << endl;
	}
	return 0;
}