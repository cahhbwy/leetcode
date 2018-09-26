#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int jump(vector<int> &nums) {
        int r = 0, n = static_cast<int>(nums.size()), c = 0, p = 0, pp;
        while (p < n - 1) {
            ++r;
            pp = p;
            while (c <= pp) {
                p = max(p, c + nums[c]);
                ++c;
            }
            if (p == pp) {
                return -1;
            }
        }
        return r;
    }
};

int main(int argc, char **argv) {
    Solution solution;
    vector<int> nums(25000);
    for (int i = 0; i < 25000; ++i) {
        nums[i] = 25000 - i;
    }
    nums.push_back(1);
    nums.push_back(0);
    cout << solution.jump(nums) << endl;
    return 0;
}