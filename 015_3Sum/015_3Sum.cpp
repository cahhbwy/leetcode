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
				if (nums[head] + nums[tail] > f) {
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
		}
		return result;
	}
};
int main(int argc, char** argv) {
	Solution solution;
	vector<int> nums = { -2, 0, 0, 2, 2 };
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