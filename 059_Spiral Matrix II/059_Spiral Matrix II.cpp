#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

ostream &operator<<(ostream &out, vector<int> nums) {
    out << "[";
    for (int i = 0; i < nums.size(); ++i) {
        if (i < nums.size() - 1) {
            out << nums[i] << ", ";
        } else {
            out << nums[i];
        }
    }
    out << "]";
    return out;
}

ostream &operator<<(ostream &out, vector<vector<int>> mats) {
    if (!mats.empty()) {
        out << "[" << endl;
        for (int i = 0; i < mats.size(); ++i) {
            if (i < mats.size() - 1) {
                cout << "\t" << mats[i] << "," << endl;
            } else {
                cout << "\t" << mats[i] << endl;
            }
        }
        out << "]" << endl;
    } else {
        out << "[]" << endl;
    }
    return out;
}

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if (n <= 0) {
            return vector<vector<int>>();
        } else {
            vector<vector<int>> result(n, vector<int>(n));
            int i, j, k = 0;
            for (int l = 0; l < n / 2; ++l) {
                for (i = l, j = l; j < n - l - 1; ++j) {
                    result[i][j] = ++k;
                }
                for (i = l, j = n - l - 1; i < n - l - 1; ++i) {
                    result[i][j] = ++k;
                }
                for (i = n - l - 1, j = n - l - 1; j > l; --j) {
                    result[i][j] = ++k;
                }
                for (i = n - l - 1, j = l; i > l; --i) {
                    result[i][j] = ++k;
                }
            }
            if (n % 2) {
                result[n / 2][n / 2] = n * n;
            }
            return result;
        }
    }
};

int main(int argc, char **argv) {
    Solution solution;
    cout << solution.generateMatrix(0) << endl;
    cout << solution.generateMatrix(1) << endl;
    cout << solution.generateMatrix(2) << endl;
    cout << solution.generateMatrix(3) << endl;
    cout << solution.generateMatrix(4) << endl;
    return 0;
}