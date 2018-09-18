#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int trap(vector<int> &height) {
        int count = 0;
        for (int i = 0; i < height.size(); ++i) {
            int j = i + 1;
            while (j < height.size() && height[j] < height[i]) {
                ++j;
            }
            if (j < height.size()) {
                for (int k = i + 1; k < j; ++k) {
                    count += height[i] - height[k];
                    height[k] = height[i];
                }
            }
            j = i - 1;
            while (j >= 0 && height[j] < height[i]) {
                --j;
            }
            if (j >= 0) {
                for (int k = i - 1; k > j; --k) {
                    count += height[i] - height[k];
                    height[k] = height[i];
                }
            }
        }
        return count;
    }
};

int main(int argc, char **argv) {
    Solution solution;
    vector<int> height({0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1});
    cout << solution.trap(height) << endl;
    return 0;
}