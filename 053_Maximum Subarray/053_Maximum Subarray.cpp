#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        bool hasPos = false;
        int sum = 0;
        int min_v = 0, max_nag = INT32_MIN, max_delta = nums[0];
        for (int i:nums) {
            if (i > 0) {
                hasPos = true;
            } else {
                max_nag = max(max_nag, i);
            }
            sum += i;
            if (sum < min_v) {
                min_v = sum;
            }
            max_delta = max(max_delta, sum - min_v);
        }
        if (hasPos) {
            return max_delta;
        } else {
            return max_nag;
        }
    }
};

int main(int argc, char **argv) {
    Solution solution;
    vector<int> nums = {0, -3, 1, 1};
    cout << solution.maxSubArray(nums) << endl;
    return 0;
}