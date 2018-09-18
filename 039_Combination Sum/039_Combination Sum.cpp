#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
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
                temp.push_back(candidates[i]);
                can_combinationSum(candidates, i, target - candidates[i]);
                temp.pop_back();
            }
        }
    }
};

int main() {
    Solution solution;
    vector<int> candidates = {2, 3, 5};
    int target = 8;
    vector<vector<int>> result = solution.combinationSum(candidates, target);
    for (auto v: result) {
        cout << "[";
        for (auto i:v) {
            cout << setw(2) << i << ",";
        }
        cout << "\b]" << endl;
    }
    return 0;
}