#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		if (nums.empty()) {
			return vector<int>({ -1, -1 });
		}
		int al = 0, ah = nums.size() - 1, a;
		int bl = 0, bh = nums.size() - 1, b;
		while (al <= ah) {
			a = (al + ah) / 2;
			if (nums[a] < target) {
				al = a + 1;
			} else if (nums[a] > target) {
				ah = a - 1;
			} else if (al < ah) {
				ah = a;
			} else {
				break;
			}
		}
		while (bl <= bh) {
			b = (bl + bh + 1) / 2;
			if (nums[b] < target) {
				bl = b + 1;
			} else if (nums[b] > target) {
				bh = b - 1;
			} else if (bl < bh) {
				bl = b;
			} else {
				break;
			}
		}
		if (nums[a] != target) {
			a = -1;
		}
		if (nums[b] != target) {
			b = -1;
		}
		return vector<int>({ a, b });
	}
};
int main(int argc, char** argv) {
	Solution solution;
	vector<int> sample({});
	vector<int> result = solution.searchRange(sample, 8);
	cout << result[0] << ", " << result[1] << endl;
	system("pause");
	return 0;
}