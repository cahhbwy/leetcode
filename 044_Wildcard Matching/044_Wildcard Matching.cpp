#include <bits/stdc++.h>

using namespace std;

bool get_key(string p, unsigned long &l, unsigned long &r) {
    l = r;
    while (l < p.length() && (p[l] == '*' || p[l] == '?')) ++l;
    r = l;
    while (r < p.length() && (p[r] != '*' && p[r] != '?')) ++r;
    return l < r;
}

class Solution {
public:
    bool isMatch(string s, string p) {
        cout << "s : " << s << endl << "p : " << p << endl << endl;
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
                unsigned long l = 0, r = 0;
                get_key(p, l, r);
                string k = p.substr(l, r - l);
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
                    vector<int> pos_list;
                    while (true) {
                        pos = s.find(k, pos);
                        if (pos == string::npos) {
                            break;
                        }
                        unsigned long tl = l, tr = r, tpos = pos + 1;
                        int pos_list_index = 0;
                        while (get_key(p, tl, tr)) {
                            tpos = s.find(p.substr(tl, tr - tl), tpos);
                            if (tpos == string::npos) {
                                return false;
                            }
                            if (pos_list_index >= pos_list.size()) {
                                pos_list.push_back(tpos);
                            } else {
                                pos_list[pos_list_index] = tpos;
                                if (pos_list_index < pos_list.size() - 1) {
                                    if (pos_list[pos_list_index + 1] > tpos) {
                                        break;
                                    }
                                }
                            }
                            if (tr == p.length()) {
                                tpos = s.rfind(p.substr(tl, tr - tl));
                                if (tpos + tr - tl < s.length()) {
                                    return false;
                                }
                            }
                            ++tpos;
                        }
                        if (isMatch(s.substr(0, pos), p.substr(0, l)) && isMatch(s.substr(pos + k.length()), p.substr(r))) {
                            return true;
                        }
                        ++pos;
                    };
                    return false;
                }
            }
        }
    }
};

int main(int argc, char **argv) {
    Solution solution;
    string s = "aaaabaabaabbbabaabaabbbbaabaaabaaabbabbbaaabbbbbbabababbaabbabbbbaababaaabbbababbbaabbbaabbaaabbbaabbbbbaaaabaaabaabbabbbaabababbaabbbabababbaabaaababbbbbabaababbbabbabaaaaaababbbbaabbbbaaababbbbaabbbbb";
    string p = "**a*b*b**b*b****bb******b***babaab*ba*a*aaa***baa****b***bbbb*bbaa*a***a*a*****a*b*a*a**ba***aa*a**a*";
    cout << solution.isMatch(s, p) << endl;
    return 0;
}