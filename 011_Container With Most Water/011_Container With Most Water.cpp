#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	int maxArea(vector<int>& height) {
		int length = height.size();
		int maxAreaResult = 0, areaTemp;
		for (int i = 0; i < length; ++i) {
			for (int j = i; j < length; ++j) {
				areaTemp = (j - i)*(height[i] < height[j] ? height[i] : height[j]);
				maxAreaResult = maxAreaResult > areaTemp ? maxAreaResult : areaTemp;
			}
		}
		return maxAreaResult;
	}
};
int main(int argc, char** argv) {
	Solution solution;
	vector<int> height;
	height.resize(10000);
	for (int i = 0; i < 10000; ++i) {
		height[i] = rand() & 0xff;
	}
	cout << solution.maxArea(height) << endl;
	return 0;
}