#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        temp.clear();
        result.clear();
        can_combinationSum(candidates, 0, target);
        return result;
    }

private:
    vector<int> temp;
    vector<vector<int>> result;

    void can_combinationSum(vector<int> &candidates, int index, int target) {
        if (target == 0) {
            result.push_back(temp);
        } else if (target > 0) {
            for (int i = index; i < candidates.size() && candidates[i] <= target; ++i) {
                if (i > index && candidates[i] == candidates[i - 1]) {
                    continue;
                }
                temp.push_back(candidates[i]);
                can_combinationSum(candidates, i + 1, target - candidates[i]);
                temp.pop_back();
            }
        }
    }
};

int main() {
    Solution solution;
    vector<int> candidates = {5, 4, 5, 1, 5, 3, 1, 4, 5, 5, 4};
    int target = 10;
    vector<vector<int>> result = solution.combinationSum2(candidates, target);
    for (auto v: result) {
        cout << "[";
        for (auto i:v) {
            cout << setw(2) << i << ",";
        }
        cout << "\b]" << endl;
    }
    return 0;
}