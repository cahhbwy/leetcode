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
		int size = nums.size();
		for (int i = 0; i < size - 2; ++i) {
			for (int j = i + 1; j < size - 1; ++j) {
				if (j - 1 > i&&nums[j] == nums[j - 1]) {
					continue;
				}
				int f = -nums[i] - nums[j];
				for (int k = j + 1; k < size; ++k) {
					if (nums[k] == f) {
						resultTemp[0] = nums[i];
						resultTemp[1] = nums[j];
						resultTemp[2] = f;
						bool push = true;
						sort(resultTemp.begin(), resultTemp.end());
						for (vector<int> t : result) {
							if (t[0] == resultTemp[0] && t[1] == resultTemp[1] && t[2] == resultTemp[2]) {
								push = false;
								break;
							}
						}
						if (push) {
							result.push_back(resultTemp);
						}
					}
				}
			}
		}
		return result;
	}
};
int main(int argc, char** argv) {
	Solution solution;
	vector<int> nums = { -1, 0, 1, 2, -1, -4 };
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