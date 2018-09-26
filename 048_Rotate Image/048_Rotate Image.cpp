#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>> &matrix) {
        unsigned long size = matrix.size();
        int t;
        for (unsigned long i = 0; i < (size + 1) / 2; ++i) {
            for (unsigned long j = 0; j < size / 2; ++j) {
                t = matrix[i][j];
                matrix[i][j] = matrix[size - 1 - j][i];
                matrix[size - 1 - j][i] = matrix[size - 1 - i][size - 1 - j];
                matrix[size - 1 - i][size - 1 - j] = matrix[j][size - 1 - i];
                matrix[j][size - 1 - i] = t;
            }
        }
    }
};

int main(int argc, char **argv) {
    Solution solution;
    vector<vector<int>> matrix = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
    };
    solution.rotate(matrix);
    for (auto r : matrix) {
        for (auto i:r) {
            cout << setw(2) << i;
        }
        cout << endl;
    }
    return 0;
}