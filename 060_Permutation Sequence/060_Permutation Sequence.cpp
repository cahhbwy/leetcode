#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        char result[n + 1];
        k = k - 1;
        vector<char> buf(n);
        for (int i = 0; i < n; ++i) {
            buf[i] = '0' + i + 1;
        }
        int p = 1;
        for (int i = 1; i <= n; ++i) {
            p *= i;
        }
        for (int i = 0; i < n; ++i) {
            p = p / (n - i);
            result[i] = buf[k / p];
            buf.erase(buf.begin() + k / p);
            k = k % p;
        }
        result[n] = 0;
        return string(result);
    }
};

int main(int argc, char **argv) {
    Solution solution;
    cout << solution.getPermutation(3, 3) << endl;
    cout << solution.getPermutation(4, 9) << endl;
    return 0;
}