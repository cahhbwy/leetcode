#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if (x == 0.0) {
            return 0.0;
        }
        if (n < 0) {
            x = 1.0 / x;
        }
        double b = x, r = 1.0;
        while (n != 0) {
            if (n % 2) {
                r *= b;
            }
            b = b * b;
            n /= 2;
        }
        return r;
    }
};

int main(int argc, char **argv) {
    Solution solution;
    cout << solution.myPow(2.0, -2147483648) << endl;
    return 0;
}