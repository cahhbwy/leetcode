#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	int maxArea(vector<int>& height) {
		int length = height.size();
		int leftMH = 0, rightMH, tempA, maxA = 0;
		for (int i = 0; i < length; ++i) {
			if (height[i] > leftMH) {
				leftMH = height[i];
				rightMH = 0;
				for (int j = length - 1; j > i; --j) {
					if (height[j] > rightMH) {
						rightMH = height[j];
						if (leftMH < rightMH) {
							tempA = leftMH * (j - i);
							maxA = maxA > tempA ? maxA : tempA;
							break;
						} else {
							tempA = rightMH * (j - i);
							maxA = maxA > tempA ? maxA : tempA;
						}
					}
				}
			}
		}
		return maxA;
	}
};
int main(int argc, char** argv) {
	Solution solution;
	vector<int> height = { 1, 1 };
	// 	height.resize(10000);
	// 	for (int i = 0; i < 10000; ++i) {
	// 		height[i] = rand() & 0xff;
	// 	}
	cout << solution.maxArea(height) << endl;
	return 0;
}