#include <bits/stdc++.h>

using namespace std;

bool is_star(char a, char b) {
    return a == '*' && b == '*';
}

class Solution {
public:
    bool isMatch(string s, string p) {
        auto it = unique(p.begin(), p.end(), is_star);
        p.resize(static_cast<unsigned long>(distance(p.begin(), it)));
        unsigned long i = 0, j;
        while (i < p.length() && (p[i] == '*' || p[i] == '?')) {
            ++i;
        }
        j = i;
        while (j < p.length() && (p[j] != '*' && p[j] != '?')) {
            ++j;
        }
        string k = p.substr(i, j - i);
        if (s.empty()) {
            for (const char *c = p.c_str(); *c; ++c) {
                if (*c != '*') {
                    return false;
                }
            }
            return true;
        } else {
            if (p.empty()) {
                return false;
            } else {
                if (k.empty()) {
                    int count = 0;
                    bool has_star = false;
                    for (const char *c = p.c_str(); *c; ++c) {
                        if (*c == '?') {
                            ++count;
                        } else {
                            has_star = true;
                        }
                    }
                    return s.length() == count || (has_star && s.length() >= count);
                } else {
                    size_t pos = 0;
                    while (true) {
                        pos = s.find(k, pos);
                        if (pos == std::string::npos) {
                            break;
                        }
                        if (isMatch(s.substr(0, pos), p.substr(0, i)) && isMatch(s.substr(pos + k.length()), p.substr(j))) {
                            return true;
                        }
                        ++pos;
                    }
                    return false;
                }
            }
        }
    }
};

int main(int argc, char **argv) {
    Solution solution;
    string s = "abbabaaabbabbaababbabbbbbabbbabbbabaaaaababababbbabababaabbababaabbbbbbaaaabababbbaabbbbaabbbbababababbaabbaababaabbbababababbbbaaabbbbbabaaaabbababbbbaababaabbababbbbbababbbabaaaaaaaabbbbbaabaaababaaaabb";
    string p = "**aa*****ba*a*bb**aa*ab****a*aaaaaa***a*aaaa**bbabb*b*b**aaaaaaaaa*a********ba*bbb***a*ba*bb*bb**a*b*bb";
    cout << solution.isMatch(s, p) << endl;
    return 0;
}