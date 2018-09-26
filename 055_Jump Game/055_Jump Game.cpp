#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canJump(vector<int> &nums) {
        int r = 0, n = static_cast<int>(nums.size()), c = 0, p = 0, pp;
        while (p < n - 1) {
            ++r;
            pp = p;
            while (c <= pp) {
                p = max(p, c + nums[c]);
                ++c;
            }
            if (p == pp) {
                return false;
            }
        }
        return true;
    }
};

int main(int argc, char **argv) {
    Solution solution;
    vector<int> nums = {2, 3, 1, 1, 4};
    cout << solution.canJump(nums) << endl;
    nums = {3, 2, 1, 0, 4};
    cout << solution.canJump(nums) << endl;
    return 0;
}