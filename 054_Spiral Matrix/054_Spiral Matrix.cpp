#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        if (matrix.empty()) {
            return vector<int>();
        }
        vector<int> result;
        unsigned long m = matrix.size(), n = matrix[0].size();
        unsigned long step = min(m + 1, n + 1) / 2;
        for (int k = 0; k < step; ++k) {
            int i = k, j = k;
            while (j < n - k) {
                result.push_back(matrix[i][j]);
                ++j;
            }
            --j;
            ++i;
            while (i < m - k) {
                result.push_back(matrix[i][j]);
                ++i;
            }
            --i;
            --j;
            if (m % 2 && m < n && k == step - 1) {
                break;
            }
            while (j >= k) {
                result.push_back(matrix[i][j]);
                --j;
            }
            ++j;
            --i;
            if (n % 2 && m > n && k == step - 1) {
                break;
            }
            while (i > k) {
                result.push_back(matrix[i][j]);
                --i;
            }
        }
        return result;
    }
};

int main(int argc, char **argv) {
    Solution solution;
    vector<vector<int>> matrix = {
            {1, 2,  3,  4},
            {5, 6,  7,  8},
            {9, 10, 11, 12}
    };
    auto result = solution.spiralOrder(matrix);
    for (auto i:result) {
        cout << " " << i;
    }
    cout << endl;
    return 0;
}