#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
        unsigned long m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<int> curr(n, 1), prev(n, 0), tmp;
        for (unsigned long j = 1; j < n; ++j) {
            if (obstacleGrid[0][j - 1] == 1) {
                curr[j] = 0;
            } else {
                curr[j] = 1;
            }
        }
        for(unsigned long i = 1; i < m; ++i){

        }
    }
};

int main(int argc, char **argv) {
    Solution solution;
    vector<vector<int>> obstacleGrid = {
            {0, 0, 0},
            {0, 1, 0},
            {0, 0, 0}
    };
    cout << solution.uniquePathsWithObstacles(obstacleGrid) << endl;
    return 0;
}
