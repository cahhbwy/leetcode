#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		for (vector<int>::iterator it = nums.begin(); it != nums.end();) {
			if (*it == val) {
				it = nums.erase(it);
			} else {
				++it;
			}
		}
		return nums.size();
	}
};
int main(int argc, char **argv) {
	Solution solution;
	vector<int> nums = { 0, 1, 1, 2, 2, 3, 5, 6, 7 };
	cout << solution.removeElement(nums, 5) << endl;
	return 0;
}