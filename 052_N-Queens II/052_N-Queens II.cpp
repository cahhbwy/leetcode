#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int totalNQueens(int n) {
        result = 0;
        vector<int> pos(n, -1);
        findResult(n, pos, 0);
        return result;
    }

    void findResult(int n, vector<int> &pos, int l) {
        if (l >= n) {
            ++result;
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

private:
    int result;
};

int main(int argc, char **argv) {
    Solution solution;
    cout << solution.totalNQueens(8) << endl;
    return 0;
}