#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        unordered_map<string, unsigned long> sorted;
        vector<vector<string>> result;
        for (string str:strs) {
            string temp(str);
            sort(temp.begin(), temp.end());
            auto it = sorted.find(temp);
            if (it == sorted.end()) {
                sorted.insert({temp, sorted.size()});
                result.emplace_back(vector<string>());
            }
            result[sorted[temp]].emplace_back(str);
        }
        return result;
    }
};

int main(int argc, char **argv) {
    Solution solution;
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    auto result = solution.groupAnagrams(strs);
    for (auto r : result) {
        for (auto s:r) {
            cout << s << " ";
        }
        cout << endl;
    }
    return 0;
}