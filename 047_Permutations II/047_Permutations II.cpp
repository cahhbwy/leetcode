#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        return permute(nums);
    }

    vector<vector<int>> permute(vector<int> &nums) {
        if (nums.size() == 1) {
            return vector<vector<int>>(1, nums);
        } else {
            vector<vector<int>> result;
            for (int i = 0; i < nums.size(); ++i) {
                if (i > 0 && nums[i] == nums[i - 1]) {
                    continue;
                }
                auto temp = vector<int>(nums);
                temp.erase(temp.begin() + i);
                for (const auto &r:permute(temp)) {
                    result.push_back(r);
                    result.back().push_back(nums[i]);
                }
            }
            return result;
        }
    }
};

int main(int argc, char **argv) {
    Solution solution;
    vector<int> nums = {1, 2, 1};
    auto result = solution.permuteUnique(nums);
    for (auto r : result) {
        for (auto i:r) {
            cout << setw(2) << i;
        }
        cout << endl;
    }
    return 0;
}