#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.empty())	return "";
		string maxStr = strs.front(), minStr = strs.front();
		for (string s : strs) {
			maxStr = maxStr > s ? maxStr : s;
			minStr = minStr < s ? minStr : s;
		}
		const char *c1 = maxStr.c_str(), *c2 = minStr.c_str();
		while (*c1 == *c2&&*c1 != 0) {
			++c1;
			++c2;
		}
		return maxStr.substr(0, c1 - maxStr.c_str());
	}
};
int main(int argc, char** argv) {
	Solution solution;
	vector<string> strs = {};
	cout << solution.longestCommonPrefix(strs) << endl;
	return 0;
}