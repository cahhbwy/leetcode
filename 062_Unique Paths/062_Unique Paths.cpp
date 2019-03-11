#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m <= 0 || n <= 0) {
            return 0;
        }
        int result = 1;
        --m;
        --n;
        int k = m + n, g;
        if (m < n) {
            m = n;
            n = k - m;
        }
        vector<int> numerator(n, 1), denominator(n, 1);
        for (int i = 0; i < n; ++i) {
            numerator[i] = m + 1 + i;
            denominator[i] = 1 + i;
        }
        for (int i = n - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                g = gcd(numerator[j], denominator[i]);
                numerator[j] /= g;
                denominator[i] /= g;
                if (denominator[i] == 1) {
                    break;
                }
            }
        }
        for (int i:numerator) {
            result *= i;
        }
        return result;
    }
};

int main(int argc, char **argv) {
    Solution solution;
    cout << solution.uniquePaths(3, 2) << endl;
    cout << solution.uniquePaths(7, 3) << endl;
    cout << solution.uniquePaths(0, 0) << endl;
    cout << solution.uniquePaths(1, 0) << endl;
    cout << solution.uniquePaths(1, 1) << endl;
    cout << solution.uniquePaths(2, 1) << endl;
    return 0;
}
