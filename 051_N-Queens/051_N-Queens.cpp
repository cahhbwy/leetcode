#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<int> pos(n, -1);
        findResult(n, pos, 0);
        return result;
    }

    void findResult(int n, vector<int> &pos, int l) {
        if (l >= n) {
            result.emplace_back(generateResult(n, pos));
        }
        for (int i = 0; i < n; ++i) {
            if (!conflict(n, pos, l, i)) {
                pos[l] = i;
                findResult(n, pos, l + 1);
            }
        }
    }

    bool conflict(int n, vector<int> pos, int l, int i) {
        for (int j = 0; j < l; ++j) {
            if (pos[j] == i || abs(pos[j] - i) == abs(j - l)) {
                return true;
            }
        }
        return false;
    }

    vector<string> generateResult(int n, vector<int> pos) {
        vector<string> r(n, string(n, '.'));
        for (int i = 0; i < n; ++i) {
            r[i][pos[i]] = 'Q';
        }
        return r;
    }

private:
    vector<vector<string>> result;
};

int main(int argc, char **argv) {
    Solution solution = Solution();
    auto result = solution.solveNQueens(5);
    for (auto r:result) {
        for (const auto &s:r) {
            cout << s << endl;
        }
        cout << endl;
    }
    return 0;
}