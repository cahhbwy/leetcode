#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        string result(num1.length() + num2.length(), '0');
        for (unsigned long j = 0; j < num2.length(); j += 9) {
            char *pEnd;
            unsigned long long y = strtoull(num2.substr(j, 9).c_str(), &pEnd, 10);
            for (unsigned long i = 0; i < num1.length(); i += 9) {
                unsigned long long x = strtoull(num1.substr(i, 9).c_str(), &pEnd, 10);
                unsigned long long z = x * y;
                string t = to_string(z);
                unsigned long p = i + j;
                unsigned long l = (i + 9 < num1.length() ? 9 : num1.length() - i) + (j + 9 < num2.length() ? 9 : num2.length() - j);
                int c = 0;
                int r;
                for (unsigned int k = 1; k <= l; ++k) {
                    if (k <= t.length()) {
                        r = (t[t.length() - k] - '0') + (result[p + l - k] - '0') + c;
                    } else {
                        r = (result[p + l - k] - '0') + c;
                    }
                    c = r / 10;
                    r = r % 10;
                    result[p + l - k] = static_cast<char>(r + '0');
                }
                while (c > 0) {
                    --p;
                    r = (result[p] - '0') + c;
                    c = r / 10;
                    r = r % 10;
                    result[p] = static_cast<char>(r + '0');
                }
            }
        }
        for (unsigned long i = 0; i < result.length(); ++i) {
            if (result[i] != '0') {
                return result.substr(i);
            }
        }
        return "0";
    }
};

int main(int argc, char **argv) {
    Solution solution;
    string num1 = "163574684342341654674346878674643";
    string num2 = "4653413436524134635464334687435346533";
    cout << solution.multiply(num1, num2) << endl;
    return 0;
}