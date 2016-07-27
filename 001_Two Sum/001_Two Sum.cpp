#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_multimap<int, int> hashNums;
		unordered_multimap<int, int>::iterator it;
		for (int i = 0; i < nums.size(); ++i) {
			hashNums.insert(pair<int, int>(nums.at(i), i));
		}
		for (auto i : hashNums) {
			it = hashNums.find(target - i.first);
			if (it != hashNums.end() && it->second != i.second) {
				return vector<int>{i.second, it->second};
			}
		}
		return vector<int>();
	}
};
int main(int argc, char** argv) {
	vector<int> nums = { 0, 2, 3, 0 };
	Solution solution;
	vector<int> result = solution.twoSum(nums, 0);
	cout << "[";
	for (auto i : result) {
		cout << i << ",";
	}
	cout << "\b" << "]" << endl;
	return 0;
}