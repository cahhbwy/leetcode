#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int last;
		if (!nums.empty()) {
			last = nums[0] - 1;
			for (vector<int>::iterator it = nums.begin(); it != nums.end();) {
				if (last == *it) {
					it = nums.erase(it);
				} else {
					last = *it;
					++it;
				}
			}
		}
		return nums.size();
	}
};
int main(int argc, char **argv) {
	Solution solution;
	vector<int> nums = { 0, 1, 1, 2, 2, 3, 5, 6, 7 };
	cout << solution.removeDuplicates(nums) << endl;
	return 0;
}